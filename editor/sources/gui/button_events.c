/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 09:11:03 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 11:50:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_button.h"

void	ft_gui_button_on_click(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;

	(void)gui_env;
	button_data = button->data;
	button_data->state = STATE_ACTIVE;
}

void	ft_gui_button_on_hover(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;

	(void)gui_env;
	button_data = button->data;
	if (button_data->state != STATE_ACTIVE)
		button_data->state = STATE_HOVERED;
}

void	ft_gui_button_on_lose_focus(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;

	(void)gui_env;
	button_data = button->data;
	button_data->state = STATE_INACTIVE;
}

void	ft_gui_button_on_release(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;

	(void)gui_env;
	button_data = button->data;
	button_data->state = STATE_INACTIVE;
	if (ft_is_mouse_in_component(button, button->event.e.button.x,
				button->event.e.button.y) && button_data->handler)
		button_data->handler(button_data->arg, button);
}
