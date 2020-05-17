/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_texture_selector_addon.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:09:56 by abiri             #+#    #+#             */
/*   Updated: 2020/05/15 01:13:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_GUI_TEXTURE_SELECTOR_ADDON_H
# define EDITOR_GUI_TEXTURE_SELECTOR_ADDON_H
# include "ttsgui.h"
# define ICON_MIN_SIZE 50.0
# define SCROLL_RECT_WIDTH 10

typedef struct	s_gui_texture_selector
{
	int			scroll_offset;
	int 		texture_list_size;
	t_sdl_image	*texture_list;
	t_sdl_image **to_change;
}				t_gui_texture_selector;

/*
**	CONSTRUCTOR
*/

t_gui_component	*ft_gui_new_texture_selector(t_rect rect, t_sdl_image *list,
		int size, t_sdl_image **to_change);

/*
**	PRIVATE
*/

void			ft_gui_texture_selector_on_scroll(t_tts_gui *gui_env,
		t_gui_component *component);
void			ft_gui_texture_scroll_bar(t_gui_texture_selector *data,
		t_gui_component *component, t_tts_gui *gui_env);
int				ft_scroll_textures_selector(t_gui_component *component,
		t_point	mouse_position);
void			ft_gui_texture_selector_on_hover(t_tts_gui *gui_env,
		t_gui_component *component);
#endif
