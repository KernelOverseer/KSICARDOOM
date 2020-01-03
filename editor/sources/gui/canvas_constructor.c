/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:33:51 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 18:21:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_canvas.h"

t_gui_component	*ft_gui_new_canvas(t_rect rect, t_sdl_image *image)
{
	t_gui_component	*component;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
	component->data = image;
	component->draw = &ft_gui_canvas_draw;
	return (component);
}
