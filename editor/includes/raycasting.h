/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:50:42 by abiri             #+#    #+#             */
/*   Updated: 2019/12/26 12:27:03 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "vectors.h"
# include "graphical_objects.h"

/*
**	This is the ray that will be used to check intersections aftecr
**		- origin : the center from where the ray is casted (Ex. camera position)
**		- direction : a vector representing the direction of the ray
**		- distance : distance from the last intersected object
*/

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
	double		distance;
}				t_ray;

typedef struct          s_intercalc
{
    t_vector            p1;
    t_vector            p2;
    t_vector            p3;
    t_vector            p4;
    double              den;
    double              u;
    double              t;
}                       t_intercalc;

typedef struct	s_intersect
{
	t_sector	*sector;
	t_ray		ray;
	t_vector	pos;
	double		distance;
	double		real_distance;
	int			render_min;
	int			render_max;
	int			screen_x;
	t_wall		*wall;
}				t_intersect;

/*
**	This is the struct that will contain the necessary ray generation data
**		- ray :  is the ray genereated everytime
**		- plane : is rightmost point of the projection plane
**		- swipe : is the leftmost point of the projection plane, will be
**			incremented towards the plane.
**		- iter : a normalised vector that will be added to swipe everytime
**			till swipe reached plane, so we can iterate and generate ray for
**			every column of the screen.
**		- render_min : is the minimum distance to cast the ray to, similar
**			to clipping distance in polygonn renderers
**		- render_max : is the maximum distance to check intersections to
*/

typedef struct	s_raycast
{
	t_ray		ray;
	t_vector	plane;
	t_vector	direction;
	t_vector	swipe;
	t_vector	iter;
	double		render_min;
	double		render_max;
}				t_raycast;

#endif
