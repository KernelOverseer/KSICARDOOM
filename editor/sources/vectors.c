/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:55:47 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 22:27:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	ft_vector_size(t_vector *vector)
{
	return (sqrt(vector->x * vector->x + vector->y * vector->y));
}

double		ft_vector_distance(t_point	p1, t_vector p2)
{
	t_vector	result;

	result.x = p2.x - p1.x;
	result.y = p2.y - p1.y;
	return (ft_vector_size(&result));
}

t_vector	ft_vector_from_angle(double	size, double angle)
{
	t_vector	new;

	new.x = (double)size * cos(angle);
	new.y = (double)size * sin(angle);
	return (new);
}

void	ft_normalise_vector(t_vector *vector)
{
	double size;

	size = ft_vector_size(vector);
	vector->x /= size;
	vector->y /= size;
}
