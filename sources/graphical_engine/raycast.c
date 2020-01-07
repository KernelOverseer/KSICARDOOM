/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:20:54 by abiri             #+#    #+#             */
/*   Updated: 2020/01/07 20:00:30 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "libgl.h"
#include "config.h"
#include "centropy.h"

void	ft_init_raycasting(t_raycast *raygen, double angle)
{
	raygen->plane = ft_vec2_from_angle((double)PROJECTION_PLANE / 2.0,
			angle + M_PI / 2.0);
	raygen->direction = ft_vec2_from_angle(PROJECTION_DISTANCE, angle);
    raygen->swipe.x = -raygen->plane.x / (CONF_WINDOW_WIDTH / 2);
	raygen->swipe.y = -raygen->plane.y / (CONF_WINDOW_WIDTH / 2);
    //raygen->swipe = ft_vec2_normalize(raygen->swipe);
	raygen->ray.dir.x = raygen->direction.x + raygen->plane.x;
	raygen->ray.dir.y = raygen->direction.y + raygen->plane.y;
	raygen->ray.dist = 0;
	raygen->render_min = 0;
}

void	ft_iter_ray(t_raycast *raygen, int render_max)
{
	raygen->plane.x += raygen->swipe.x * CONFIG_RES_RATIO;
	raygen->plane.y += raygen->swipe.y * CONFIG_RES_RATIO;
	raygen->ray.dir.x = raygen->direction.x + raygen->plane.x;
	raygen->ray.dir.y = raygen->direction.y + raygen->plane.y;
	raygen->ray.dist = ft_vec2_mag(raygen->ray.dir);
	raygen->render_min = 0;
	raygen->render_max = render_max;
}

int     ft_get_ray_wall_intersect(t_ray *ray, t_wall *wall, t_intersect *intersect)
{
    t_vec2      origin_inter;
    t_vec2      pos;
    int         status;
    double      distance;

    pos = ft_intersect(*ray, *wall, &status);
    if (!status)
        return (0);
    origin_inter = (t_vec2){pos.x - ray->origin.x,
        pos.y - ray->origin.y};
    distance = origin_inter.x * origin_inter.x +
        origin_inter.y * origin_inter.y;
    if (distance < intersect->distance)
    {
        intersect->wall = wall;
        intersect->pos = pos;
        intersect->distance = distance;
        intersect->real_distance = distance;
    }
    return (1);
}

void    temp_draw_color_wall(t_point top, t_point bottom, t_sdl_image *render_image)
{
    int i;
    
    i = top.y;
    while (i < bottom.y)
    {
        ft_sdl_image_pixel(render_image, top.x, i, 0xFF00FF);
        i++;
    }
}

void        ft_temp_draw_wall(t_graphical_scene *scene, t_intersect *intersect)
{
    t_point top;
    t_point bottom;
    int wallheight;
    int center;

    center = scene->render_image->height / 2;
    wallheight = DEFAULT_WALL_HEIGHT / intersect->distance;
    top.y = center - wallheight / 2;
    bottom.y = top.y + wallheight;
    top.y = ft_min(top.y, 0);
    bottom.y = ft_max(bottom.y, scene->render_image->height);
    top.x = intersect->screen_x;
    bottom.x = intersect->screen_x;
    temp_draw_color_wall(top, bottom, scene->render_image);
}

t_intersect ft_init_intersect(t_sector *sector, t_raycast *raycast, int screen_x)
{
    t_intersect result;

    result.wall = NULL;
    result.sector = sector;
    result.render_min = raycast->render_min;
    result.render_max = raycast->render_max;
    result.distance = INFINITY;
    result.screen_x = screen_x;
    return (result);
}

void	ft_intersect_ray(t_graphical_scene *scene, t_sector *sector, int screen_x)
{
    t_wall      *wall;
    t_ray       ray;
    t_intersect inter;

    ray = scene->camera.raycast.ray;
    inter = ft_init_intersect(sector, &(scene->camera.raycast), screen_x);
    inter.ray = ray;
    sector->walls.iterator = sector->walls.first;
    while ((wall = ttslist_iter_content(&sector->walls)))
        ft_get_ray_wall_intersect(&ray, wall, &inter);
    inter.real_distance = sqrt(inter.distance);
    inter.distance = inter.real_distance / ray.dist;
    if (inter.wall)
        ft_temp_draw_wall(scene, &inter);
}

void	ft_raycast(t_graphical_scene *env)
{
	t_raycast	*raygen;
	int			x;

    raygen = &(env->camera.raycast);
	ft_bzero(raygen, sizeof(t_raycast));
	raygen->ray.origin = env->camera.position;
	ft_init_raycasting(raygen, env->camera.angle);
	raygen->render_max = env->render_image->height;
	x = 0;
	while (x < env->render_image->width)
	{
		ft_intersect_ray(env, env->current_sector, x);
		ft_iter_ray(raygen, env->render_image->height);
		x += CONFIG_RES_RATIO;
	}
}