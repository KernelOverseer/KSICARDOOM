/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 08:54:00 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 11:50:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_BUTTON_H
# define GUI_BUTTON_H
# include "ttsgui.h"
# include "gui_button.h"
# define BUTTON_BORDER 3
# define BUTTON_INACTIVE_COLOR 0xc0c4c8
# define BUTTON_ACTIVE_COLOR 0xc0c4c8
# define BUTTON_HOVER_COLOR 0xc0c4c8
# define BUTTON_BORDER_TOP 0xfcfcfc
# define BUTTON_BORDER_BOTTOM 0x84888c

typedef	void	t_button_handler(void *arg, t_gui_component *button);

typedef struct	s_gui_button
{
	int					state;
	int					always_on;
	t_sdl_image			*text;
	t_button_handler	*handler;
	void				*arg;
}				t_gui_button;

void	ft_gui_button_on_click(t_tts_gui *gui_env, t_gui_component *button);
void	ft_gui_button_on_hover(t_tts_gui *gui_env, t_gui_component *button);
void	ft_gui_button_on_lose_focus(t_tts_gui *gui_env, t_gui_component *button);
t_gui_component	*ft_gui_new_button(t_rect rect, t_sdl_image *text,
		t_button_handler *handler, void *arg);
void	ft_gui_button_draw(t_tts_gui *gui_env, t_gui_component *button);
void	ft_gui_button_on_release(t_tts_gui *gui_env, t_gui_component *button);
#endif
