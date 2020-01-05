/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:35:36 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 22:09:00 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	ft_draw_points(t_doom_editor *env)
{
	t_point	*point;

	env->event.points->iterator = env->event.points.start;
	while ((point = ttslist_iter(&(env->event.points))))
	{
		if (!(point.x > env->editor_canvas.width || point.x < 0
				|| points.y < 0 || point.y > env->editor_canvas.height))
			ft_sdl_image_disc(env->render_image, *point, 5, UI_COLOR_BLUE);
	}
}
