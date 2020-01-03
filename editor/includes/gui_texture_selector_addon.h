/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_texture_selector_addon.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:09:56 by abiri             #+#    #+#             */
/*   Updated: 2019/12/27 10:09:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_GUI_TEXTURE_SELECTOR_ADDON_H
# define EDITOR_GUI_TEXTURE_SELECTOR_ADDON_H
# include "ttsgui.h"
# define ICON_MIN_SIZE 50.0

typedef struct	s_gui_texture_selector
{
	int			scroll_offset;
	int 		texture_list_size;
	t_sdl_image	*texture_list;
	t_sdl_image **to_change;
}				t_gui_texture_selector;

t_gui_component	*ft_gui_new_texture_selector(t_rect rect, t_sdl_image *list,
		int size, t_sdl_image **to_change);
#endif
