/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:34:58 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 10:37:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include <stdio.h>

int		ft_display_init(t_doom_editor *env)
{
	t_sdl_init_config	sdl_config;

	sdl_config = ft_sdl_new_config();
	sdl_config.window_title = "doom_nukem_editor";
	sdl_config.screen_width = WINDOW_WIDTH;
	sdl_config.screen_height = WINDOW_HEIGHT;
	env->display_env = ft_sdl_init(sdl_config);
	if (!env->display_env)
		return (0);
	env->main_image = newimage(sdl_config.screen_width, sdl_config.screen_height);
	if (!env->main_image)
		return (0);
	ttslist_init(&(env->gui.gui_areas));
	return (1);
}

int	ft_main_loop(void *arg)
{
	t_doom_editor	*env;

	env = arg;
	ft_sdl_clear_image(env->main_image, env->gui.background_color);
	ft_draw_gui_areas(&(env->gui));
	ft_sdl_put_image(env->main_image, env->display_env);
	ft_sdl_render_texture(env->display_env);
	return (1);
}

int main(void) {
	t_doom_editor env;

	if (!ft_display_init(&env))
	{
		printf("There is an initialisation ERROR\n");
		return (-1);
	}
	env.gui.image = env.main_image;
	ft_load_debug_gui(&env.gui);
	ft_sdl_hook(&ft_gui_mouse_event, &(env.gui), SDL_MOUSEMOTION);
	ft_sdl_hook(&ft_gui_mouse_event, &(env.gui), SDL_MOUSEBUTTONUP);
	ft_sdl_hook(&ft_gui_mouse_event, &(env.gui), SDL_MOUSEBUTTONDOWN);
	ft_sdl_hook(&ft_gui_mouse_event, &(env.gui), SDL_MOUSEWHEEL);
	ft_sdl_loop_hook(&ft_main_loop, &env);
	ft_sdl_loop(env.display_env);
	return (0);
}
