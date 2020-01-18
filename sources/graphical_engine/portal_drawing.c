/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:55:06 by abiri             #+#    #+#             */
/*   Updated: 2020/01/18 19:21:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

void	ft_draw_portal_top(t_graphical_scene *scene, t_render_portal *render)
{
	t_render_wall	render_top;
	t_intersect		*inter;

	inter = render->inter;
	if (render->this_sector.top.y > render->that_sector.top.y)
		render->render_top = render->this_sector.top.y;
	else
	{
		render_top.top.x = inter->screen_x;
		render_top.top.y = render->this_sector.top.y;
		render_top.bottom.y = render->that_sector.top.y;
		render_top.render_top = ft_min(render_top.top.y, inter->render_min);
		render_top.render_bottom =
			ft_max(render_top.bottom.y, inter->render_max);
		render_top.inter = inter;
		render_top.wall = &inter->object.object.portal->wall;
		render_top.half_height = render->half_height;
		ft_render_wall(scene, &render_top);
		render->render_top = render->that_sector.top.y;
	}
}

void	ft_draw_portal_bottom(t_graphical_scene *scene, t_render_portal *render)
{
	t_render_wall	render_bottom;
	t_intersect		*inter;

	inter = render->inter;
	if (render->this_sector.bottom.y > render->that_sector.bottom.y)
	{
		render_bottom.top.x = inter->screen_x;
		render_bottom.top.y = render->that_sector.bottom.y;
		render_bottom.bottom.y = render->this_sector.bottom.y;
		render_bottom.render_top =
			ft_min(render_bottom.top.y, inter->render_min);
		render_bottom.render_bottom =
			ft_max(render_bottom.bottom.y, inter->render_max);
		render_bottom.inter = inter;
		render_bottom.wall = &inter->object.object.portal->wall;
		render_bottom.half_height = render->half_height;
		ft_render_wall(scene, &render_bottom);
		render->render_bottom = render->that_sector.bottom.y;
	}
	else
		render->render_bottom = render->this_sector.bottom.y;
}

/*
static t_vec2		ft_get_pixel_position(t_graphical_scene *scene, t_render_wall *render,
	int y)
{
	double	distance;
	double	real_height;
	double	screen_height;

	real_height = fabs(DEFAULT_WALL_HEIGHT / 2 +
		render->inter->sector->ceil_height);
	screen_height = abs(render->center - y);
	distance = real_height / screen_height;
	return (ft_vec2_add(scene->camera.position,
		ft_vec2_scalar(render->inter->ray.dir, distance)));
}

void		ft_render_portal_ceiling(t_graphical_scene *scene,
 	t_render_portal *render)
{
	int		i;
	t_vec2	position;

	if (!render->inter->sector->ceil_texture)
		return ;
	i = render->top.y;
	while (i > render->inter->render_min)
	{
		position = ft_get_pixel_position(scene, render, i);
		ft_sdl_image_pixel(scene->render_image, render->inter->screen_x, i,
			ft_sdl_get_image_pixel(render->inter->sector->ceil_texture,
				position.x, position.y));
		i--;
	}
}*/

void	ft_prepare_portal_rendering(t_graphical_scene *scene,
	t_intersect *inter, t_render_portal *render)
{
	t_sector		*this_sector;
	t_sector		*that_sector;

	render->inter = inter;
	render->portal = inter->object.object.portal;
	this_sector = inter->sector;
	that_sector = inter->object.object.portal->sector;
	render->reverse_distance = 1.0 / inter->distance;
	render->center = scene->render_image->height + scene->camera.tilt;
	render->half_height = (DEFAULT_WALL_HEIGHT / 2.) * render->reverse_distance;
	render->this_sector.top.y = render->center - (DEFAULT_WALL_HEIGHT -
		scene->camera.height + this_sector->ceil_height) *
		render->reverse_distance;
	render->this_sector.bottom.y = render->center + (scene->camera.height -
		this_sector->floor_height) * render->reverse_distance;
	render->that_sector.top.y = render->center - (DEFAULT_WALL_HEIGHT -
		scene->camera.height + that_sector->ceil_height) *
		render->reverse_distance;
	render->that_sector.bottom.y = render->center + (scene->camera.height -
		that_sector->floor_height) * render->reverse_distance;
	ft_draw_portal_top(scene, render);
	ft_draw_portal_bottom(scene, render);
	render->this_sector.inter = inter;
	render->this_sector.center = render->center;
	ft_render_wall_ceiling(scene, &render->this_sector);
	inter->render_min = ft_min(render->render_top, inter->render_min);
	inter->render_max = ft_max(render->render_bottom, inter->render_max);
}
