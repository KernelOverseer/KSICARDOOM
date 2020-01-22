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
			body->player->input_velocity.z = 0;
		}
    }


	
	t_intersect inter;
	t_vec3 future_pos;
	t_vec2 stopping_pos;

	inter.distance = INFINITY;
	inter.min_dist = 0;
	inter.ray.origin = (t_vec2){body->pos.x, body->pos.y};
	inter.ray.dir = ft_vec2_normalize((t_vec2){body->velocity.x, body->velocity.y});
	ft_intersect_ray(scene, &inter, scene->current_sector);
	// printf("body forw %f %f | body pos %f %f | raydir (%f, %f) | intersected at: %f, %f, type: %d\n", body->forw.x, body->forw.y,body->pos.x, body->pos.y, inter.ray.dir.x, inter.ray.dir.y, inter.pos.x, inter.pos.y, inter.object.type);
	if (inter.object.type == OBJECT_wall)
	{
		future_pos = ft_vec3_add(body->pos, body->velocity);
		stopping_pos = ft_vec2_normalize(ft_vec2_sub(inter.pos, inter.ray.origin));
		stopping_pos = ft_vec2_add(inter.pos, ft_vec2_scalar(stopping_pos, 0.5));
		// printf("future_pos %f %f | current pos %f %f | intersected at: %f, %f | velocity at: %f, %f | DISTANCE %f\n", future_pos.x, future_pos.y, body->pos.x, body->pos.y, inter.pos.x, inter.pos.y, body->velocity.x, body->velocity.y, inter.distance);
		if (ft_vec2_mag(ft_vec2_sub((t_vec2){future_pos.x, future_pos.y}, stopping_pos)) < 50)
		{
			body->player->input_velocity.x = body->player->input_velocity.x * -body->bounce;
			body->player->input_velocity.y = body->player->input_velocity.y * -body->bounce;
			body->velocity.x = body->velocity.x * -body->bounce;
			body->velocity.y = body->velocity.y * -body->bounce;
		}
		// if (future_pos.x <= inter.pos.x + MICRO)
		// {
		// 	body->velocity.x = 0;
		// 	body->pos.x = inter.pos.x + MICRO;
		// }
	}
}

/*
** enum	e_object_type
** {
** 	OBJECT_wall = 1, OBJECT_portal, OBJECT_sprite
** };
*/
