/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:36:39 by msidqi            #+#    #+#             */
/*   Updated: 2019/07/17 15:37:47 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

t_vec4		ft_vec4_scalar(t_vec4 a, double factor)
{
	t_vec4 ret;

	ret.x = a.x * factor;
	ret.y = a.y * factor;
	ret.z = a.z * factor;
	ret.w = 0;
	return (ret);
}

t_vec2		ft_vec2_scalar(t_vec2 a, double factor)
{
	t_vec2 ret;

	ret.x = a.x * factor;
	ret.y = a.y * factor;
	return (ret);
}

t_vec3		ft_vec3_scalar(t_vec3 a, double factor)
{
	t_vec3 ret;

	ret.x = a.x * factor;
	ret.y = a.y * factor;
	ret.z = a.z * factor;
	return (ret);
}
