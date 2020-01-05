/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:26:51 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 13:22:44 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include <stdio.h>

int	ft_main_loop(void *arg)
{
	t_doom_env *env;

	env = arg;

	//ft_apply_controllers(env);
	//ft_render_graphics(env);
	return (SUCCESS);
}

int	ft_menu_loop(void *arg)
{
	t_doom_env *env;
	static t_sdl_image	menu_image;

	env = arg;

	//ft_interact_menu(env);
	//ft_render_menu(env);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_doom_env	env;
	(void)argc;
	(void)argv;

	ft_init_game_window(&env);
	ft_sdl_hook(ft_keyboard_button_on, &env, SDL_KEYDOWN);
	ft_sdl_hook(ft_keyboard_button_off, &env, SDL_KEYUP);
	ft_sdl_loop_hook(ft_menu_loop, &env);
	ft_sdl_loop(&env.display);
	return (0);
}
