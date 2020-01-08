/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:42:09 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 20:42:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_calculations.h"

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
    if (distance < intersect->distance && distance > intersect->min_dist)
    {
        intersect->wall = wall;
        intersect->pos = pos;
        intersect->distance = distance;
        intersect->real_distance = distance;
        return (1);
    }
    return (0);
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
    result.min_dist = 0;
    result.screen_x = screen_x;
    return (result);
}

int     ft_get_ray_portal_intersect(t_ray *ray, t_portal *portal, t_intersect *intersect)
{
    if (ft_get_ray_wall_intersect(ray, &portal->wall, intersect))
    {
        intersect->wall = (t_wall *)portal;
        intersect->min_dist = intersect->distance;
        intersect->distance = INFINITY;
        return (1);
    }
    return (0);
}

void	ft_intersect_ray(t_graphical_scene *scene, t_intersect *inter, t_sector *sector, int screen_x)
{
    t_wall      *wall;
    t_portal    *portal;
    int         is_portal;
    t_ray       ray;

    is_portal = 0;
    inter->wall = NULL;
    inter->sector = sector;
    ray = scene->camera.raycast.ray;
    inter->ray = ray;
    sector->walls.iterator = sector->walls.first;
    sector->portals.iterator = sector->portals.first;
    while ((wall = ttslist_iter_content(&sector->walls)))
        ft_get_ray_wall_intersect(&ray, wall, inter);
    while ((portal = ttslist_iter_content(&sector->portals)))
        is_portal |= ft_get_ray_portal_intersect(&ray, portal, inter);
    if (is_portal)
        ft_intersect_ray(scene, inter, ((t_portal *)inter->wall)->sector, screen_x);
    else
    {
        inter->real_distance = sqrt(inter->distance);
        inter->distance = inter->real_distance / ray.dist;
        if (inter->wall)
            ft_temp_draw_wall(scene, inter);
    }
}