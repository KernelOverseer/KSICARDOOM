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

int		ft_main_menu_init(t_doom_env *env)
{
	t_menu			*new_menu;
	t_menu_button	*new_button;

	if (!(env->menu_manager = ft_memalloc(sizeof(t_menu_system))))
		return (ERROR);
	ft_init_menu_system(env->menu_manager, NULL);
	env->menu_manager->font = TTF_OpenFont(MENU_FONT, 50);
	if (!env->menu_manager->font)
		return (ERROR);
	new_menu = ft_new_menu();
	new_menu->position = (t_rect){0, 0, env->main_image->width,
		env->main_image->height};
	new_menu->background = ft_memalloc(sizeof(t_sdl_image));
	new_menu->select_indicator = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image(BACKGROUND_IMAGE, new_menu->background);
	ft_sdl_load_image(SELECT_INDICATOR, new_menu->select_indicator);
	if (!new_menu->background || !new_menu->select_indicator)
		return (ERROR);
	ft_add_menu(env->menu_manager, new_menu);
	if (!(new_button = ft_new_button("START")))
		return (ERROR);
	new_button->format.x = new_menu->position.x + new_menu->position.w / 2;
	new_button->format.y = new_menu->position.y + new_menu->position.h / 2 - 100;
	new_button->format.align = ALIGN_CENTER_CENTER;
	new_button->format.color = 0xFFFFFF;
	ft_add_button(new_menu, new_button);
		if (!(new_button = ft_new_button("SETTINGS")))
		return (ERROR);
	new_button->format.x = new_menu->position.x + new_menu->position.w / 2;
	new_button->format.y = new_menu->position.y + new_menu->position.h / 2;
	new_button->format.align = ALIGN_CENTER_CENTER;
	new_button->format.color = 0xFFFFFF;
	ft_add_button(new_menu, new_button);
		if (!(new_button = ft_new_button("EXIT")))
		return (ERROR);
	new_button->format.x = new_menu->position.x + new_menu->position.w / 2;
	new_button->format.y = new_menu->position.y + new_menu->position.h / 2 + 100;
	new_button->format.align = ALIGN_CENTER_CENTER;
	new_button->format.color = 0xFFFFFF;
	ft_add_button(new_menu, new_button);
	return (SUCCESS);
}

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
	if (env->keys[SDL_SCANCODE_RETURN])
		ft_sdl_loop_hook(ft_main_loop, env);
	return (SUCCESS);
}