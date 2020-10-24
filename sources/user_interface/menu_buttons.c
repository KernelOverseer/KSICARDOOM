/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 03:38:59 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 20:22:46 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	ft_draw_menu_button(t_menu_button *button, t_sdl_image *image,
	t_text format, t_sdl_image *select_indicator)
{
	t_rect	indicator_rect;
	t_rect	text_rect;

	text_rect = ft_sdl_put_text(button->text, format, button->font, image);
	indicator_rect = (t_rect){text_rect.x - SELECT_INDICATOR_WIDTH / 2 +
		SELECT_INDICATOR_OFFSET, text_rect.y - SELECT_INDICATOR_WIDTH / 2,
		SELECT_INDICATOR_WIDTH, SELECT_INDICATOR_HEIGHT};
	if (select_indicator)
		ft_blit_image(indicator_rect, select_indicator, image);
}

void	ft_draw_menu_buttons(t_menu *menu, t_sdl_image *image)
{
	t_menu_button	*button;
	t_text			format;

	menu->buttons.iterator = menu->buttons.first;
	while ((button = ttslist_iter_content(&menu->buttons)))
	{
		format = button->format;
		format.x += menu->position.x;
		format.y += menu->position.y;
		ft_draw_menu_button(button, image, format,
			(menu->selected_button == button) ? menu->select_indicator : NULL);
	}
}

void			ft_apply_button_handler(t_menu_button *button,
	t_doom_env *env)
{
	if (!button)
		return ;
	if (button->handler)
		button->handler(button, env);
}

void			ft_catch_button_input(t_menu *menu, t_doom_env *env)
{
	static	t_sound_track	*menu_effect = NULL;
	t_list_node	*new_button_node;
	static int	pressed = false;

	if (menu_effect == NULL)
		menu_effect = ft_new_track("sound/menu_effect.wav");
	if (!menu)
		return ;
	new_button_node = NULL;
	if (!menu->selected_button)
	{
		if (menu->buttons.first)
		{
			menu->selected_button = menu->buttons.first->content;
		}
		return ;
	}
	if (env->keys[SDL_SCANCODE_DOWN])
	{
		if (!pressed)
		{
			ft_sound_play_track(menu_effect);
			new_button_node = menu->selected_button->parent_node->next;
		}
		pressed = SDL_SCANCODE_DOWN;
	}
	else if (env->keys[SDL_SCANCODE_UP])
	{
		if (!pressed)
		{
			ft_sound_play_track(menu_effect);
			new_button_node = menu->selected_button->parent_node->prev;
		}
		pressed = SDL_SCANCODE_UP;
	}
	else if (env->keys[SDL_SCANCODE_RETURN])
	{
		if (!pressed)
		{
			ft_apply_button_handler(menu->selected_button, env);
		}
		pressed = SDL_SCANCODE_RETURN;
	}
	else if (pressed)
	{
		pressed = false;
		return ;
	}
	if (new_button_node)
		menu->selected_button = new_button_node->content;
}

t_menu_button	*ft_new_button(const char *text)
{
	t_menu_button	*result;

	if (!(result = ft_memalloc(sizeof(t_menu_button))))
		return (NULL);
	result->text = ft_strdup(text);
	return (result);
}
