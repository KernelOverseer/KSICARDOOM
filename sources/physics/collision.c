/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:25:49 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/24 13:51:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"
#define INTER_DISTANCE 10
#define INTERSECTION_MARGIN 10

int		ft_set_new_intersection_slide_velocity(t_body *body, t_intersect inter, double delta_time)
{
	t_vec2 new_position_vector;
	t_vec2 wall_push_vector;
	t_vec2 orthogonal_projection;
	double orthogonal_dot;
	t_vec2 normalized_wall;
	double new_velocity_scalar;
	t_vec2	new_velocity;
	double distance_to_corner;

	t_wall *virtual_wall;

	if (inter.object.type == OBJECT_wall)
		virtual_wall = inter.object.object.wall;
	else if (inter.object.type == OBJECT_portal)
		virtual_wall = &inter.object.object.portal->wall;
	else
		return (0);
	if (virtual_wall->props & PROP_NO_CLIP)
		return (0);
	normalized_wall = ft_vec2_normalize((t_vec2){virtual_wall->p2.x - virtual_wall->p1.x, virtual_wall->p2.y - virtual_wall->p1.y});
	orthogonal_dot = ft_vec2_dot_product((t_vec2){body->pos.x - virtual_wall->p1.x, body->pos.y - virtual_wall->p1.y}, normalized_wall);
	orthogonal_projection = ft_vec2_scalar(normalized_wall, orthogonal_dot);
	orthogonal_projection = (t_vec2){virtual_wall->p1.x + orthogonal_projection.x, virtual_wall->p1.y + orthogonal_projection.y};
	wall_push_vector = ft_vec2_scalar(ft_vec2_normalize((t_vec2){body->pos.x - orthogonal_projection.x, body->pos.y - orthogonal_projection.y}), INTERSECTION_MARGIN);
	new_velocity_scalar = ft_vec2_dot_product((t_vec2){body->velocity.x, body->velocity.y}, normalized_wall);
	new_velocity = ft_vec2_scalar(normalized_wall, new_velocity_scalar);
	body->velocity = (t_vec3){new_velocity.x, new_velocity.y, body->velocity.z};
	distance_to_corner = ft_max(ft_vec2_mag((t_vec2){virtual_wall->p1.x - inter.pos.x, virtual_wall->p1.y - inter.pos.y}),
		ft_vec2_mag((t_vec2){virtual_wall->p2.x - inter.pos.x, virtual_wall->p2.y - inter.pos.y}));
	if (distance_to_corner < INTERSECTION_MARGIN)
	{
		body->velocity.x = 0;
		body->velocity.y = 0;
	}
	return (1);
}

void	ft_apply_intersection_event(t_body *body, t_intersect inter)
{
	if (body->events.on_intersect)
		body->events.on_intersect(body, inter);
}

int		ft_floor_ceiling_intersections(t_vec3 next_position, t_body *body)
{
	// Floor and Ceiling intersection check
	// Floor intersection
	if (next_position.z <= body->player->sector->floor_height)
	{
		body->player->input_velocity.x *= body->friction;
		body->player->input_velocity.y *= body->friction;
		body->player->is_grounded = true;
		body->player->input_velocity.z = 0;
		body->velocity.z = 0;
		body->gravity = ZERO_VEC3;
		body->pos.z = body->player->sector->floor_height;
		return (1);
	}
	// Ceiling intersection
	if (next_position.z + body->player->height[1] >= DEFAULT_WALL_HEIGHT + body->player->sector->ceil_height)
	{
		body->player->input_velocity.z = 0;
		body->velocity.z = 0;
		body->pos.z = DEFAULT_WALL_HEIGHT + body->player->sector->ceil_height - body->player->height[1];
		return (1);
	}
	return (0);
}

int		ft_portal_intersections(t_intersect inter, t_body *body, double delta_time)
{
	// intersection with portal top
	double head_altitude;
	double bottom_altitude;
	double portal_top_altitude = ft_max(body->player->sector->ceil_height, inter.object.object.portal->sector->ceil_height) + DEFAULT_WALL_HEIGHT;
	double portal_bottom_altitude = ft_min(body->player->sector->floor_height, inter.object.object.portal->sector->floor_height);

	head_altitude = body->pos.z + body->player->height[1];
	bottom_altitude = body->pos.z;
	if (head_altitude > portal_top_altitude)
		return (ft_set_new_intersection_slide_velocity(body, inter, delta_time));
	else if (bottom_altitude < portal_bottom_altitude)
		return (ft_set_new_intersection_slide_velocity(body, inter, delta_time));
	else
		body->player->sector = inter.object.object.portal->sector;
	return (0);
}
int		ft_sprite_intersections(t_intersect inter, t_body *body, double delta_time)
{
	double head_altitude;
	double bottom_altitude;

	if (inter.object.object.sprite->props & PROP_NO_CLIP)
		return (0);
	head_altitude = body->pos.z + body->player->height[1];
	bottom_altitude = body->pos.z;
	if (head_altitude < inter.object.object.sprite->altitude ||
		bottom_altitude > inter.object.object.sprite->altitude
		+ inter.object.object.sprite->height)
		return (0);
	body->velocity.x = 0;
	body->velocity.y = 0;
	return (1);
}

void ft_body_collision(t_graphical_scene *scene, t_body *body, double delta_time)
{
	t_vec3 next_position;

	next_position = (t_vec3){body->pos.x + body->velocity.x * delta_time,
							 body->pos.y + body->velocity.y * delta_time,
							 body->pos.z + body->velocity.z * delta_time};
	t_intersect inter;
	t_vec3 future_pos;
	t_vec3 stopping_pos;

	ft_floor_ceiling_intersections(next_position, body);

	inter.distance = INFINITY;
	inter.min_dist = 0;
	inter.ray.origin = (t_vec2){body->pos.x, body->pos.y};
	inter.ray.dir = ft_vec2_normalize((t_vec2){body->velocity.x, body->velocity.y});
	ft_intersect_ray(scene, &inter, body->player->sector);
	while (inter.object.type)
	{
		double distance_to_next_position = ft_vec2_mag((t_vec2){next_position.x - body->pos.x, next_position.y - body->pos.y});
		double distance_to_intersection = ft_vec2_mag((t_vec2){inter.pos.x - body->pos.x, inter.pos.y - body->pos.y});
		if (inter.object.type)
		{
			if (inter.object.type == OBJECT_portal)
			{	
				if (distance_to_intersection <= distance_to_next_position)
				{
					if (ft_portal_intersections(inter, body, delta_time))
						ft_apply_intersection_event(body, inter);
				}
			}
			else if (inter.object.type == OBJECT_wall)
			{
				// Normal wall intersection behaviour
				if (distance_to_intersection <= distance_to_next_position + body->player->height[0] / 2)
				{
					ft_apply_intersection_event(body, inter);
					ft_set_new_intersection_slide_velocity(body, inter, delta_time);
				}
			}
			else if (inter.object.type == OBJECT_sprite)
			{
				double sprite_radius;

				if (inter.object.object.sprite->props & PROP_FIXED_ANGLE)
					sprite_radius = 0;
				else
					sprite_radius = inter.object.object.sprite->radius;
				if (distance_to_intersection <= distance_to_next_position + body->player->height[0] / 2 + sprite_radius)
				{
					if (ft_sprite_intersections(inter, body, delta_time))
						ft_apply_intersection_event(body, inter);
				}
			}
		}
		inter.min_dist = distance_to_intersection;
		ft_intersect_ray(scene, &inter, body->player->sector);
	}
}
