/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:31:28 by abiri             #+#    #+#             */
/*   Updated: 2019/12/26 12:28:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include "drawing.h"

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

double		ft_vector_size(t_vector *vector);
double		ft_vector_distance(t_point	p1, t_vector p2);
t_vector	ft_vector_from_angle(double	size, double angle);
void		ft_normalise_vector(t_vector *vector);
#endif
