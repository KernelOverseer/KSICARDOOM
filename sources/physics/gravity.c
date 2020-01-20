/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:25:57 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/04 16:26:12 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"

void        ft_update_gravity(t_body *body, t_vec3 global_gravity, double delta_time)
{
    body->gravity = ft_vec3_add(body->gravity, ft_vec3_scalar(global_gravity, (delta_time * 10) * body->drag));
}
