/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:26:02 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/04 16:26:03 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void    ft_velocity_add()
{
    t_vec3 v = (t_vec3){0, 1, 3};
    printf("ft_velocity_add (%f, %f, %f)\n", v.x, v.y, v.z);
}