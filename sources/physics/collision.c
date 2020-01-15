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
        body->velocity.z = 0;
        body->pos.z = 0;
        body->gravity = ZERO_VEC3;
    }
}
