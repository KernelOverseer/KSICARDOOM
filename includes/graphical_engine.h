/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:55:14 by abiri             #+#    #+#             */
/*   Updated: 2020/01/07 18:07:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GRAPHICAL_ENGINE_H
# define GRAPHICAL_ENGINE_H
# include "raycasting.h"
# include "graphics_structs.h"
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

void    ft_render_scene(t_graphical_scene *scene);
#endif