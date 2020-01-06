/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_normalize_magnitude.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:37:59 by msidqi            #+#    #+#             */
/*   Updated: 2019/07/17 15:51:11 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

double	ft_vec3_mag_cmp(t_vec3 a, t_vec3 b)
{
	return ((a.x * a.x + a.y * a.y + a.z * a.z)
			- (b.x * b.x + b.y * b.y + b.z * b.z));
}

double	ft_vec4_mag(t_vec4 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec4	ft_vec4_normalize(t_vec4 a)
{
	t_vec4		ret;
	double		hold;

	hold = ft_vec4_mag(a);
	ret.x = a.x / hold;
	ret.y = a.y / hold;
	ret.z = a.z / hold;
	ret.w = a.w / hold;
	return (ret);
}

t_vec2	ft_vec2_normalize(t_vec2 a)
{
	t_vec2		ret;
	double		hold;

	hold = ft_vec2_mag(a);
	ret.x = a.x / hold;
	ret.y = a.y / hold;
	return (ret);
}

t_vec3	ft_vec3_normalize(t_vec3 a)
{
	t_vec3		ret;
	double		hold;

	hold = ft_vec3_mag(a);
	ret.x = a.x / hold;
	ret.y = a.y / hold;
	ret.z = a.z / hold;
	return (ret);
}
