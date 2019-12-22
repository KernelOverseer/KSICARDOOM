/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 09:23:16 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 11:09:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

void	ft_draw_rect(t_sdl_image *image, t_rect rect, uint32_t color)
{
	int	x;
	int y;

	y = 0;
	while (y < rect.height)
	{
		x = 0;
		while (x < rect.width)
		{
			ft_sdl_image_pixel(image, rect.x + x, rect.y + y, color);
			x++;
		}
		y++;
	}
}

int		ft_is_mouse_in(t_rect rect, int x, int y)
{
	if (x > rect.x && y > rect.y &&
			x < rect.x + rect.width && y < rect.y + rect.height)
		return (1);
	return (0);
}

int		ft_is_mouse_in_component(t_gui_component *component, int x, int y)
{
	t_rect	rect;

	rect.x = component->x_pos;
	rect.y = component->y_pos;
	rect.width = component->width;
	rect.height = component->height;
	return (ft_is_mouse_in(rect, x, y));
}

int		ft_is_mouse_in_area(t_gui_area *area, int x, int y)
{
	t_rect	rect;
	
	rect.x = area->x_pos;
	rect.y = area->y_pos;
	rect.width = area->width;
	rect.height = area->height;
	return (ft_is_mouse_in(rect, x, y));
}
