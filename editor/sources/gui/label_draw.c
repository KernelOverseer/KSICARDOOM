/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:14:06 by abiri             #+#    #+#             */
/*   Updated: 2020/05/15 00:17:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_label.h"

void	ft_gui_label_draw(t_tts_gui *gui_env, t_gui_component *label)
{
	t_gui_label *label_data;
	t_rect		rect;

	label_data = label->data;
	rect.w = label_data->text->width;
	rect.h = label_data->text->height;
	rect.x = label->x_pos + label->width / 2 - rect.w / 2;
	rect.y = label->y_pos + label->height / 2 - rect.h / 2;
	ft_blit_image(rect, label_data->text, gui_env->image);
}
