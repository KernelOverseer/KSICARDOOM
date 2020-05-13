/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_slider.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:13:42 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 16:49:26 by abiri            ###   ########.fr       */
/*                                                                             */
/* ************************************************************************** */

#ifndef GUI_SLIDER_H
# define GUI_SLIDER_H
# include "ttsgui.h"

typedef struct	s_gui_slider
{
	int		state;
	double	*value;
	double	min;
	double	max;
	int		is_int;
}				t_gui_slider;

void	ft_gui_slider_on_click(t_tts_gui *gui_env, t_gui_component *slider);
void	ft_gui_slider_on_hover(t_tts_gui *gui_env, t_gui_component *slider);
void	ft_gui_slider_on_lose_focus(t_tts_gui *gui_env, t_gui_component *slider);
t_gui_component	*ft_gui_new_slider(t_rect rect, double *value,
		double min, double max);
void	ft_gui_slider_draw(t_tts_gui *gui_env, t_gui_component *slider);
void	ft_gui_slider_on_release(t_tts_gui *gui_env, t_gui_component *slider);
#endif
