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
	cos(-rotation_angle) * vector.x - sin(-rotation_angle) * vector.y,
	sin(-rotation_angle) * vector.x + cos(-rotation_angle) * vector.y,
	vector.z});
}
