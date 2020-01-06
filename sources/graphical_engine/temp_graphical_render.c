/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_graphical_render.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:23:31 by abiri             #+#    #+#             */
/*   Updated: 2020/01/06 13:11:40 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static t_point	ft_project_point(t_point center, double angle, t_point newpoint)
{
	t_point result;

	newpoint.x -= center.x;
	newpoint.y -= center.y;
	result.x = newpoint.x * cos(-angle + M_PI/2) - newpoint.y * sin(-angle + M_PI/2);
	result.y = - (newpoint.y * cos(-angle + M_PI/2) + newpoint.x * sin(-angle + M_PI/2));
	result.x += CONF_WINDOW_WIDTH / 2;
	result.y += CONF_WINDOW_HEIGHT / 2;
	return (result);
}

static int	ft_draw_sector_walls(t_sector *sector, t_graphical_scene *scene)
{
	int		color;
	t_point	p1;
	t_point	p2;
	t_point	center;
	t_wall	*wall;

	color = TEMP_RENDER_ACTIVE_WALL_COLOR;
	if (sector != scene->current_sector)
		color = TEMP_RENDER_INACTIVE_WALL_COLOR;
	sector->walls.iterator = sector->walls.first;
	center = (t_point){scene->camera.position.x, scene->camera.position.y};
	while ((wall = ttslist_iter_content(&(sector->walls))))
	{
		p1 = (t_point){wall->p1.x, wall->p1.y};
		p2 = (t_point){wall->p2.x, wall->p2.y};
		ft_sdl_image_line(scene->render_image,
				ft_project_point(center, scene->camera.angle, p1),
				ft_project_point(center, scene->camera.angle, p2),
				color);
	}
	return (SUCCESS);
}

int	temp_render_graphics(t_graphical_scene *scene)
{
	t_sector *sector;

	ft_sdl_image_rect(scene->render_image, (t_rect){0, 0, CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT},
			0x0);
	scene->sectors.iterator = scene->sectors.first;
	while ((sector = ttslist_iter_content(&(scene->sectors))))
		ft_draw_sector_walls(sector, scene);
	t_point p1;
	t_point p2;
	t_point center;
	t_vec2 movement;
	movement = ft_vector_from_angle(10, scene->camera.angle);
	p1 = (t_point){scene->camera.position.x, scene->camera.position.y};
	p2.x = p1.x +  movement.x;
	p2.y = p1.y +  movement.y;
	center = (t_point){scene->camera.position.x, scene->camera.position.y};
	ft_sdl_image_disc(scene->render_image, ft_project_point(center, scene->camera.angle, p1), 3, 0x00FFFF);
	ft_sdl_image_line(scene->render_image,
			ft_project_point(center, scene->camera.angle, p1),
			ft_project_point(center, scene->camera.angle, p2),
			0xFF00FF);
	return (SUCCESS);
}
