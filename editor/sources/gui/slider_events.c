/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:37:48 by abiri             #+#    #+#             */
/*   Updated: 2020/05/13 02:36:42 by abiri            ###   ########.fr       */
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
	float			final_value;

	(void)gui_env;
	slider_data = button->data;
	if (!slider_data->value)
		return ;
	if (slider_data->state != STATE_ACTIVE)
		slider_data->state = STATE_HOVERED;
	else
	{
		diff = button->event.e.button.x - button->x_pos;
		final_value = slider_data->min + (slider_data->max - slider_data->min)
			* ((double)diff / (double)button->width);
		if (!slider_data->is_int)
			*(slider_data->value) = final_value;
		else
			*((int *)slider_data->value) = (int)round(final_value);
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
