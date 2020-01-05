/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_objects.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:10:54 by abiri             #+#    #+#             */
/*   Updated: 2020/01/05 21:18:06 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICAL_OBJECTS_H
# define GRAPHICAL_OBJECTS_H
# include "vectors.h"
# include "animation_textures.h"
# include "ttslist.h"

/*
**	This is the sector struct, a sector is an area.
**
*/

typedef struct	s_sector
{
	int			id;
	t_list_head	walls;
	t_list_head	portals;
	t_list_head	sprites;
	double		brightness;
	double		floor_height;
	double		ceil_height;
	t_sdl_image *floor_texture;
	t_sdl_image *ceil_texture;
	uint32_t	props;
}				t_sector;

/*
**	This is the wall struct
**		- p1 : the first point from the wall
**		- p2 : the second point from the wall
**		- texture : the texture that should be applied to the wall
**		- props : properties as transparency and wall itersection
*/

typedef struct	s_wall
{
	t_vector		p1;
	t_vector		p2;
	t_texture		*texture;
	uint32_t		props;
}				t_wall;

/*
**	This is the portal struct
**		- wall : the wall representing the position of the portal
**		- sector : the sector that this portal takes to
*/

typedef struct	s_portal
{
	t_wall			wall;
	t_sector		*sector;
}				t_portal;

/*
**	This is the sprites (objects)
**		- position : the position of the sprite
**		- radius : half the width, as it is represented in 2d as a circle
**		- height : the height of the sprite
**		- altitude : the height relative to the floor
**		- angle : the angle defining the front of the sprite
**		- properties : defining intersection and other stuff
**		- animation : the struct containing the current texture and switching
**			it depending on the state (time or angle)
*/

typedef struct	s_sprite
{
	t_vector		position;
	double			radius;
	double			height;
	double			altitude;
	double			angle;
	uint32_t		props;
	t_animation		animation;
}				t_sprite;

/*
**	This is the struct that will contain all the renderable objects
*/

/*typedef struct	s_graphical_scene
{
	t_list_head	*sectors;
	t_list_node	*current_sector;
}				t_graphical_scene;*/

/*
**	CONSTRUCTORS FOR GRAPHICAL OBJECTS
*/

t_wall		*ft_new_wall(t_point p1, t_point p2);
t_sector	*ft_new_sector(void);
#endif
