/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_texture_display_addon.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:51:55 by abiri             #+#    #+#             */
/*   Updated: 2019/12/27 16:51:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_GUI_TEXTURE_DISPLAY_ADDON_H
# define EDITOR_GUI_TEXTURE_DISPLAY_ADDON_H
# include "ttsgui.h"
# include "editor.h"
# define FOCUS_BORDER_SIZE 3

t_gui_component	*ft_gui_new_texture_display(t_rect rect,
		t_sdl_image **texture_addr);
void			ft_gui_draw_texture_display(t_tts_gui	*gui_env,
		t_gui_component *component);
#endif
