/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_texture_display_addon.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:34:45 by abiri             #+#    #+#             */
/*   Updated: 2020/01/07 17:12:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_texture_display_addon.h"

void			ft_gui_draw_texture_display(t_tts_gui	*gui_env,
		t_gui_component *component) {
	t_sdl_image **image;
	t_rect rect;

	rect.x = component->x_pos;
	rect.y = component->y_pos;
	rect.w = component->width;
	rect.h = component->height;
	if (gui_env->focused == component)
		ft_sdl_image_rect(gui_env->image, rect, CORRECT_COLOR(UI_COLOR_GREEN));
    else
        ft_sdl_image_rect(gui_env->image, rect, CORRECT_COLOR(UI_COLOR_DARK_GREY));
	image = component->data;
	if (!image || !*image)
		return ;
	rect.x += FOCUS_BORDER_SIZE;
	rect.y += FOCUS_BORDER_SIZE;
	rect.w -= 2 * FOCUS_BORDER_SIZE;
	rect.h -= 2 * FOCUS_BORDER_SIZE;
	if (gui_env->focused == component)
		ft_sdl_image_rect(gui_env->image, rect,
				CORRECT_COLOR(gui_env->focused->parent->background_color));
	ft_blit_image(rect, *image, gui_env->image);
}

t_gui_component	*ft_gui_new_texture_display(t_rect rect,
		t_sdl_image **texture_addr)
{
	t_gui_component	*component;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
	component->data = texture_addr;
	component->draw = &ft_gui_draw_texture_display;
	return (component);
}