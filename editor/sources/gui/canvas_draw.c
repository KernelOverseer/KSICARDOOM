/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:42:12 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 18:56:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_canvas.h"

void	ft_gui_canvas_draw(t_tts_gui *gui_env, t_gui_component *canvas)
{
	t_sdl_image	*canvas_image;
	t_rect	pos;

	canvas_image = canvas->data;
	pos = (t_rect){canvas->x_pos, canvas->y_pos, canvas->width, canvas->height};
	ft_blit_image(pos, canvas_image, gui_env->image);
	pos = (t_rect){canvas->x_pos, canvas->y_pos - 4, canvas->width, 4};
	ft_blit_image(pos, &(gui_env->assets[asset_trough_horiz]), gui_env->image);
	pos = (t_rect){canvas->x_pos + canvas->width, canvas->y_pos, 4, canvas->height};
	ft_blit_image(pos, &(gui_env->assets[asset_trough_vert]), gui_env->image);
	pos = (t_rect){canvas->x_pos - 4, canvas->y_pos, 4, canvas->height};
	ft_blit_image(pos, &(gui_env->assets[asset_trough_vert]), gui_env->image);
	pos = (t_rect){canvas->x_pos, canvas->y_pos + canvas->height, canvas->width, 4};
	ft_blit_image(pos, &(gui_env->assets[asset_trough_horiz]), gui_env->image);
}
