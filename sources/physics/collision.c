/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:25:49 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/04 16:26:10 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"

void        ft_body_collision(t_graphical_scene *scene, t_body *body, double delta_time)
{
	//ground collision
    if (((body->velocity.z + body->pos.z) * delta_time * 20) <= 0) // change 0's depending on ground height
    {
        // body->velocity.x = body->velocity.x * body->friction;
        // body->velocity.y = body->velocity.y * body->friction;
        body->velocity.z = 0;
        body->pos.z = 0;
        body->gravity = ZERO_VEC3;
		if (body->flags & IS_CONTROLLED)
		{
        	body->player->input_velocity.x = body->player->input_velocity.x * body->friction;
        	body->player->input_velocity.y = body->player->input_velocity.y * body->friction;
			body->player->is_grounded = true;
			body->player->input_velocity.z *= 0;
		}
    }



	t_intersect inter;
	t_vec3 future_pos;
	t_vec3 stopping_pos;

	inter.distance = INFINITY;
	inter.min_dist = 0;
	inter.ray.origin = (t_vec2){body->pos.x, body->pos.y};
	inter.ray.dir = ft_vec2_normalize((t_vec2){body->velocity.x, body->velocity.y});
	ft_intersect_ray(scene, &inter, scene->current_sector);
	// printf("body forw %-14f %-14f | body pos %-14f %-14f | raydir (%-14f, %-14f) | intersected at: %-14f, %-14f, type: %d\n", body->forw.x, body->forw.y,body->pos.x, body->pos.y, inter.ray.dir.x, inter.ray.dir.y, inter.pos.x, inter.pos.y, inter.object.type);
	if (inter.object.type==1)
	{
		t_vec3 vec_to_inter = ft_vec3_sub((t_vec3){inter.pos.x, inter.pos.y, 0}, (t_vec3){inter.ray.origin.x, inter.ray.origin.y, 0});
		t_vec3 inter_to_p1 = ft_vec3_sub((t_vec3){inter.pos.x, inter.pos.y, 0}, (t_vec3){inter.object.object.wall->p1.x, inter.object.object.wall->p1.y, 0});

		t_vec3 cross = ft_vec3_cross_product(vec_to_inter, inter_to_p1);
		t_vec3 normal = ft_vec3_normalize(ft_vec3_cross_product(cross, inter_to_p1));
		future_pos = ft_vec3_add((t_vec3){body->pos.x, body->pos.y, 0}, (t_vec3){body->velocity.x, body->velocity.y, 0});
		stopping_pos = ft_vec3_add((t_vec3){inter.pos.x, inter.pos.y, 0}, normal);
		// printf("future_pos %-14f %-14f | current pos %-14f %-14f | intersected at: %-14f, %-14f | velocity at: %-14f, %-14f | DISTANCE %-14f | normal %-14f %-14f %-14f\n", future_pos.x, future_pos.y, body->pos.x, body->pos.y, inter.pos.x, inter.pos.y, body->velocity.x, body->velocity.y, inter.distance, normal.x, normal.y, normal.z);
		// t_vec3 print = ft_vec3_scalar(normal, ft_vec3_dot_product(normal, ft_vec3_sub(future_pos, stopping_pos)));

		if (ft_vec3_mag(ft_vec3_sub(future_pos, stopping_pos)) < 50)
		{
			// printf("%14f %14f %14f || %14f + %14f, %14f + %14f, %14f + %14f \n", newdir.x, newdir.y, newdir.z, body->velocity.x, body->player->input_velocity.x, body->velocity.y, body->player->input_velocity.y, body->velocity.z, body->player->input_velocity.z);
			if (!body->bounce)
			{
				t_vec3 newdir = ft_vec3_normalize(inter_to_p1);
				double dot = ft_vec3_dot_product(newdir, body->velocity);
				newdir = ft_vec3_scalar(newdir, dot);
				body->velocity.x = newdir.x;
				body->velocity.y = newdir.y;
			}
			else
			{
				t_vec3 reflected_vec;
				reflected_vec = ft_vec3_add(ft_vec3_scalar(normal, -2 * ft_vec3_dot_product(body->velocity, normal)), body->velocity);
				body->velocity.x = reflected_vec.x * body->bounce;
				body->velocity.y = reflected_vec.y * body->bounce;
				reflected_vec = ft_vec3_add(ft_vec3_scalar(normal, -2 * ft_vec3_dot_product(body->player->input_velocity, normal)), body->player->input_velocity);
				body->player->input_velocity.x = reflected_vec.x * body->bounce;
				body->player->input_velocity.y = reflected_vec.y * body->bounce;
			}
			
		}
	}
}

/*
** enum	e_object_type
** {
** 	OBJECT_wall = 1, OBJECT_portal, OBJECT_sprite
** };
*/
