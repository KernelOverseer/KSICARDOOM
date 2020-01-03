/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:31:21 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 08:03:04 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_checkbox.h"

void	ft_gui_checkbox_on_click(t_tts_gui *gui_env, t_gui_component *checkbox)
{
	t_gui_checkbox	*checkbox_data;

	(void)gui_env;
	checkbox_data = checkbox->data;
	checkbox_data->state = STATE_ACTIVE;
}

void	ft_gui_checkbox_on_hover(t_tts_gui *gui_env, t_gui_component *checkbox)
{
	t_gui_checkbox	*checkbox_data;

	(void)gui_env;
	checkbox_data = checkbox->data;
	if (checkbox_data->state != STATE_ACTIVE)
		checkbox_data->state = STATE_HOVERED;
}

void	ft_gui_checkbox_on_lose_focus(t_tts_gui *gui_env, t_gui_component *checkbox)
{
	t_gui_checkbox	*checkbox_data;

	(void)gui_env;
	checkbox_data = checkbox->data;
	checkbox_data->state = STATE_INACTIVE;
}

void	ft_gui_checkbox_on_release(t_tts_gui *gui_env, t_gui_component *checkbox)
{
	t_gui_checkbox	*checkbox_data;

	(void)gui_env;
	checkbox_data = checkbox->data;
	checkbox_data->state = STATE_INACTIVE;
	if (ft_is_mouse_in_component(checkbox, checkbox->event.e.button.x,
				checkbox->event.e.button.y))
		*(checkbox_data->value) ^= checkbox_data->mask;
}
