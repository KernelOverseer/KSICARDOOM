/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 09:03:32 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 12:18:15 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_button.h"

void	ft_gui_button_draw(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;
	t_rect			pos;
	t_sdl_image		*text_image;

	button_data = button->data;
	if (!button_data)
		return ;
	text_image = button_data->text;
	pos = (t_rect){button->x_pos, button->y_pos, button->width, button->height};
	if (button_data->state == STATE_ACTIVE || button_data->always_on)
		ft_blit_image(pos, &(gui_env->assets[asset_button_active]), gui_env->image);
	else if (gui_env->hovered == button)
		ft_blit_image(pos, &(gui_env->assets[asset_button_hover]), gui_env->image);
	else
		ft_blit_image(pos, &(gui_env->assets[asset_button]), gui_env->image);
	pos = (t_rect){button->x_pos + button->width / 2 - text_image->width / 2,
		button->y_pos + button->height / 2 - text_image->height / 2 ,
		text_image->width, text_image->height};
	ft_blit_image(pos, text_image, gui_env->image);
}
