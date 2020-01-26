/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manipulations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:29:50 by abiri             #+#    #+#             */
/*   Updated: 2019/12/26 19:29:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	ft_draw_player(t_doom_editor *env)
{
	t_graphical_scene	*data;
	t_point				player_pos;
//	t_point				player_lookat;
//	t_point				player_screen1;
//	t_point				player_screen2;

	data = &(env->data);
	player_pos = ft_map_to_screen((t_point){data->camera.position.x,
                                         data->camera.position.y,},
                                                 env->event.scale,
                                                 env->event.offset);
/*	player_lookat = player_pos;
	player_lookat.x += (data->camera.raycast.direction.x / env->event.scale);
	player_lookat.y += (data->camera.raycast.direction.y / env->event.scale);
	player_screen1.x = player_lookat.x + data->camera.raycast.plane.x / env->event.scale;
	player_screen1.y = player_lookat.y + data->camera.raycast.plane.y / env->event.scale;
	player_screen2.x = player_lookat.x - data->camera.raycast.plane.x / env->event.scale;
	player_screen2.y = player_lookat.y - data->camera.raycast.plane.y /
 env->event.scale;*/
	ft_sdl_image_disc(env->edit_image, player_pos,
			10, CORRECT_COLOR(UI_COLOR_RED));
/*	ft_sdl_image_line(env->edit_image, player_pos, player_lookat,
			CORRECT_COLOR(UI_COLOR_BLUE));
	ft_sdl_image_line(env->edit_image, player_pos, player_screen1,
					  CORRECT_COLOR(UI_COLOR_BLUE));
	ft_sdl_image_line(env->edit_image, player_pos, player_screen2,
					  CORRECT_COLOR(UI_COLOR_BLUE));
	ft_sdl_image_line(env->edit_image, player_screen1, player_screen2,
					  CORRECT_COLOR(UI_COLOR_BLUE));
*/
}