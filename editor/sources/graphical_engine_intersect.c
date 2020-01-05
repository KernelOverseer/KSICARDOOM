/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_engine_intersect.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:07:43 by abiri             #+#    #+#             */
/*   Updated: 2019/12/26 16:16:22 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"
#include "graphical_objects.h"
#include "editor.h"

static void ft_point_vector(t_vector p, t_vector *r1, t_vector p2, t_vector *r2)
{
    r1->x = p.x;
    r1->y = p.y;
    r2->x = p2.x;
    r2->y = p2.y;
}

t_vector	ft_intersect(t_ray ray, t_wall wall, int *status)
{
	t_intercalc	c;

	*status = 0;
	c.p1 = (t_vector){ray.origin.x, ray.origin.y};
	c.p2 = (t_vector){c.p1.x + ray.direction.x, c.p1.y + ray.direction.y};
	ft_point_vector(wall.p1, &c.p3, wall.p2, &c.p4);
	c.den = ((c.p1.x - c.p2.x) * (c.p3.y - c.p4.y) - (c.p1.y - c.p2.y) *
			(c.p3.x - c.p4.x));
	if (c.den == 0)
		return ((t_vector){0,0});
	c.t = ((c.p1.x - c.p3.x) * (c.p3.y - c.p4.y) - (c.p1.y - c.p3.y) *
			(c.p3.x - c.p4.x)) / c.den;
	if (c.t < 0)
		return ((t_vector){0,0});
	c.u = -((c.p1.x - c.p2.x) * (c.p1.y - c.p3.y) - (c.p1.y - c.p2.y) *
			(c.p1.x - c.p3.x)) / c.den;
	if (c.u < 0 || c.u > 1)
		return ((t_vector){0,0});
	*status = 1;
	return ((t_vector){c.p1.x + c.t * (c.p2.x - c.p1.x), c.p1.y +
				c.t * (c.p2.y - c.p1.y)});
}

int     ft_intersect_wall(t_wall *wall, t_ray *ray, t_intersect *inter)
{
    int         status;
    t_vector    newpos;
    double      distance;

    newpos = ft_intersect(*ray, *wall, &status);
    if (!status)
        return (0);
    distance = ft_vector_distance((t_point){ray->origin.x, ray->origin.y},
		newpos);
    if (distance < inter->real_distance)
    {
        inter->wall = wall;
        inter->real_distance = distance;
        inter->ray = *ray;
    }
    return (1);
}

Uint32 ft_apply_brightness(int color, double brightness)
{
	double colors[3];

	if (brightness > 1)
		brightness = 1;
	else if (brightness < 0)
		brightness = 0;
	colors[0] = ((double)RGB_R(color) / 255.0) * brightness;
	colors[1] = ((double)RGB_G(color) / 255.0) * brightness;
	colors[2] = ((double)RGB_B(color) / 255.0) * brightness;
	return ((Uint8)(colors[0] * 255) << 16 | (Uint8)(colors[1] * 255) << 8 | (Uint8)(colors[2] * 255));
}

void    ft_draw_wall(t_graphical_scene *scene, t_intersect *inter)
{
	int	upper;
	int lower;
	int	wallheight;

	inter->distance = inter->real_distance / ft_vector_size(&(inter->ray.direction));
	wallheight = DEFAULT_WALL_HEIGHT / inter->distance;
	upper = scene->render_image->height / 2 - wallheight / 2;
	lower = upper + wallheight + (inter->sector->floor_height / inter->distance);
	upper -= (inter->sector->ceil_height / inter->distance);
	Uint32 color = ft_apply_brightness(0xFF00FF, inter->sector->brightness);
	color = ft_apply_brightness(color, 1.0 - (inter->real_distance / MAX_RENDER_DISTANCE));
	if (upper != lower)
		ft_sdl_image_line(scene->render_image, (t_point){inter->screen_x, upper}, (t_point){inter->screen_x, lower}, CORRECT_COLOR(color));
}

void    ft_intersect_ray(t_graphical_scene *scene, t_raycast *raygen,
    t_sector *sector, int x)
{
    t_intersect inter;
    t_wall      *wall;

    inter.real_distance = MAX_RENDER_DISTANCE;
	inter.screen_x = x;
	inter.sector = sector;
    sector->walls.iterator = sector->walls.first;
    while ((wall = ttslist_iter_content(&(sector->walls))))
        ft_intersect_wall(wall, &(raygen->ray), &inter);
    ft_draw_wall(scene, &inter);
}
