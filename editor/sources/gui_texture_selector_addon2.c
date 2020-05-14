/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_texture_selector_addon2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 23:41:31 by abiri             #+#    #+#             */
/*   Updated: 2020/05/14 01:19:00 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "gui_texture_selector_addon.h"

void	ft_gui_texture_selector_on_scroll(t_tts_gui *gui_env,
		t_gui_component *component)
{
	t_gui_texture_selector	*data;
	int						max_offset;
	int						margin;

	data = component->data;
	margin = ((int)component->width % (int)ICON_MIN_SIZE) /
			 (component->width / ICON_MIN_SIZE + 1);
	max_offset = (data->texture_list_size /
		(component->width / (int)(margin + ICON_MIN_SIZE)));
	if (component->event.e.wheel.y > 0)
		data->scroll_offset++;
	else if (component->event.e.wheel.y < 0)
		data->scroll_offset--;
	margin = component->height / (int)(margin + ICON_MIN_SIZE);
	if (data->scroll_offset < 0)
		data->scroll_offset = 0;
	else if (data->scroll_offset > max_offset - margin)
		data->scroll_offset = max_offset - margin;
}

void	ft_gui_texture_selector_scroll_bar(t_gui_texture_selector *data,
	t_gui_component *component, t_tts_gui *gui_env)
{
	int		max_scroll;
	int		margin;
	t_rect	scroll_rect;

	margin = ((int)component->width % (int)ICON_MIN_SIZE) /
		(component->width / ICON_MIN_SIZE + 1);
	max_scroll = data->texture_list_size /
		(component->width / (int)(margin + ICON_MIN_SIZE));
	scroll_rect.h = (component->height / (max_scroll -
		(component->height / (int)(margin + ICON_MIN_SIZE))) - 1);
	scroll_rect.w = SCROLL_RECT_WIDTH;
	scroll_rect.x = component->x_pos + component->width - scroll_rect.w;
	scroll_rect.y = component->y_pos + data->scroll_offset * scroll_rect.h;
	ft_sdl_image_rect(gui_env->image, (t_rect){scroll_rect.x - 1,
	component->y_pos, scroll_rect.w + 2, component->height}, UI_COLOR_DARK_GREY);
	ft_blit_image(scroll_rect, &gui_env->assets[asset_slider], gui_env->image);
}

int	ft_scroll_textures_selector(t_gui_component *component,
		t_point	mouse_position)
{
	t_gui_texture_selector	*data;
	int						max_offset;
	int						margin;
	int						new_offset;

	mouse_position.x -= component->x_pos;
	mouse_position.y -= component->y_pos;
	if (mouse_position.x <= component->width - ICON_MIN_SIZE - 2)
		return (0);
	data = component->data;
	margin = ((int)component->width % (int)ICON_MIN_SIZE) /
			 (component->width / ICON_MIN_SIZE + 1);
	printf("texture_count : %d\n", data->texture_list_size);
	max_offset = (data->texture_list_size /
		(component->width / (int)(margin + ICON_MIN_SIZE)));
	new_offset = mouse_position.y / (component->height / (max_offset -
		(component->height / (int)(margin + ICON_MIN_SIZE))) - 1);
	data->scroll_offset = new_offset;
	margin = component->height / (int)(margin + ICON_MIN_SIZE);
	if (data->scroll_offset < 0)
		data->scroll_offset = 0;
	else if (data->scroll_offset > max_offset - margin)
		data->scroll_offset = max_offset - margin;
	return (1);
}