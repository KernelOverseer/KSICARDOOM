/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:26:51 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 12:21:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_main_loop(void *arg)
{
	t_doom_env *env;

	env = arg;
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_doom_env	env;
	(void)argc;
	(void)argv;

	ft_init_game_window(&env.display);
	ft_sdl_hook(ft_keyboard_button_on, &env, SDL_KEYDOWN);
	ft_sdl_hook(ft_keyboard_button_off, &env, SDL_KEYUP);
	ft_sdl_loop_hook(ft_main_loop, &env);
	ft_sdl_loop(&env.display);
	return (0);
}
