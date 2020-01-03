/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_canvas.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:34:37 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 11:49:17 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CANVAS_H
# define GUI_CANVAS_H
# include "ttsgui.h"

t_gui_component	*ft_gui_new_canvas(t_rect rect, t_sdl_image *image);
void	ft_gui_canvas_draw(t_tts_gui *gui_env, t_gui_component *canvas);

#endif
