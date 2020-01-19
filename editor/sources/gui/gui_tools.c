/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 09:23:16 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 16:27:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

void	ft_blit_image(t_rect rect, t_sdl_image *texture, t_sdl_image *main_image)
{
	double x_inc;
	double y_inc;
	double x;
	double y;
	int		rect_x;


	if (!texture || !main_image)
		return ;
	x_inc = (double)texture->width / (double)rect.w;
	y_inc = (double)texture->height / (double)rect.h;
	y = 0;
	rect_x = rect.x;
	int xmax = rect.x + rect.w;
	int ymax = rect.y + rect.h;
	int	color;
	while (rect.y < ymax && y < texture->height)
	{
		x = 0;
		rect.x = rect_x;
		while (rect.x < xmax && x < texture->width)
		{
			color = texture->pixels[(int)y * texture->width + (int)x];
			if (RGB_A(color) != 0)
				ft_sdl_set_image_pixel(main_image, rect.x, rect.y, color);
			x += x_inc;
			rect.x++;
		}
		rect.y++;
		y += y_inc;
	}
}


void	ft_draw_rect(t_sdl_image *image, t_rect rect, uint32_t color)
{
	int	x;
	int y;

	y = 0;
	while (y < rect.h)
	{
		x = 0;
		while (x < rect.w)
		{
			ft_sdl_set_image_pixel(image, rect.x + x, rect.y + y, color);
			x++;
		}
		y++;
	}
}

int		ft_is_mouse_in(t_rect rect, int x, int y)
{
	if (x > rect.x && y > rect.y &&
			x < rect.x + rect.w && y < rect.y + rect.h)
		return (1);
	return (0);
}

int		ft_is_mouse_in_component(t_gui_component *component, int x, int y)
{
	t_rect	rect;

	rect.x = component->x_pos;
	rect.y = component->y_pos;
	rect.w = component->width;
	rect.h = component->height;
	return (ft_is_mouse_in(rect, x, y));
}

int		ft_is_mouse_in_area(t_gui_area *area, int x, int y)
{
	t_rect	rect;
	
	rect.x = area->x_pos;
	rect.y = area->y_pos;
	rect.w = area->width;
	rect.h = area->height;
	return (ft_is_mouse_in(rect, x, y));
}
