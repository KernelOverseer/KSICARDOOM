/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:12:12 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 12:40:05 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_init_game_window(t_doom_env *env)
{
	t_sdl_init_config	config;

	config = ft_sdl_new_config();
	config.screen_width = CONF_WINDOW_WIDTH;
	config.screen_height = CONF_WINDOW_HEIGHT;
	config.window_title = CONF_WINDOW_TITLE;
	ttslist_init(&(env->controllers));
	if (!ft_sdl_init(&(env->display), config))
		return (ERROR);
	if (!(env->main_image = newimage(CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT)))
		return (ERROR);
	ft_init_timer(&env->timer);
	ft_init_physics(&env->phi);
	ft_bzero(env->keys, sizeof(env->keys));
	return (SUCCESS);
}
