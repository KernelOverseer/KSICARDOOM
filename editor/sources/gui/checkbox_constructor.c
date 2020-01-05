/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_constructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:27:13 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 17:51:30 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_checkbox.h"

t_gui_component	*ft_gui_new_checkbox(t_rect rect, uint32_t *value, uint32_t mask)
{
	t_gui_component	*component;
	t_gui_checkbox	*checkbox;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
	if (!(checkbox = ft_memalloc(sizeof(t_gui_checkbox))))
	{
		free(component);
		return (NULL);
	}
	checkbox->value = value;
	checkbox->mask = mask;
	component->data = checkbox;
	component->draw = ft_gui_checkbox_draw;
	component->event.on_click = ft_gui_checkbox_on_click;
	component->event.on_hover = ft_gui_checkbox_on_hover;
	component->event.on_lose_focus = ft_gui_checkbox_on_lose_focus;
	component->event.on_release = ft_gui_checkbox_on_release;
	return (component);
}
