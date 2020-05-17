/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_texture_selector_addon.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:09:39 by abiri             #+#    #+#             */
/*   Updated: 2020/05/15 01:13:12 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "gui_texture_selector_addon.h"

static t_sdl_image	*ft_get_selected_texture(t_gui_component *component,
		t_point	mouse_position)
{
	t_gui_texture_selector	*data;
	t_point					texture_index;
	int 					index;
	int 					margin;
	int						line_count;

	data = component->data;
	margin = ((int)component->width % (int)ICON_MIN_SIZE) /
			 (component->width / ICON_MIN_SIZE + 1);
	mouse_position.x -= component->x_pos;
	mouse_position.y -= component->y_pos;
	texture_index.x = mouse_position.x / (int)(margin + ICON_MIN_SIZE);
	texture_index.y = mouse_position.y / (int)(margin + ICON_MIN_SIZE);
	line_count = component->width / (int)(margin + ICON_MIN_SIZE);
	index = (texture_index.y + data->scroll_offset) * line_count
		+ texture_index.x;
	if (index < data->texture_list_size)
		return (&(data->texture_list[index]));
	return (NULL);
}

void			ft_gui_texture_selector_on_click(t_tts_gui *gui_env,
		t_gui_component *component)
{
	t_gui_texture_selector	*selector;
	t_sdl_image				*selected;
	t_point					mouse_position;

	mouse_position.x = gui_env->mouse_position.x - component->x_pos;
	mouse_position.y = gui_env->mouse_position.y - component->y_pos;
	selector = component->data;
	if (ft_scroll_textures_selector(component, gui_env->mouse_position))
		return ;
	if (gui_env->focused &&
		gui_env->focused->draw == ft_gui_draw_texture_display)
	{
		if (gui_env->focused->data)
		{
			selected = ft_get_selected_texture(component,
					gui_env->mouse_position);
			if (selected)
			{
				*((t_sdl_image**)gui_env->focused->data) = selected;
			}
		}
	}
}

void 			ft_gui_texture_selector_draw(t_tts_gui *gui_env,
		t_gui_component *component)
{
	t_gui_texture_selector	*data;
	t_point					start;
	int 					margin;
	int 					texture_index;

	data = component->data;
	if (!data || !data->texture_list)
		return ;
	ft_sdl_image_rect(gui_env->image,
			(t_rect){component->x_pos,component->y_pos,
			component->width, component->height}, UI_COLOR_WHITE);
	margin = ((int)component->width % (int)ICON_MIN_SIZE) /
			(component->width / (ICON_MIN_SIZE + 2));
	start.y = margin;
	texture_index = data->scroll_offset * component->width
		/ (int)(ICON_MIN_SIZE + margin);
	while (texture_index < data->texture_list_size &&
			start.y + ICON_MIN_SIZE <= component->height)
	{
		start.x = margin;
		while (texture_index < data->texture_list_size &&
			start.x + ICON_MIN_SIZE <= component->width)
		{
			ft_blit_image((t_rect){component->x_pos + start.x, component->y_pos + start.y,
						  ICON_MIN_SIZE, ICON_MIN_SIZE},
					&(data->texture_list[texture_index]), gui_env->image);
			start.x += ICON_MIN_SIZE + margin;
			texture_index++;
		}
		start.y += ICON_MIN_SIZE + margin;
	}
	ft_gui_texture_selector_scroll_bar(data, component, gui_env);
}

t_gui_component	*ft_gui_new_texture_selector(t_rect rect, t_sdl_image *list,
		int size, t_sdl_image **to_change)
{
	t_gui_component	*result;

	if (!(result = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	result->x_pos = rect.x;
	result->y_pos = rect.y;
	result->width = rect.w;
	result->height = rect.h;
	ACTIVATE_PROP(result->props, GUI_ACTIVE);
	ACTIVATE_PROP(result->props, GUI_NEVER_FOCUS);
	if (!(result->data = ft_memalloc(sizeof(t_gui_texture_selector))))
	{
		free(result);
		return (NULL);
	}
	((t_gui_texture_selector*)result->data)->texture_list = list;
	((t_gui_texture_selector*)result->data)->texture_list_size = size;
	((t_gui_texture_selector*)result->data)->to_change = to_change;
	result->draw = ft_gui_texture_selector_draw;
	result->event.on_click = ft_gui_texture_selector_on_click;
	result->event.on_mouse_wheel = ft_gui_texture_selector_on_scroll;
	return (result);
}
