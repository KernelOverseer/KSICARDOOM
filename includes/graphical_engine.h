/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:55:14 by abiri             #+#    #+#             */
/*   Updated: 2019/12/17 21:10:40 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GRAPHICAL_ENGINE_H
# define GRAPHICAL_ENGINE_H
# define "vectors.h"
# define "raycasting.h"

/*
**	To make everything portable and compact the scene and everything that the
**		rendering engine needs should be defined in one struct
*/

/*
**	This is the camera struct, will contain position and the projection plane
**		- raycast : the struct that will be used for ray generation
**		- position : the position of the camera
**		- angle : the horizontal angle of the camera (not field of view)
**		- height : the height of the camera relative to the ground
**		- tilt : the vertical tilt of the camera (since the renderer is not 3d
**			we cannot have the tilt as an angle)
*/

typedef	struct	s_camera
{
	t_raycast	raycast;
	t_vector	position;
	double		angle;
	int			height;
	int			tilt;
}				t_camera;

typedef struct	s_graphical_settings;
{
}				t_graphical_settings;
#endif
