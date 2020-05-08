/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:39:24 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 02:27:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

void	ft_draw_gui_component(t_gui_component *gui_component, t_tts_gui	*gui_env)
{
	if (gui_component->draw)
	{
		gui_component->draw(gui_env, gui_component);
	}
}

static void	ft_draw_gui_area_background(t_sdl_image *image, t_gui_area *area)
{
	uint32_t x;
	uint32_t y;

	y = 0;
	while (y < area->height)
	{
		x = 0;
		while (x < area->width)
		{
			ft_sdl_image_pixel(image, area->x_pos + x, area->y_pos + y,
					area->background_color);
			x++;
		}
		y++;
	}
}

void	ft_draw_gui_area(t_gui_area	*gui_area, t_tts_gui *gui_env)
{
	t_gui_component	*current_component;

	ft_draw_gui_area_background(gui_env->image, gui_area);
	gui_area->children.iterator = gui_area->children.first;
	while ((current_component = ttslist_iter_content((&gui_area->children))))
	{
		if (GET_PROP(current_component->props, GUI_ACTIVE))
			ft_draw_gui_component(current_component, gui_env);
	}
	gui_area->children.iterator = NULL;
}

void	ft_draw_gui_areas(t_tts_gui	*gui_env)
{
	t_gui_area	*current_area;

	gui_env->gui_areas.iterator = gui_env->gui_areas.first;
	while ((current_area = ttslist_iter_content(&(gui_env->gui_areas))))
	{
		if (GET_PROP(current_area->props, GUI_ACTIVE))
			ft_draw_gui_area(current_area, gui_env);
	}
	gui_env->gui_areas.iterator = NULL;
}
