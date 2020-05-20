/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:51:07 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 20:16:50 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_menu_loop(void *arg)
{
	t_doom_env *env;

	env = arg;
	// ft_main_menu_background(env);
	// ft_main_menu_draw(env);
	ft_catch_button_input(env->menu_manager->current, env);
	ft_draw_menus(env->menu_manager, env->main_image);
	ft_sdl_put_image(env->main_image, &env->display);
	ft_sdl_render_texture(&env->display);
	return (SUCCESS);
}
