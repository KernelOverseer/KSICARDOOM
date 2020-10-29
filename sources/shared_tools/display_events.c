/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:07:53 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 19:48:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_keyboard_button_on(void *arg, SDL_Event e)
{
	t_doom_env	*env;

	env = arg;
	env->keys[e.key.keysym.scancode] = 1;
	return (1);
}

int	ft_keyboard_button_off(void *arg, SDL_Event e)
{
	t_doom_env	*env;

	env = arg;
	env->keys[e.key.keysym.scancode] = 0;
	return (1);
}

int	ft_mouse_data(void *arg, SDL_Event e)
{
	t_doom_env	*env;

	env = arg;
	if (e.type == SDL_MOUSEMOTION)
		env->mouse_pos = (t_vec2int){e.motion.x, e.motion.y};
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_RIGHT)
			env->mouse_buttons[MOUSE_BUTTON_RIGHT] = 1;
		else if (e.button.button == SDL_BUTTON_LEFT)
			env->mouse_buttons[MOUSE_BUTTON_LEFT] = 1;
		else if (e.button.button == SDL_BUTTON_MIDDLE)
			env->mouse_buttons[MOUSE_BUTTON_MIDDLE] = 1;
	}
	else if (e.type == SDL_MOUSEBUTTONUP)
	{
		if (e.button.button == SDL_BUTTON_RIGHT)
			env->mouse_buttons[MOUSE_BUTTON_RIGHT] = 0;
		else if (e.button.button == SDL_BUTTON_LEFT)
			env->mouse_buttons[MOUSE_BUTTON_LEFT] = 0;
		else if (e.button.button == SDL_BUTTON_MIDDLE)
			env->mouse_buttons[MOUSE_BUTTON_MIDDLE] = 0;
	}
	return (1);
}
