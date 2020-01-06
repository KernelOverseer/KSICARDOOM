/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:31:28 by abiri             #+#    #+#             */
/*   Updated: 2020/01/06 13:09:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include "drawing.h"

double		ft_vector_size(t_vec2 *vector);
double		ft_vector_distance(t_point	p1, t_vec2 p2);
t_vec2		ft_vector_from_angle(double	size, double angle);
void		ft_normalise_vector(t_vec2 *vector);
#endif
