/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:39:09 by msidqi            #+#    #+#             */
/*   Updated: 2019/05/11 18:39:12 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

double	ft_vec2_mag(t_vec2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

double	ft_vec3_mag(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

double	ft_vec2_mag_cmp(t_vec2 a, t_vec2 b)
{
	return ((a.x * a.x + a.y * a.y) - (b.x * b.x + b.y * b.y));
}

/*
** y_axis (-0.75, 0.66) (1, 0)
*/

t_vec2	ft_vec2_rotate_byangle(t_vec2 a, double angle)
{
	t_vec2	ret;

	ret.x = a.x * cos(angle) - a.y * sin(angle);
	ret.y = a.x * sin(angle) + a.y * cos(angle);
	return (ret);
}

/*
** To avoid cos && sin 's computational cost.
**
** Rotate the x-axis (1,0) and y-axis (0,1) using vec2_rotate_cosin()
** x_axis = vec2_rotate_cosin((1,0), 49 degrees)
** y_axis = vec2_rotate_cosin((0,1), 49 degrees)
** then use the following function on all
** the object's points(passing the rotated axises as param).
** instead of applying vec2_rotate_cosin() on each point.
**
** formula x(a,b) + y(c,d)
** x and y are the original point's position,
** (a,b)(c,d) are the rotated axis.
** vec2_add(vec2_scalar_multi(x_axis, a.x), vec2_scalar_multi(y_axis, a.y))
**
** exmpl: x_axis (0.66,0.75) y_axis (-0.75, 0.66)
** 0*(0.66,0.75) + 2*(-0.75, 0.66) = (-1.5, 1.3)
*/

t_vec2	ft_vec2_rotate_byaxis(t_vec2 a, t_vec2 x_axis, t_vec2 y_axis)
{
	x_axis.x *= a.x;
	x_axis.y *= a.x;
	y_axis.x *= a.y;
	y_axis.y *= a.y;
	return (ft_vec2_add(x_axis, y_axis));
}
