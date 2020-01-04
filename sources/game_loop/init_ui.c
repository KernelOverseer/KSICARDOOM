/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:12:12 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 11:53:06 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_init_game_window(t_sdl_env *sdl_env)
{
	t_sdl_init_config	config;

	config = ft_sdl_new_config();
	config.screen_width = CONF_WINDOW_WIDTH;
	config.screen_height = CONF_WINDOW_HEIGHT;
	config.window_title = CONF_WINDOW_TITLE;
	if (!ft_sdl_init(sdl_env, config))
		return (ERROR);
	return (SUCCESS);
}
