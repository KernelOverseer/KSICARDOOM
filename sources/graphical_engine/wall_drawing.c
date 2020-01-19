/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:23:33 by abiri             #+#    #+#             */
/*   Updated: 2020/01/16 16:56:13 by abiri            ###   ########.fr       */
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

// void		ft_render_wall_ceiling(t_graphical_scene *scene,
// 	t_render_wall *render)
// {

// }

void		ft_render_wall_ground(t_graphical_scene *scene,
	t_render_wall *render)
{
	t_vec2	ground_pos;
	int		size;
	int		i;
	double	percent;

	// if (render->bottom.x != scene->render_image->width / 2)
	// 	return ;
	// printf("render_max %d | render_bottom %d | distance %f | inter_p(%f, %f) | player at (%f, %f) | whitepixels size: %d\n",//ground: x: %f y: %f
	// render->inter->render_max, render->render_bottom, render->inter->real_distance, render->inter->pos.x, render->inter->pos.y, scene->camera.position.x, scene->camera.position.y, render->inter->render_max - render->render_bottom);
	
	size = render->inter->render_max - render->render_bottom;
	i = render->render_bottom;
	while (i < render->inter->render_max)
	{
		percent = 1.0 - (double)(i - render->render_bottom) / size;
		// double dist = ft_vec2_mag(ft_vec2_sub(scene->camera.position, render->inter->pos));
		// double size_over_dist = (double)size / dist;
		// printf("dist (%f) | size_over_dist (%f)\n", dist, size_over_dist);
		ground_pos.x = lerp(scene->camera.position.x, render->inter->pos.x, percent);
		ground_pos.y = lerp(scene->camera.position.y, render->inter->pos.y, percent);
		// if (percent == 0.5)
		// 	printf("%12f\n", ft_vec2_mag(ft_vec2_sub(ground_pos, scene->camera.position)) - ft_vec2_mag(ft_vec2_sub(render->inter->pos, ground_pos)));
		// if (i == render->inter->render_max - 2)
		// 	printf("player at (%11f, %11f) | ground pos x: %11f y: %11f | inter_p(%11f, %11f) \n", scene->camera.position.x, scene->camera.position.y, ground_pos.x, ground_pos.y, render->inter->pos.x, render->inter->pos.y);
		ft_sdl_image_pixel(scene->render_image, render->bottom.x, i++, ft_sdl_get_image_pixel(render->wall->texture, ground_pos.x, ground_pos.y));
		// SDL_Delay(500);
	}
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
	ft_render_wall_ground(scene, render);
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
