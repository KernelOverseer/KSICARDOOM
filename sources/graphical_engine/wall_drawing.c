/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:23:33 by abiri             #+#    #+#             */
/*   Updated: 2020/01/14 19:18:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

static void	ft_draw_color_wall(t_graphical_scene *scene, t_render_wall *render)
{
	int i;

	i = render->render_top;
	while (i < render->render_bottom)
	{
		ft_sdl_image_pixel(scene->render_image,
			render->top.x, i, DEFAULT_WALL_COLOR);
		i++;
	}
}

static int	ft_map_texture_x(t_vec2 start, t_vec2 pos, int texture_width)
{
	t_vec2	diff;

	diff = ft_vec2_sub(pos, start);
	return ((int)ft_vec2_mag(diff) % texture_width);
}

void		ft_render_wall(t_graphical_scene *scene, t_render_wall *render)
{
	double	y_ratio;
	double	texture_y;
	int		color;

	if (!render->wall->texture)
	{
		ft_draw_color_wall(scene, render);
		return ;
	}
	render->texture_x = ft_map_texture_x(render->inter->pos, render->wall->p1,
		render->wall->texture->width);
	y_ratio = ((double)render->wall->texture->height /
		(double)(render->half_height * 2));
	texture_y = (render->render_top - render->top.y) * y_ratio;
	while (render->render_top < render->render_bottom)
	{
		color = ft_sdl_get_image_pixel(render->wall->texture,
			render->texture_x, texture_y);
		if (RGB_A(color))
			ft_sdl_image_pixel(scene->render_image, render->top.x,
				render->render_top, color);
		texture_y += y_ratio;
		render->render_top++;
	}
}

void		ft_prepare_wall_rendering(t_graphical_scene *scene,
	t_intersect *inter, t_render_wall *render)
{
	render->inter = inter;
	render->reverse_distance = 1.0 / inter->distance;
	render->top.x = inter->ray.screen_x;
	render->bottom.x = inter->ray.screen_x;
	render->center = scene->render_image->height + scene->camera.tilt +
	(DEFAULT_WALL_HEIGHT / 2 - scene->camera.height) * render->reverse_distance;
	render->half_height = ((double)DEFAULT_WALL_HEIGHT / 2) *
		render->reverse_distance;
	render->top.y = render->center - render->half_height -
		inter->sector->ceil_height * render->reverse_distance;
	render->bottom.y = render->center + render->half_height -
		inter->sector->floor_height * render->reverse_distance;
	render->wall = inter->object.object.wall;
	render->render_top = ft_min(render->top.y, inter->render_min);
	render->render_bottom = ft_max(render->bottom.y, inter->render_max);
}
