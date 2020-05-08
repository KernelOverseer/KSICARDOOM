/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_int_label_addon.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:21:45 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 04:16:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_INT_LABEL_ADDON_H
# define GUI_INT_LABEL_ADDON_H
# include "ttsgui.h"
# include "editor.h"
# include "graphical_objects.h"

typedef struct  s_gui_int_label
{
    t_sector        **sector;
    int             last_value;
    t_sdl_image     *text_image;
    t_doom_editor   *env;
}               t_gui_int_label;

t_gui_component *ft_gui_new_int_label(t_rect rect, t_sector **sector, t_doom_editor *env);
void            ft_gui_draw_int_label(t_tts_gui *gui_env, t_gui_component *component);
#endif