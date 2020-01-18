/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:55:14 by abiri             #+#    #+#             */
/*   Updated: 2020/01/18 18:25:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GRAPHICAL_ENGINE_H
# define GRAPHICAL_ENGINE_H
# include "raycasting.h"
# include "graphics_structs.h"
# include "graphics_drawing.h"
# include "animation_textures.h"
# include "libgl.h"
# include "ray_calculations.h"
# include "graphical_objects.h"
# include "ttslist.h"
# define TEMP_RENDER_ACTIVE_WALL_COLOR 0xFFFFFF
# define TEMP_RENDER_INACTIVE_WALL_COLOR 0x686868
# define TEMP_RENDER_ACTIVE_PORTAL_COLOR 0xFF0000
# define TEMP_RENDER_INACTIVE_PORTAL_COLOR 0x680000
# define TEMP_RENDER_ACTIVE_SPRITE_COLOR 0x00FF00
# define TEMP_RENDER_INACTIVE_SPRITE_COLOR 0x006800

/*
**	RENDERING INTERFACE FUNCTIONS
*/

int	temp_render_graphics(t_graphical_scene *scene);

/*
**	RENDERING FUNCTIONS
*/

void	ft_render_scene(t_graphical_scene *scene);
void	ft_prepare_wall_rendering(t_graphical_scene *scene,
	t_intersect *inter, t_render_wall *render);
void	ft_render_wall(t_graphical_scene *scene, t_render_wall *render);
void	ft_prepare_portal_rendering(t_graphical_scene *scene,
	t_intersect *inter, t_render_portal *render);
void	ft_prepare_sprite_rendering(t_graphical_scene *scene,
	t_intersect *inter, t_render_sprite *render);
void	ft_render_sprite(t_graphical_scene *scene, t_render_sprite *render);
void	ft_handle_sprite_intersection(t_graphical_scene *scene,
	t_intersect *inter);
void	ft_handle_portal_intersection(t_graphical_scene *scene,
	t_intersect *inter);
void	ft_handle_wall_intersection(t_graphical_scene *scene,
	t_intersect *inter);
void	ft_handle_intersect(t_graphical_scene *scene, t_intersect *inter);
int		ft_draw_skybox(t_graphical_scene *scene);
void	ft_render_wall_ceiling(t_graphical_scene *scene,
 	t_render_wall *render);
#endif
