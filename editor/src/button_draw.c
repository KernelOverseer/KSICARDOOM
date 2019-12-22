/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 09:03:32 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 14:26:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_button.h"

static void	ft_draw_button_rectangle(t_sdl_image *image, t_rect rect,
		uint32_t color, uint32_t border_top, uint32_t border_bottom)
{
	ft_draw_rect(image, (t_rect){rect.x, rect.y + rect.height - BUTTON_BORDER, rect.width, BUTTON_BORDER}, 0x0);
	ft_draw_rect(image, (t_rect){rect.x + rect.width - BUTTON_BORDER, rect.y, BUTTON_BORDER, rect.height}, 0x0);
	ft_draw_rect(image, (t_rect){rect.x + BUTTON_BORDER, rect.y + rect.height - BUTTON_BORDER * 2, rect.width - BUTTON_BORDER * 2, BUTTON_BORDER}, border_bottom);
	ft_draw_rect(image, (t_rect){rect.x + rect.width - BUTTON_BORDER * 2, rect.y + BUTTON_BORDER, BUTTON_BORDER, rect.height - BUTTON_BORDER * 2}, border_bottom);
	ft_draw_rect(image, (t_rect){rect.x, rect.y, rect.width - BUTTON_BORDER, BUTTON_BORDER}, border_top);
	ft_draw_rect(image, (t_rect){rect.x, rect.y + BUTTON_BORDER, BUTTON_BORDER, rect.height - BUTTON_BORDER * 2}, border_top);
	ft_draw_rect(image, (t_rect){rect.x + BUTTON_BORDER, rect.y + BUTTON_BORDER, rect.width - BUTTON_BORDER * 3, rect.height - BUTTON_BORDER * 3}, color);
/*	ft_draw_rect(image, (t_rect){rect.x, rect.y, rect.width, 3}, border_top);
	ft_draw_rect(image, (t_rect){rect.x + 3, rect.y + rect.height - 3, rect.width - 3, 2}, border_bottom);
	ft_draw_rect(image, (t_rect){rect.x + 3, rect.y + 3, rect.width - 6, rect.height - 6}, color);
	ft_draw_rect(image, (t_rect){rect.x, rect.y, 3, rect.height}, border_top);
	ft_draw_rect(image, (t_rect){rect.x + rect.width - 3, rect.y + 3, 3, rect.height - 3}, border_bottom);
	ft_draw_rect(image, (t_rect){rect.x + 3, rect.y + rect.height - 1, rect.width - 3, 1}, 0x464645);*/
}

void	ft_gui_button_draw(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;
	t_rect			pos;

	button_data = button->data;
	pos = (t_rect){button->x_pos, button->y_pos, button->width, button->height};
	if (button_data->state == STATE_ACTIVE)
		ft_draw_button_rectangle(gui_env->image, pos, BUTTON_ACTIVE_COLOR, BUTTON_BORDER_BOTTOM, BUTTON_BORDER_BOTTOM);
	else if (gui_env->hovered == button)
		ft_draw_button_rectangle(gui_env->image, pos, BUTTON_HOVER_COLOR, BUTTON_BORDER_TOP, BUTTON_BORDER_BOTTOM);
	else
		ft_draw_button_rectangle(gui_env->image, pos, BUTTON_INACTIVE_COLOR, BUTTON_BORDER_TOP, BUTTON_BORDER_BOTTOM);
}
