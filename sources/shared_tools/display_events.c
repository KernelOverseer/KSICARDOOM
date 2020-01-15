/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:07:53 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 12:21:07 by abiri            ###   ########.fr       */
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
	env->mouse_pos = (t_vec2int){e.motion.x, e.motion.y};
	return (1);
}
