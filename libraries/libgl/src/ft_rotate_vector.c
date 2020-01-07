/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:13:53 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/07 17:54:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

t_vec2	ft_vec2_from_angle(double size, double angle)
{
	t_vec2	result;

	result.x = size * cos(angle);
	result.y = size * sin(angle);
	return (result);
}

t_vec3	ft_vec3_rotate_z(t_vec3 vector, double rotation_angle)
{
	return ((t_vec3){
	cos(-rotation_angle) * vector.x - sin(-rotation_angle) * vector.y,
	sin(-rotation_angle) * vector.x + cos(-rotation_angle) * vector.y,
	vector.z});
}
