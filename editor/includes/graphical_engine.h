/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:55:14 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 18:14:11 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GRAPHICAL_ENGINE_H
# define GRAPHICAL_ENGINE_H
# include "vectors.h"
# include "raycasting.h"
# include "graphical_objects.h"
# include "ttslist.h"
# define PROJECTION_PLANE 1305
# define PROJECTION_DISTANCE 900.0
# define CONFIG_RES_RATIO 1
# define MAX_RENDER_DISTANCE 10000.0
# define DEFAULT_WALL_HEIGHT 1024

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

typedef struct	s_graphical_scene
{
	t_camera	camera;
	t_list_head	sectors;
	t_sdl_image	**textures;
	int			textures_count;
	t_sector	*current_sector;
	t_sdl_image	*render_image;

}				t_graphical_scene;

/*
**	RENDERING FUNCTIONS
*/

void    ft_render_scene(t_graphical_scene *scene);
void    ft_intersect_ray(t_graphical_scene *scene, t_raycast *raygen,
    t_sector *sector, int x);
#endif