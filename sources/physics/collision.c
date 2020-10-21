/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:25:49 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/20 14:42:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"
#define INTER_DISTANCE 10
#define INTERSECTION_MARGIN 50

void        ft_body_collision(t_graphical_scene *scene, t_body *body, double delta_time)
{
	t_vec3	next_position;

	next_position = (t_vec3){body->pos.x + body->velocity.x * delta_time,
							 body->pos.y + body->velocity.y * delta_time,
							 body->pos.z + body->velocity.z * delta_time};
	// Floor and Ceiling intersection check
	// Floor intersection
	if (next_position.z <= scene->current_sector->floor_height)
	{
		body->player->input_velocity.x *= body->friction;
		body->player->input_velocity.y *= body->friction;
		body->player->is_grounded = true;
		body->player->input_velocity.z = 0;
		body->velocity.z = 0;
		body->gravity = ZERO_VEC3;
		body->pos.z = scene->current_sector->floor_height;
	}
	// Ceiling intersection
	if (next_position.z + body->player->height[1] >= DEFAULT_WALL_HEIGHT + scene->current_sector->ceil_height)
	{
		body->player->input_velocity.z = 0;
		body->velocity.z = 0;
		body->pos.z = DEFAULT_WALL_HEIGHT + scene->current_sector->ceil_height - body->player->height[1];
	}	


	t_intersect inter;
	t_vec3 future_pos;
	t_vec3 stopping_pos;

	inter.distance = INFINITY;
	inter.min_dist = 0;
	inter.ray.origin = (t_vec2){body->pos.x, body->pos.y};
	inter.ray.dir = ft_vec2_normalize((t_vec2){body->velocity.x, body->velocity.y});
	ft_intersect_ray(scene, &inter, scene->current_sector);
	while (inter.object.type)
	{
		double distance_to_next_position = ft_vec2_mag((t_vec2){next_position.x - body->pos.x, next_position.y - body->pos.y});
		double distance_to_intersection = ft_vec2_mag((t_vec2){inter.pos.x - body->pos.x, inter.pos.y - body->pos.y});
		if (inter.object.type)
		{
			if (inter.object.type == OBJECT_portal)
			{
				//scene->current_sector = inter.object.object.portal->sector;
			}
			else
			{
				if (distance_to_intersection <= distance_to_next_position + INTERSECTION_MARGIN)
				{
					t_vec2 new_position_vector;
					t_vec2 wall_push_vector;
					t_vec2 orthogonal_projection;
					double orthogonal_dot;


					t_vec2 normalized_wall = ft_vec2_normalize((t_vec2){inter.object.object.wall->p2.x - inter.object.object.wall->p1.x, inter.object.object.wall->p2.y - inter.object.object.wall->p1.y});
					orthogonal_dot = ft_vec2_dot_product((t_vec2){body->pos.x - inter.object.object.wall->p1.x, body->pos.y - inter.object.object.wall->p1.y}, normalized_wall);
					orthogonal_projection = ft_vec2_scalar(normalized_wall, orthogonal_dot);
					orthogonal_projection = (t_vec2){inter.object.object.wall->p1.x + orthogonal_projection.x, inter.object.object.wall->p1.y + orthogonal_projection.y};
					wall_push_vector = ft_vec2_scalar(ft_vec2_normalize((t_vec2){body->pos.x - orthogonal_projection.x, body->pos.y - orthogonal_projection.y}), INTERSECTION_MARGIN);
					body->pos.x = inter.pos.x + wall_push_vector.x;
					body->pos.y = inter.pos.y + wall_push_vector.y;	
					double new_velocity_scalar = ft_vec2_dot_product((t_vec2){body->velocity.x, body->velocity.y}, normalized_wall);
					t_vec2 new_velocity = ft_vec2_scalar(normalized_wall, new_velocity_scalar);	
					body->velocity = (t_vec3){new_velocity.x, new_velocity.y, body->velocity.z};
				}
				

				/*t_vec3 vec_to_inter = ft_vec3_sub((t_vec3){inter.pos.x, inter.pos.y, 0}, (t_vec3){inter.ray.origin.x, inter.ray.origin.y, 0});
				t_vec3 inter_to_p1 = ft_vec3_sub((t_vec3){inter.pos.x, inter.pos.y, 0}, (t_vec3){inter.object.object.wall->p1.x, inter.object.object.wall->p1.y, 0});

				t_vec3 cross = ft_vec3_cross_product(vec_to_inter, inter_to_p1);
				t_vec3 normal = ft_vec3_normalize(ft_vec3_cross_product(cross, inter_to_p1));
				future_pos = ft_vec3_add((t_vec3){body->pos.x, body->pos.y, 0}, (t_vec3){body->velocity.x, body->velocity.y, 0});
				stopping_pos = ft_vec3_add((t_vec3){inter.pos.x, inter.pos.y, 0}, normal);

				// printf("future_pos %-14f %-14f | current pos %-14f %-14f | intersected at: %-14f, %-14f | velocity at: %-14f, %-14f | DISTANCE %-14f | normal %-14f %-14f %-14f\n", future_pos.x, future_pos.y, body->pos.x, body->pos.y, inter.pos.x, inter.pos.y, body->velocity.x, body->velocity.y, inter.distance, normal.x, normal.y, normal.z);

				t_vec3 vec_perpendicular_towards_inter = ft_vec3_scalar(normal, ft_vec3_dot_product(ft_vec3_sub(future_pos, stopping_pos), normal));
				if (ft_vec3_mag(vec_perpendicular_towards_inter) < INTER_DISTANCE)
				{
					// body->pos = stopping_pos;
					if (body->bounce) // reflect velocity
					{
						t_vec3 reflected_vec;
						reflected_vec = ft_vec3_add(ft_vec3_scalar(normal, -2 * ft_vec3_dot_product(body->velocity, normal)), body->velocity);
						body->velocity.x = reflected_vec.x * body->bounce;
						body->velocity.y = reflected_vec.y * body->bounce;
						if (body->flags & IS_CONTROLLED)
						{
							reflected_vec = ft_vec3_add(ft_vec3_scalar(normal, -2 * ft_vec3_dot_product(body->player->input_velocity, normal)), body->player->input_velocity);
							body->player->input_velocity.x = reflected_vec.x * body->bounce;
							body->player->input_velocity.y = reflected_vec.y * body->bounce;
						}
					}
					else // redirect velocity
					{
						t_vec3 newdir = ft_vec3_normalize(inter_to_p1);
						double dot = ft_vec3_dot_product(newdir, body->velocity);
						newdir = ft_vec3_scalar(newdir, dot);
						body->velocity.x = newdir.x;
						body->velocity.y = newdir.y;
						if (body->flags & IS_CONTROLLED)
						{
							body->player->input_velocity.x = newdir.x;
							body->player->input_velocity.y = newdir.y;
						}
					}
				}*/
			}
		}
		inter.min_dist = distance_to_intersection;
		ft_intersect_ray(scene, &inter, scene->current_sector);
	}
}
