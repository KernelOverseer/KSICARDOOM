/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_checkbox.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:29:11 by abiri             #+#    #+#             */
/*   Updated: 2019/12/23 18:32:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CHECKBOX_H
# define GUI_CHECKBOX_H
# include "ttsgui.h"
# define CHECKBOX_SIZE 24

typedef struct	s_gui_checkbox
{
	int			state;
	uint32_t	*value;
	uint32_t	mask;
}				t_gui_checkbox;

void	ft_gui_checkbox_draw(t_tts_gui *gui_env, t_gui_component *component);
t_gui_component	*ft_gui_new_checkbox(t_rect rect, uint32_t *value, uint32_t mask);
void	ft_gui_checkbox_on_click(t_tts_gui *gui_env, t_gui_component *checkbox);
void	ft_gui_checkbox_on_hover(t_tts_gui *gui_env, t_gui_component *checkbox);
void	ft_gui_checkbox_on_lose_focus(t_tts_gui *gui_env, t_gui_component *checkbox);
void	ft_gui_checkbox_on_release(t_tts_gui *gui_env, t_gui_component *checkbox);
#endif
