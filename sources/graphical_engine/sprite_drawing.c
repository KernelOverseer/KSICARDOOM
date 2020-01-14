/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:20:57 by abiri             #+#    #+#             */
/*   Updated: 2020/01/14 19:45:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

void	ft_render_sprite(t_graphical_scene *scene, t_render_sprite *render)
{
	double	y_ratio;
	double	texture_y;
	int		color;

	render->texture_x = (ft_vec2_mag(ft_vec2_sub(render->wall.p1,
		render->inter->pos)) / ft_vec2_mag(ft_vec2_sub(render->wall.p1,
		render->wall.p2))) * render->wall.texture->width;
	y_ratio = ((double)render->wall.texture->height) /
		(double)(render->half_height * 2);
	texture_y = (render->render_top - render->top.y) * y_ratio;
	while (render->render_top < render->render_bottom)
	{
		color = ft_sdl_get_image_pixel(render->wall.texture,
			render->texture_x, texture_y);
		if (RGB_A(color))
			ft_sdl_image_pixel(scene->render_image, render->top.x,
				render->render_top, color);
		texture_y += y_ratio;
		render->render_top++;
	}
}

void	ft_prepare_sprite_rendering(t_graphical_scene *scene,
	t_intersect *inter, t_render_sprite *render)
{
	render->inter = inter;
	render->reverse_distance = 1.0 / inter->distance;
	render->top.x = inter->screen_x;
	render->bottom.x = inter->screen_x;
	render->half_height = ((double)inter->object.object.sprite->height / 2) *
		render->reverse_distance;
	render->center = scene->render_image->height + scene->camera.tilt
		+ (DEFAULT_WALL_HEIGHT / 2 - inter->object.object.sprite->height / 2
		- inter->object.object.sprite->altitude) * render->reverse_distance;
	render->top.y = render->center - render->half_height;
	render->bottom.y = render->center + render->half_height;
	render->render_top = ft_min(render->top.y, inter->render_min);
	render->render_bottom = ft_max(render->bottom.y, inter->render_max);
}