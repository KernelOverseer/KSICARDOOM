/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 08:36:32 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 17:47:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_button.h"

/*
**	This is an example of a component
**		for a component we need to define maybe a struct that will contain its
**		custom data
**		so we need to fill the component struct with:
**			t_gui_component:
**				x_pos : x position
**				y_pos : y position
**				width : width of component
**				height : height of component
**				props : some of the props are to be set as you like
**				data : this is to be filled with the component specific data
**				draw : a pointer to function that will draw the component
**				event : fill it with functions that handle the events
*/

t_gui_component	*ft_gui_new_button(t_rect rect, t_sdl_image *text,
		t_button_handler *handler, void *arg)
{
	t_gui_component	*component;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
	if (!(component->data = ft_memalloc(sizeof(t_gui_button))))
	{
		free(component);
		return (NULL);
	}
	((t_gui_button*)component->data)->handler = handler;
	((t_gui_button*)component->data)->arg = arg;
	((t_gui_button*)component->data)->text = text;
	component->draw = ft_gui_button_draw;
	component->event.on_click = ft_gui_button_on_click;
	component->event.on_hover = ft_gui_button_on_hover;
	component->event.on_lose_focus = ft_gui_button_on_lose_focus;
	component->event.on_release = ft_gui_button_on_release;
	return (component);
}
