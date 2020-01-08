/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:42:09 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 23:35:29 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_calculations.h"
#include "graphics_drawing.h"

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
        intersect->object.object.wall = wall;
        intersect->object.type = OBJECT_wall;
        intersect->pos = pos;
        intersect->distance = distance;
        intersect->real_distance = distance;
        return (1);
    }
    return (0);
}

int     ft_get_ray_portal_intersect(t_ray *ray, t_portal *portal, t_intersect *intersect)
{
    if (ft_get_ray_wall_intersect(ray, &portal->wall, intersect))
    {
        intersect->object.object.portal = portal;
        intersect->object.type = OBJECT_portal;
        intersect->min_dist = intersect->distance;
        intersect->distance = INFINITY;
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

void        ft_temp_draw_wall(t_graphical_scene *scene, t_render_wall *render)
{
    render->top.y = render->render_top;
    render->bottom.y = render->render_bottom;
    temp_draw_color_wall(render->top, render->bottom, scene->render_image);
}

/*
**  OLD DIRTY VERSION UP
**  CLEAN VERSION DOWN
*/

int     ft_map_texture_y(t_vec2 real, t_vec2 screen,
    double ratio)
{
    return ((screen.x - real.x) * ratio);
}

void    ft_render_wall(t_graphical_scene *scene, t_render_wall *render)
{
    double  y_ratio;
    double  texture_y;
    int     color;

    if (!render->wall->texture)
    {
        ft_temp_draw_wall(scene, render);
        return ;
    }
    y_ratio = ((double)render->wall->texture->height / (double)(render->half_height * 2));
    texture_y = (render->render_top - render->top.y) * y_ratio;
    while (render->render_top < render->render_bottom)
    {
        color = render->wall->texture->pixels[ (((int)texture_y % render->wall->texture->height) * render->wall->texture->width) + render->texture_x];
        ft_sdl_image_pixel(scene->render_image, render->top.x, render->render_top, color);
        texture_y += y_ratio;
        render->render_top++;
    }
}

static int ft_map_texture_x(t_vec2 start, t_vec2 pos, int texture_width)
{
    t_vec2  diff;

    diff = ft_vec2_sub(pos, start);
    return ((int)ft_vec2_mag(diff) % texture_width);
}

void    ft_prepare_wall_rendering(t_graphical_scene *scene, t_intersect *inter,
    t_render_wall *render)
{
    render->inter = inter;
    render->reverse_distance = 1 / inter->distance;
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
    if (render->wall->texture)
        render->texture_x = ft_map_texture_x(inter->pos, render->wall->p1,
            render->wall->texture->width);
}

void    ft_handle_wall_intersection(t_graphical_scene *scene, t_intersect *inter)
{
    t_render_wall   wall_render;

    inter->real_distance = sqrt(inter->distance);
    inter->distance = inter->real_distance / inter->ray.dist;
    ft_prepare_wall_rendering(scene, inter, &wall_render);
    ft_render_wall(scene, &wall_render);
}

void    ft_handle_portal_intersection(t_graphical_scene *scene, t_intersect *inter)
{
    ft_intersect_ray(scene, inter, inter->object.object.portal->sector);
}

void    ft_intersect_ray(t_graphical_scene *scene, t_intersect *inter, t_sector *sector)
{
    union u_render_object   object;

    inter->object.type = 0;
    inter->sector = sector;
    sector->walls.iterator = sector->walls.first;
    sector->portals.iterator = sector->portals.first;
    while ((object.wall = ttslist_iter_content(&sector->walls)))
        ft_get_ray_wall_intersect(&inter->ray, object.wall, inter);
    while ((object.portal = ttslist_iter_content(&sector->portals)))
        ft_get_ray_portal_intersect(&inter->ray, object.portal, inter);
    if (inter->object.type == OBJECT_wall)
        ft_handle_wall_intersection(scene, inter);
        //ft_temp_draw_wall(scene, inter);
    else if (inter->object.type == OBJECT_portal)
        ft_handle_portal_intersection(scene, inter);
        //ft_intersect_ray(scene, inter, inter->object.object.portal->sector);
}