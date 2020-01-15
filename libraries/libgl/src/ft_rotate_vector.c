/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:13:53 by msidqi            #+#    #+#             */
/*   Updated: 2019/12/26 20:13:55 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

t_vec3	ft_vec3_rotate_z(t_vec3 vector, double rotation_angle)
{
	return ((t_vec3){
	cos(rotation_angle) * vector.x - sin(rotation_angle) * vector.y,
	sin(rotation_angle) * vector.x + cos(rotation_angle) * vector.y,
	vector.z});
}

t_vec3	ft_vec3_rotate_y(t_vec3 vector, double rotation_angle)
{
	return ((t_vec3){
	cos(rotation_angle) * vector.x + sin(rotation_angle) * vector.z,
	vector.y,
	-sin(rotation_angle) * vector.x + cos(rotation_angle) * vector.z});
}

t_vec3	ft_vec3_rotate_x(t_vec3 vector, double rotation_angle)
{
	return ((t_vec3){
	vector.x,
	cos(rotation_angle) * vector.y - sin(rotation_angle) * vector.z,
	sin(rotation_angle) * vector.y + cos(rotation_angle) * vector.z});
}

t_vec3	ft_vec3_rotate_z_const(t_vec3 vector)
{
	return ((t_vec3){
	0.99999979 * vector.x + 0.00065042 * vector.y,
	-0.00065042 * vector.x + 0.99999979 * vector.y,
	vector.z});
}

t_vec2	ft_vec2_from_angle(double size, double angle)
{
	t_vec2	result;

	result.x = size * cos(angle);
	result.y = size * sin(angle);
	return (result);
}
