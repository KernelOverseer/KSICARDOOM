/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_engine_render.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 22:17:32 by abiri             #+#    #+#             */
/*   Updated: 2019/12/26 16:18:26 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"
#include "graphical_objects.h"
#include "editor.h"
#include "centropy.h"
#include <math.h>

void    ft_fill_raycast_data(t_camera *camera)
{
    t_raycast *raygen;

    raygen = &(camera->raycast);
    raygen->ray.origin = camera->position;
    raygen->plane = ft_vector_from_angle(PROJECTION_PLANE / 2, camera->angle + M_PI / 2);
    raygen->direction = ft_vector_from_angle(PROJECTION_DISTANCE, camera->angle);
    raygen->swipe.x = -raygen->plane.x;
    raygen->swipe.y = -raygen->plane.y;
    ft_normalise_vector(&(raygen->swipe));
    raygen->ray.direction.x = raygen->direction.x + raygen->plane.x;
    raygen->ray.direction.y = raygen->direction.y + raygen->plane.y;
    raygen->ray.distance = 0;
    raygen->render_min = 0;
}

void    ft_iter_ray(t_raycast *raygen, int render_max)
{
    raygen->plane.x += raygen->swipe.x * CONFIG_RES_RATIO;
    raygen->plane.y += raygen->swipe.y * CONFIG_RES_RATIO;
    raygen->ray.direction.x = raygen->direction.x + raygen->plane.x;
    raygen->ray.direction.y = raygen->direction.y + raygen->plane.y;
    raygen->ray.distance = 0;
    raygen->render_min = 0;
    raygen->render_max = render_max;
}

void    ft_render_scene(t_graphical_scene *scene)
{
    t_raycast   *raygen;
    int         x;

    raygen = &(scene->camera.raycast);
    ft_bzero(raygen, sizeof(t_raycast));
    ft_sdl_image_rect(scene->render_image, (t_rect){0, 0, scene->render_image->width, scene->render_image->height}, CORRECT_COLOR(0x0));
    ft_fill_raycast_data(&(scene->camera));
    raygen->render_max = scene->render_image->height;
    t_point lookat;
    lookat.x = scene->camera.position.x + raygen->ray.direction.x;
    lookat.y = scene->camera.position.y + raygen->ray.direction.y;
    x = 0;
    while (x < PROJECTION_PLANE)
    {
        ft_intersect_ray(scene, raygen, scene->current_sector, x);
        ft_iter_ray(raygen, scene->render_image->height);
        x += CONFIG_RES_RATIO;
    }
}
