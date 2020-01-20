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

void        ft_body_collision(t_body *body, double delta_time)
{
    if (((body->velocity.z + body->pos.z) * delta_time * 20) <= 0) // change 0's depending on ground height
    {
		// printf("------\ncollision %f %f %f\n", body->velocity.x, body->velocity.y, body->friction);
        // body->velocity.x = body->velocity.x * body->friction;
        // body->velocity.y = body->velocity.y * body->friction;
		// printf("collision %f %f\n", body->velocity.x, body->velocity.y);
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
}
