/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_label.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:09:17 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 12:26:22 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_LABEL_H
# define GUI_LABEL_H

typedef struct	s_gui_label
{
	t_sdl_image	*text;
}				t_gui_label;

t_gui_component	*ft_gui_new_label(t_rect rect, char *text, uint32_t color, t_tts_gui *gui_env);
void			ft_gui_label_draw(t_tts_gui *gui_env, t_gui_component *label);

#endif
