/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_area_constructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:23:01 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 14:56:46 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_button.h"
#include "gui_checkbox.h"
#include <stdio.h>

t_gui_area	*ft_new_gui_area(int x_pos, int y_pos, int width, int height)
{
	t_gui_area	*result;

	if (!(result = ft_memalloc(sizeof(t_gui_area))))
		return (NULL);
	result->x_pos = x_pos;
	result->y_pos = y_pos;
	result->width = width;
	result->height = height;
	ttslist_init(&(result->children));
	ACTIVATE_PROP(result->props, GUI_ACTIVE);
	return (result);
}

t_gui_component	*ft_new_gui_component(t_gui_area *parent, int x, int y,
		int width, int height, t_gui_component_function *handle)
{
	t_gui_component	*result;

	if (!(result = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);

	result->x_pos = x;
	result->y_pos = y;
	result->width = width;
	result->height = height;
	result->parent = parent;
	result->draw = handle;
	ACTIVATE_PROP(result->props, GUI_ACTIVE);
	return (result);
}

void	ft_load_debug_gui(t_tts_gui *gui_env)
{
	t_gui_area	*new_area;

	gui_env->background_color = 0xc0c4c8;
	printf("will now start loading the debug GUI\n");
	new_area = ft_new_gui_area(0, 0, 600, 600);
	printf("created a new gui area\n");
	t_gui_component	*element;

	element = ft_gui_new_checkbox((t_rect){50, 50, 24, 24}, (uint32_t *)&(new_area->background_color), 0x1);
	element->parent = new_area;
	new_area->children.push(&(new_area->children), element);
	element = ft_gui_new_button((t_rect){200, 200, 100, 50}, NULL, &(new_area->background_color));
	element->parent = new_area;
	new_area->children.push(&(new_area->children), element);
//	element = ft_gui_new_button((t_rect){50, 150, 100, 100}, this_is_another_test_function_for_button, &(new_area->background_color));
	element = ft_gui_new_checkbox((t_rect){50, 150, 24, 24}, (uint32_t *)&(new_area->background_color), 0x100);
	element->parent = new_area;
	new_area->children.push(&(new_area->children), element);
	new_area->background_color = gui_env->background_color;
	gui_env->gui_areas.push(&(gui_env->gui_areas), new_area);
	printf("loaded a debug GUI and all good till now\n");
}
