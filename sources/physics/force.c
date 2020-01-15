/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:26:02 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/04 16:26:03 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"

void    ft_force_add(t_body *body, t_vec3 force, double duration)
{
    if (duration <= 0)
		body->force = (t_vec3){0, 0, 0};
	else
	{
		body->force = force;
		body->force_duration = duration;
	}
}

void    ft_force_change(t_body *body, t_vec3 force, double duration)
{
    if (duration <= 0)
		body->force = (t_vec3){0, 0, 0};
	else
	{
		body->force = ft_vec3_add(body->force, force);
		body->force_duration += duration;
	}
}

void    ft_update_force(t_body *body, double delta_time)
{
	delta_time = delta_time * 20;
    if (body->force_duration > 0)
	{
        body->velocity = ft_vec3_add(body->velocity,
				ft_vec3_scalar(body->force, delta_time));
		body->force_duration -= delta_time;
	}
}
