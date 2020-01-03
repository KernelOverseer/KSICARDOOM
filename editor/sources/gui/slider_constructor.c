/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:13:20 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 17:47:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_slider.h"

t_gui_component	*ft_gui_new_slider(t_rect rect, double *value,
		double min, double max)
{
	t_gui_component	*component;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
	if (!(component->data = ft_memalloc(sizeof(t_gui_slider))))
	{
		free(component);
		return (NULL);
	}
	((t_gui_slider*)component->data)->value = value;
	((t_gui_slider*)component->data)->min = min;
	((t_gui_slider*)component->data)->max = max;
	component->draw = ft_gui_slider_draw;
	component->event.on_click = ft_gui_slider_on_click;
	component->event.on_hover = ft_gui_slider_on_hover;
	component->event.on_lose_focus = ft_gui_slider_on_lose_focus;
	component->event.on_release = ft_gui_slider_on_release;
	return (component);
}
