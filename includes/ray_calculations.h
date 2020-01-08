/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:17:34 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 21:30:20 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CALCULATIONS_H
# define RAY_CALCULATIONS_H
# define HALF_PI 1.57079632679
# include "graphics_structs.h"

struct	s_segment_distance
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	dot;
	double	len_sq;
	double	param;
	double	xx;
	double	yy;
	double	dx;
	double	dy;
};

double	ft_segment_distance_sq(t_point player_pos, t_point p1, t_point p2);
t_vec2  ft_intersect(t_ray ray, t_wall wall, int *status);
t_vec2	ft_segment_intersect(t_point player, t_vec2 dir, t_wall wall, int *status);
void	ft_intersect_ray(t_graphical_scene *scene, t_intersect *inter,
	t_sector *sector);

#endif