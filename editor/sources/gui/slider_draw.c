/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:39:25 by abiri             #+#    #+#             */
/*   Updated: 2019/12/23 10:35:14 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_slider.h"
#include "ttsgui_assets.h"

static double	ft_double_min_max(double value, double min, double max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

static int	ft_get_slider_position(t_gui_component *element)
{
	t_gui_slider	*slider_data;
	double			ratio;

	slider_data = element->data;
	if (!slider_data->value)
		return (0);
	*(slider_data->value) = ft_double_min_max(*(slider_data->value),
			slider_data->min, slider_data->max);
	ratio = (*(slider_data->value) - slider_data->min)
		/ (slider_data->max - slider_data->min);
	return (element->width * ratio);
}

static void	ft_draw_slider_line(t_tts_gui *gui_env, t_gui_component *element)
{
	int	x;
	int	y;
	int	value;

	y = element->y_pos + element->height / 2 - 2;
	x = element->x_pos + 1;
	ft_draw_rect(gui_env->image, (t_rect){x, y - 1, element->width - 2, 2}, 0x84888c);
	ft_draw_rect(gui_env->image, (t_rect){x - 1, y - 1, 2, 3}, 0x84888c);
	ft_draw_rect(gui_env->image, (t_rect){x + element->width - 2, y - 1, 2, 3}, 0xfcfcfc);
	ft_draw_rect(gui_env->image, (t_rect){x, y, element->width - 2, 2}, 0x0);
	ft_draw_rect(gui_env->image, (t_rect){x, y + 1, element->width - 2, 2}, 0xc0c4c8);
	ft_draw_rect(gui_env->image, (t_rect){x - 1, y + 2, element->width, 2}, 0xfcfcfc);
	value = ft_get_slider_position(element);
	ft_blit_image((t_rect){x + value - 10, y - 15, 20, 30},
			&(gui_env->assets[asset_slider_horiz]), gui_env->image);
}

void	ft_gui_slider_draw(t_tts_gui *gui_env, t_gui_component *element)
{
	t_gui_slider	*slider_data;
	t_rect			pos;

	slider_data = element->data;
	pos = (t_rect){element->x_pos, element->y_pos, element->width, element->height};
	ft_draw_slider_line(gui_env, element);
}
