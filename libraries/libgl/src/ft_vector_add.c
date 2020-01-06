/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:35:25 by msidqi            #+#    #+#             */
/*   Updated: 2019/07/17 15:36:08 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

t_vec4	ft_vec4_add(t_vec4 vec1, t_vec4 vec2)
{
	t_vec4 ret;

	ret.x = vec1.x + vec2.x;
	ret.y = vec1.y + vec2.y;
	ret.z = vec1.z + vec2.z;
	ret.w = 0;
	return (ret);
}

t_vec2	ft_vec2_add(t_vec2 a, t_vec2 b)
{
	t_vec2 ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_vec3	ft_vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3 ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}
