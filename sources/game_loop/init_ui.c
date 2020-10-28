/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:12:12 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 03:03:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_graphical_scene	*g_parsed_scene;

int	ft_load_menu_ressources(t_doom_env *env)
{
	(void)env;
	return (1);
}

int	ft_init_game_window(t_doom_env *env)
{
	t_sdl_init_config	config;

	config = ft_sdl_new_config();
	config.screen_width = CONF_WINDOW_WIDTH;
	config.screen_height = CONF_WINDOW_HEIGHT;
	config.window_title = CONF_WINDOW_TITLE;
	if (!ft_sdl_init(&(env->display), config))
		return (ERROR);
	if (!ft_load_menu_ressources(env))
		return (ERROR);
	if (!(env->main_image = newimage(CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT)))
		return (ERROR);
	// limits the mouse to the window and hides the cursor
	//SDL_SetRelativeMouseMode(SDL_TRUE);
	if (TTF_Init())
	{
		ft_raise_exception(ERROR_graphical_init, SDL_GetError());
		return (ERROR);
	}
	// init somewhere else
	ft_init_timer(&env->timer);
	ft_init_physics(&env->phi);
	ttslist_init(&(env->controllers));
	ttslist_init(&(env->bodies));
	ft_bzero(env->keys, sizeof(env->keys));
	//------------------------------------
	return (SUCCESS);
}
