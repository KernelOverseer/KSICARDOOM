/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mode_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:58:35 by abiri             #+#    #+#             */
/*   Updated: 2020/05/13 00:30:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	ft_render_move_player(void *arg, SDL_Event e)
{
	t_doom_editor	*env;
	t_vec2			move_vector;

	env = arg;
	if (env->event.preview_mode != PREVIEW_RENDER)
		return (true);
	move_vector = (t_vec2){0, 0};
	if (e.key.keysym.sym == SDLK_LEFT)
		env->data.camera.angle += CAMERA_ANGLE_SPEED;
	else if (e.key.keysym.sym == SDLK_RIGHT)
		env->data.camera.angle -= CAMERA_ANGLE_SPEED;
	else if (e.key.keysym.sym == SDLK_UP)
		move_vector = ft_vec2_from_angle(CAMERA_MOVE_SPEED, env->data.camera.angle);
	else if (e.key.keysym.sym == SDLK_DOWN)
		move_vector = ft_vec2_from_angle(-CAMERA_MOVE_SPEED, env->data.camera.angle);
	env->data.camera.position.x += move_vector.x;
	env->data.camera.position.y += move_vector.y;
	return (true);
}