/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:53:01 by abiri             #+#    #+#             */
/*   Updated: 2020/01/16 15:42:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

int	ft_draw_default_sky(t_graphical_scene *scene)
{
	ft_sdl_image_rect(scene->render_image, (t_rect){0, 0,
		scene->render_image->width,
		scene->render_image->height + scene->camera.tilt},
		0x0);
	return (ERROR);
}

int	ft_draw_skybox(t_graphical_scene *scene)
{
	int	texture_start;
	int	x;
	int	y;
	int	center;

	if (!scene->skybox)
		return (ft_draw_default_sky(scene));
	texture_start = (-scene->camera.angle / (2 * M_PI)) * scene->skybox->width;
	center = scene->render_image->height + scene->camera.tilt;
	y = center;
	while (--y >= 0)
	{
		x = scene->render_image->width;
		while (--x >= 0)
		{
			ft_sdl_image_pixel(scene->render_image, x, y,
				ft_sdl_get_image_pixel(scene->skybox, texture_start + x,
				scene->skybox->height - (center - y)));
		}
	}
	return (SUCCESS);
}