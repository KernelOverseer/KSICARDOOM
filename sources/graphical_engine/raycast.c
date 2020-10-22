/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:20:54 by abiri             #+#    #+#             */
/*   Updated: 2020/10/22 13:52:20 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "libgl.h"
#include "config.h"
#include "centropy.h"

t_intersect ft_init_intersect(t_sector *sector, t_raycast *raycast, int screen_x)
{
    t_intersect result;

    result.object.object.wall = NULL;
    result.object.type = 0;
    result.ray = raycast->ray;
    result.sector = sector;
    result.render_min = raycast->render_min;
    result.render_max = raycast->render_max;
    result.distance = INFINITY;
    result.min_dist = 0;
    result.screen_x = screen_x;
    return (result);
}

void	ft_init_raycasting(t_raycast *raygen, t_graphical_scene *env)
{
    raygen->ray.origin = env->camera.position;
	raygen->plane = ft_vec2_from_angle((double)PROJECTION_PLANE / 2.0,
			env->camera.angle + M_PI / 2.0);
	raygen->direction = ft_vec2_from_angle(PROJECTION_DISTANCE,
            env->camera.angle);
    raygen->swipe.x = -raygen->plane.x / (CONF_WINDOW_WIDTH / 2);
	raygen->swipe.y = -raygen->plane.y / (CONF_WINDOW_WIDTH / 2);
	raygen->ray.dir.x = raygen->direction.x + raygen->plane.x;
	raygen->ray.dir.y = raygen->direction.y + raygen->plane.y;
    raygen->iter = (t_vec2){0, 0};
	raygen->ray.dist = 0;
}

void	ft_iter_ray(t_raycast *raygen, t_graphical_scene *env)
{
	raygen->plane.x += raygen->swipe.x * env->resolution_ratio;
	raygen->plane.y += raygen->swipe.y * env->resolution_ratio;
	raygen->ray.dir.x = raygen->direction.x + raygen->plane.x;
	raygen->ray.dir.y = raygen->direction.y + raygen->plane.y;
	raygen->ray.dist = ft_vec2_mag(raygen->ray.dir);
	raygen->render_min = 0;
	raygen->render_max = env->render_image->height;
}

void	ft_raycast(t_graphical_scene *env)
{
	t_raycast	*raygen;
    t_intersect inter;
	int			x;

    raygen = &(env->camera.raycast);
	ft_init_raycasting(raygen, env);
	x = 0;
	while (x < env->render_image->width)
	{
        inter = ft_init_intersect(env->current_sector, &(env->camera.raycast), x);
        raygen->ray.screen_x = x;
		ft_intersect_ray(env, &inter, env->current_sector);
		ft_handle_intersect(env, &inter);
		ft_iter_ray(raygen, env);
		x += env->resolution_ratio;
	}
}
