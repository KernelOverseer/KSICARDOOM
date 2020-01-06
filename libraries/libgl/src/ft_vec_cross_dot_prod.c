/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cross_dot_prod.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:40:05 by msidqi            #+#    #+#             */
/*   Updated: 2019/12/31 08:57:07 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

double	ft_vec4_dot_product(t_vec4 a, t_vec4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec4	ft_vec4_cross_product(t_vec4 vec1, t_vec4 vec2)
{
	t_vec4 ret;

	ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
	ret.w = 0;
	return (ret);
}

t_vec3	ft_vec3_cross_product(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 ret;

	ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (ret);
}

double	ft_vec2_dot_product(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

/*
** For normalized vectors Dot returns 1 if they point in exactly
** the same direction, -1 if they point in completely opposite directions
** and zero if the vectors are perpendicular.
** Angle between them θ = acos([A•B]/[|A||B|]) && if A B are
** 												normalized θ = acos(AB).
**  A • B = |A||B|cos(θ) ==> (|B|cos(θ) how much do they move together).
** ==> the extent to which the vectors are pointing in the same direction.
*/

double	ft_vec3_dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
