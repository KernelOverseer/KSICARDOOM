/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:14:34 by abiri             #+#    #+#             */
/*   Updated: 2020/01/07 19:00:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

double	ft_segment_distance_sq(t_point player_pos, t_point p1, t_point p2)
{
	t_segment_distance	calc;

	calc.a = player_pos.x - p1.x;
	calc.b = player_pos.y - p1.y;
	calc.c = p2.x - p1.x;
	calc.d = p2.y - p1.y;

	calc.dot = calc.a * calc.c + calc.b * calc.d;
	calc.len_sq = calc.c * calc.c + calc.d * calc.d;
	calc.param = -1;
	if (calc.len_sq != 0)
		calc.param = calc.dot / calc.len_sq;
	if (calc.param < 0)
	{
		calc.xx = p1.x;
		calc.yy = p1.y;
	}
	else if (calc.param > 1)
	{
    	calc.xx = p2.x;
    	calc.yy = p2.y;
	}
	else
	{
		calc.xx = p1.x + calc.param * calc.c;
    	calc.yy = p1.y + calc.param * calc.d;
	}
	calc.dx = player_pos.x - calc.xx;
	calc.dy = player_pos.y - calc.yy;
	return (calc.dx * calc.dx + calc.dy * calc.dy);
}

static void	ft_point_vector(t_vec2 p, t_vec2 *r1, t_vec2 p2, t_vec2 *r2)
{
	r1->x = p.x;
	r1->y = p.y;
	r2->x = p2.x;
	r2->y = p2.y;
}

/*
**	This function checks if there is an intersection of a ray
**		and any given wall, then returns a vector containing
**		the coordinates of the point of intersection.
**		or NULL if there is no intersection
*/

t_vec2  ft_intersect(t_ray ray, t_wall wall, int *status)
{
	t_intercalc	c;

	*status = 0;
	c.p1 = (t_vec2){ray.origin.x, ray.origin.y};
	c.p2 = (t_vec2){c.p1.x + ray.dir.x, c.p1.y + ray.dir.y};
	ft_point_vector(wall.p1, &c.p3, wall.p2, &c.p4);
	c.den = ((c.p1.x - c.p2.x) * (c.p3.y - c.p4.y) - (c.p1.y - c.p2.y) *
			(c.p3.x - c.p4.x));
	if (c.den == 0)
		return ((t_vec2){0,0});
	c.t = ((c.p1.x - c.p3.x) * (c.p3.y - c.p4.y) - (c.p1.y - c.p3.y) *
			(c.p3.x - c.p4.x)) / c.den;
	if (c.t < 0)
		return ((t_vec2){0,0});
	c.u = -((c.p1.x - c.p2.x) * (c.p1.y - c.p3.y) - (c.p1.y - c.p2.y) *
			(c.p1.x - c.p3.x)) / c.den;
	if (c.u < 0 || c.u > 1)
		return ((t_vec2){0,0});
	*status = 1;
	return ((t_vec2){c.p1.x + c.t * (c.p2.x - c.p1.x), c.p1.y +
				c.t * (c.p2.y - c.p1.y)});
}

/*
**	This function checks if two segemnts intersect
*/

t_vec2	ft_segment_intersect(t_point player, t_vec2 dir, t_wall wall,
  int *status)
{
	t_intercalc	c;

	*status = 0;
	c.p1 = (t_vec2){player.x, player.y};
	c.p2 = (t_vec2){player.x + dir.x, player.y + dir.y};
	ft_point_vector(wall.p1, &c.p3, wall.p2, &c.p4);
	c.den = ((c.p1.x - c.p2.x) * (c.p3.y - c.p4.y) - (c.p1.y - c.p2.y) *
			(c.p3.x - c.p4.x));
	if (c.den == 0)
		return ((t_vec2){0,0});
	c.t = ((c.p1.x - c.p3.x) * (c.p3.y - c.p4.y) - (c.p1.y - c.p3.y) *
			(c.p3.x - c.p4.x)) / c.den;
	if (c.t < 0 || c.t > 1)
		return ((t_vec2){0,0});
	c.u = -((c.p1.x - c.p2.x) * (c.p1.y - c.p3.y) - (c.p1.y - c.p2.y) *
			(c.p1.x - c.p3.x)) / c.den;
	if (c.u < 0 || c.u > 1)
		return ((t_vec2){0,0});
	*status = 1;
	return ((t_vec2){c.p1.x + c.t * (c.p2.x - c.p1.x), c.p1.y +
				c.t * (c.p2.y - c.p1.y)});
}