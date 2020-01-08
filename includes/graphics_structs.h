/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_structs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:43:01 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 23:33:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_STRUCTS_H
# define GRAPHICS_STRUCTS_H
# include "libgl.h"
# include "ttslist.h"
# include "ft_simplesdl.h"
# include "config.h"
# define PROJECTION_PLANE CONF_WINDOW_WIDTH / 10
# define PROJECTION_DISTANCE 45.0
# define CONFIG_RES_RATIO 1
# define MAX_RENDER_DISTANCE INFINITY
# define DEFAULT_WALL_HEIGHT 5000.0
# define CONF_CAMERA_HEIGHT DEFAULT_WALL_HEIGHT / 2

typedef struct  s_camera                t_camera;
typedef struct  s_graphical_settings    t_graphical_settings;
typedef struct  s_graphical_scene       t_graphical_scene;
typedef struct  s_ray                   t_ray;
typedef struct  s_intercalc             t_intercalc;
typedef struct  s_intersect             t_intersect;
typedef struct  s_raycast               t_raycast;
typedef struct  s_sector                t_sector;
typedef struct  s_wall                  t_wall;
typedef struct  s_portal                t_portal;
typedef struct  s_sprite                t_sprite;
typedef struct  s_segment_distance      t_segment_distance;
typedef struct  s_animation             t_animation;
typedef struct	s_intersect_object		t_intersect_object;


enum	e_object_type
{
	OBJECT_wall = 1, OBJECT_portal, OBJECT_sprite
};

struct s_graphical_settings
{
    double  projection_plane;
    double  projection_distance;
    int     resolution_ratio;
};

/*
**	This union will contain a pointer to the objects that a ray can intersect with
*/

union	u_render_object
{
	t_wall		*wall;
	t_portal	*portal;
	t_sprite	*sprite;
};

/*
**	This struct will contain the object that the ray intersected with and an int
**		indicating its type
*/

struct	s_intersect_object
{
	union u_render_object	object;
	enum e_object_type		type;
};

/*
**	This is the ray that will be used to check intersections aftecr
**		- origin : the center from where the ray is casted (Ex. camera position)
**		- direction : a vector representing the direction of the ray
**		- distance : distance from the last intersected object
*/

struct	s_ray
{
	t_vec2		origin;
	t_vec2		dir;
	double		dist;
	int			screen_x;
};

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

struct	s_raycast
{
	t_ray		ray;
	t_vec2		plane;
	t_vec2		direction;
	t_vec2		swipe;
	t_vec2		iter;
	double		render_min;
	double		render_max;
};

struct			s_intersect
{
	t_sector			*sector;
    t_ray				ray;
	t_vec2				pos;
	double				distance;
	double				real_distance;
    double				min_dist;
	int					render_min;
	int					render_max;
	int					screen_x;	
	t_intersect_object	object;
};


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

struct			s_camera
{
	t_raycast	raycast;
	t_vec2		position;
	double		angle;
	int			height;
	int			tilt;
};

struct			s_graphical_scene
{
	t_camera	camera;
	t_list_head	sectors;
	t_sector	*current_sector;
	t_sdl_image	*render_image;

};

struct          s_intercalc
{
    t_vec2				p1;
    t_vec2				p2;
    t_vec2				p3;
    t_vec2				p4;
    double              den;
    double              u;
    double              t;
};

/*
**	The animation struct for animating objects and sprites
**
*/

struct          s_animation
{
	t_sdl_image **textures;
	double		current_frame;
	double		speed;
	int			frame_count;
	uint32_t	now_time;
	uint32_t	type;
	uint32_t	props;
};

/*
**	This is the sector struct, a sector is an area.
**
*/

struct	s_sector
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
};

/*
**	This is the wall struct
**		- p1 : the first point from the wall
**		- p2 : the second point from the wall
**		- texture : the texture that should be applied to the wall
**		- props : properties as transparency and wall itersection
*/

struct	s_wall
{
	t_vec2			p1;
	t_vec2			p2;
	t_sdl_image		*texture;
	uint32_t		props;
};

/*
**	This is the portal struct
**		- wall : the wall representing the position of the portal
**		- sector : the sector that this portal takes to
*/

struct	s_portal
{
	t_wall			wall;
	t_sector		*sector;
};

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

struct	s_sprite
{
	t_vec2			position;
	double			radius;
	double			height;
	double			altitude;
	double			angle;
	uint32_t		props;
	t_animation		animation;
};

/*
**	This is the struct that will contain all the renderable objects
*/

/*typedef struct	s_graphical_scene
{
	t_list_head	*sectors;
	t_list_node	*current_sector;
}				t_graphical_scene;*/

#endif