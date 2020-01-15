/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:22:19 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/08 11:22:20 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"

void    ft_init_physics(t_physics_engine *phi)
{
    phi->global_gravity = GLOBAL_GRAVITY;
    phi->gravity_vec = GLOBAL_GRAVITY_VECTOR;
}