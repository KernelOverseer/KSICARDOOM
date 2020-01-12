/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_drawing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 21:52:16 by abiri             #+#    #+#             */
/*   Updated: 2020/01/09 21:34:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_DRAWING_H
# define GRAPHICS_DRAWING_H
# include "graphics_structs.h"

typedef struct  s_render_wall
{
    t_point     top;
    t_point     bottom;
    int         render_top;
    int         render_bottom;
    double      reverse_distance;
    int         center;
    double      half_height;
    int         texture_x;
    t_intersect *inter;
    t_wall      *wall;
}               t_render_wall;

typedef struct	s_render_portal
{
	t_render_wall	this_sector;
	t_render_wall	that_sector;
	double			reverse_distance;
	double			half_height;
	int				center;
	t_portal		*portal;
	t_intersect		*inter;
	int				render_top;
	int				render_bottom;
}				t_render_portal;


# endif