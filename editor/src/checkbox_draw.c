/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:48:37 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 14:55:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_checkbox.h"

static void	ft_gui_draw_miniline(t_sdl_image *image, int x, int y, int color)
{
	ft_sdl_image_pixel(image, x, y - 1, color);
	ft_sdl_image_pixel(image, x, y, color);
	ft_sdl_image_pixel(image, x, y + 1, color);
	ft_sdl_image_pixel(image, x, y + 2, color);
}

static void	ft_gui_draw_check(t_sdl_image *image, int x, int y)
{
	ft_gui_draw_miniline(image, x - 3, y - 1, 0x0);
	ft_gui_draw_miniline(image, x - 2, y, 0x0);
	ft_gui_draw_miniline(image, x - 1, y + 1, 0x0);
	ft_gui_draw_miniline(image, x, y, 0x0);
	ft_gui_draw_miniline(image, x + 1, y - 1, 0x0);
	ft_gui_draw_miniline(image, x + 2, y - 2, 0x0);
	ft_gui_draw_miniline(image, x + 3, y - 3, 0x0);
}

static void	ft_gui_checkbox_inactive(t_sdl_image *image, t_rect rect, uint32_t color)
{
	rect.width = 24;
	rect.height = 24;
	ft_draw_rect(image, (t_rect){rect.x, rect.y, rect.width - 2, 2}, 0x84888c);
	ft_draw_rect(image, (t_rect){rect.x, rect.y, 2, rect.height - 2}, 0x84888c);
	ft_draw_rect(image, (t_rect){rect.x + rect.width - 2, rect.y, 2, rect.height}, 0xfcfcfc);
	ft_draw_rect(image, (t_rect){rect.x, rect.y + rect.height - 2, rect.width - 2, 2}, 0xfcfcfc);
	ft_draw_rect(image, (t_rect){rect.x + 2, rect.y + rect.height - 4, rect.width - 4, 2}, 0xc0c4c8);
	ft_draw_rect(image, (t_rect){rect.x + rect.width - 4, rect.y + 2, 2, rect.height - 4}, 0xc0c4c8);
	ft_draw_rect(image, (t_rect){rect.x + 2, rect.y + 2, rect.width - 6, 2}, 0x0);
	ft_draw_rect(image, (t_rect){rect.x + 2, rect.y + 4, 2, rect.height - 8}, 0x0);
	ft_draw_rect(image, (t_rect){rect.x + 4, rect.y + 4, rect.width - 8, rect.height - 8}, color);
}

static void	ft_gui_checkbox_checked(t_sdl_image *image, t_rect rect, uint32_t color)
{
	rect.width = 24;
	rect.height = 24;
	ft_gui_checkbox_inactive(image, rect, color);
	ft_gui_draw_check(image, rect.x + rect.width / 2, rect.y + rect.height / 2);
}

static int	ft_check_checkbox_status(uint32_t value, uint32_t mask)
{
	return (value & mask);
}

void	ft_gui_checkbox_draw(t_tts_gui *gui_env, t_gui_component *component)
{
	t_gui_checkbox *checkbox;
	uint32_t		color;

	checkbox = component->data;
	if (checkbox->state == STATE_ACTIVE)
		color = gui_env->background_color;
	else
		color = 0xfcfcfc;
	if (ft_check_checkbox_status(*(checkbox->value), checkbox->mask))
		ft_gui_checkbox_checked(gui_env->image, (t_rect){component->x_pos,
				component->y_pos, component->width, component->height},
				color);
	else
		ft_gui_checkbox_inactive(gui_env->image, (t_rect){component->x_pos,
				component->y_pos, component->width, component->height},
				color);
}
