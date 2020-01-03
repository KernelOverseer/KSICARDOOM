/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:37:48 by abiri             #+#    #+#             */
/*   Updated: 2019/12/23 09:26:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_slider.h"

void	ft_gui_slider_on_click(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_slider	*slider_data;

	(void)gui_env;
	slider_data = button->data;
	slider_data->state = STATE_ACTIVE;
/*	diff = button->event.e.button.x;
	diff -= button->x_pos;
	*(slider_data->value) = slider_data->min +
		(slider_data->max - slider_data->min) * ((double)(diff / button->width));*/
}

void	ft_gui_slider_on_hover(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_slider	*slider_data;
	int				diff;

	(void)gui_env;
	slider_data = button->data;
	if (!slider_data->value)
		return ;
	if (slider_data->state != STATE_ACTIVE)
		slider_data->state = STATE_HOVERED;
	else
	{
		diff = button->event.e.button.x - button->x_pos;
		*(slider_data->value) = slider_data->min +
			(slider_data->max - slider_data->min) * ((double)diff / (double)button->width);
	}
}

void	ft_gui_slider_on_lose_focus(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_slider	*slider_data;

	(void)gui_env;
	slider_data = button->data;
	slider_data->state = STATE_INACTIVE;
}

void	ft_gui_slider_on_release(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_slider	*slider_data;

	(void)gui_env;
	slider_data = button->data;
	slider_data->state = STATE_INACTIVE;
}
