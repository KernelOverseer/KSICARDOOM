/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 03:27:31 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 04:34:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ft_init_menu_system(t_menu_system *menu_manager, TTF_Font *font)
{
	ft_bzero(menu_manager, sizeof(t_menu));
	menu_manager->font = font;
	ttslist_init(&menu_manager->menu_list);
	ttslist_init(&menu_manager->notifications);
	return (1);
}

t_menu	*ft_new_menu(void)
{
	t_menu	*new_menu;

	if (!(new_menu = ft_memalloc(sizeof(t_menu))))
		return (NULL);
	ttslist_init(&new_menu->buttons);
	return (new_menu);
}

int		ft_add_menu(t_menu_system *menu_manager, t_menu *new_menu)
{
	new_menu->font = menu_manager->font;
	menu_manager->current = new_menu;
	menu_manager->menu_list.push(&menu_manager->menu_list, new_menu);
	return (1);
}

int		ft_add_button(t_menu *menu, t_menu_button *button)
{
	button->font = menu->font;
	button->parent_node = menu->buttons.push(&menu->buttons, button);
	return (1);
}

int		ft_fit_menu_button(t_menu *menu, t_menu_button *button)
{
	ft_add_button(menu, button);
	button->format.y = menu->fit_data.y - menu->position.y;
	menu->fit_data.y += button->format.y;
	return (1);
}

int		ft_draw_menus(t_menu_system *menu_system, t_sdl_image *image)
{
	if (!menu_system->current)
		return (0);
	ft_draw_menu(menu_system->current, image);
	return (1);
}

int		ft_draw_menu(t_menu	*menu, t_sdl_image *image)
{
	ft_blit_image(menu->position, menu->background, image);
	ft_draw_menu_buttons(menu, image);
	return (1);
}
