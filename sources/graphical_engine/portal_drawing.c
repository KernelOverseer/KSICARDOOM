/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:55:06 by abiri             #+#    #+#             */
/*   Updated: 2020/01/11 17:05:07 by abiri            ###   ########.fr       */
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
	render->center = scene->render_image->height + scene->camera.tilt +
		(DEFAULT_WALL_HEIGHT / 2.0 - scene->camera.height) *
		render->reverse_distance;
	render->half_height =
		(DEFAULT_WALL_HEIGHT / 2.0) * render->reverse_distance;
	render->this_sector.top.y = render->center - render->half_height -
		this_sector->ceil_height * render->reverse_distance;
	render->this_sector.bottom.y = render->center + render->half_height -
		this_sector->floor_height * render->reverse_distance;
	render->that_sector.top.y = render->center - render->half_height -
		that_sector->ceil_height * render->reverse_distance;
	render->that_sector.bottom.y = render->center + render->half_height -
		that_sector->floor_height * render->reverse_distance;
	ft_draw_portal_top(scene, render);
	ft_draw_portal_bottom(scene, render);
	inter->render_min = ft_min(render->render_top, inter->render_min);
	inter->render_max = ft_max(render->render_bottom, inter->render_max);
}