/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   intersect_ray.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: abiri <abiri@student.1337.ma>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/08 20:42:09 by abiri			 #+#	#+#			 */
/*   Updated: 2020/01/09 19:09:45 by abiri			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "graphical_engine.h"

int		ft_get_ray_wall_intersect(t_ray *ray, t_wall *wall,
	t_intersect *intersect)
{
	t_vec2	origin_inter;
	t_vec2	pos;
	int		status;
	double	distance;

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

int		ft_get_ray_sprite_intersect(t_graphical_scene *scene, t_ray *ray,
	t_sprite *sprite, t_intersect *inter)
{
	t_wall			sprite_wall;
	t_vec2			sprite_corner_vector;

	sprite_corner_vector = ft_vec2_from_angle(sprite->radius,
		scene->camera.angle + HALF_PI);
	sprite_wall.p1 = ft_vec2_add(sprite->position, sprite_corner_vector);
	sprite_wall.p2 = ft_vec2_sub(sprite->position, sprite_corner_vector);
	if (ft_get_ray_wall_intersect(ray, &sprite_wall, inter))
	{
		inter->object.object.sprite = sprite;
		inter->object.type = OBJECT_sprite;
		return (1);
	}
	return (0);
}

int		ft_get_ray_portal_intersect(t_ray *ray, t_portal *portal,
	t_intersect *intersect)
{
	if (ft_get_ray_wall_intersect(ray, &portal->wall, intersect))
	{
		intersect->object.object.portal = portal;
		intersect->object.type = OBJECT_portal;
		return (1);
	}
	return (0);
}

void	ft_handle_wall_intersection(t_graphical_scene *scene,
	t_intersect *inter)
{
	t_render_wall	wall_render;

	inter->real_distance = sqrt(inter->distance);
	inter->distance = inter->real_distance / inter->ray.dist;
	ft_prepare_wall_rendering(scene, inter, &wall_render);
	ft_render_wall(scene, &wall_render);
	ft_render_wall_ceiling(scene, &wall_render);
}

void	ft_handle_portal_intersection(t_graphical_scene *scene,
	t_intersect *inter)
{
	t_render_portal	render;

	inter->distance = sqrt(inter->distance) / inter->ray.dist;
	ft_prepare_portal_rendering(scene, inter, &render);
	inter->distance = INFINITY;
	ft_intersect_ray(scene, inter, inter->object.object.portal->sector);
	ft_handle_intersect(scene, inter);
}

int			ft_get_animation_angle(t_graphical_scene *scene,
	t_sprite *sprite)
{
	double	percent;
	int		frame;

	percent = scene->camera.angle / (2 * M_PI);
	frame = (int)(percent * sprite->animation.frame_count) %
		sprite->animation.frame_count;
	if (frame < 0)
		frame = sprite->animation.frame_count + frame - 1;
	return (frame % sprite->animation.frame_count);
}

t_sdl_image	*ft_get_animation_texture(t_graphical_scene *scene,
	t_sprite *sprite)
{
	t_sdl_image	*result;
	t_animation *animation;

	animation = &sprite->animation;
	if (animation->type == ANIMATION_TYPE_DIRECTION)
		result = animation->textures[ft_get_animation_angle(scene, sprite)];
	else if (animation->type == ANIMATION_TYPE_TIME)
		result = animation->textures[(int)animation->current_frame];
	else
		return (NULL);
	if (animation->type == ANIMATION_TYPE_TIME
		&& animation->now_time != (uint32_t)scene->frame_count)
	{
		animation->current_frame += animation->speed;
		if (animation->current_frame > animation->frame_count - 1)
			animation->current_frame = 0;
		animation->now_time = scene->frame_count;
	}
	return (result);
}

void	ft_handle_sprite_intersection(t_graphical_scene *scene,
	t_intersect *inter)
{
	t_render_sprite render;
	t_sprite		*sprite;
	t_intersect		new_inter;
	t_wall			sprite_wall;
	t_vec2			sprite_corner_vector;

	new_inter = ft_init_intersect(inter->sector,
		&scene->camera.raycast, inter->screen_x);
	new_inter.render_min = inter->render_min;
	new_inter.render_max = inter->render_max;
	new_inter.min_dist = inter->min_dist;
	ft_intersect_ray(scene, &new_inter, inter->sector);
	ft_handle_intersect(scene, &new_inter);

	sprite = inter->object.object.sprite;
	sprite_corner_vector = ft_vec2_from_angle(sprite->radius,
		scene->camera.angle + HALF_PI);
	tts_bzero(&sprite_wall, sizeof(sprite_wall));
	sprite_wall.p1 = ft_vec2_add(sprite->position, sprite_corner_vector);
	sprite_wall.p2 = ft_vec2_sub(sprite->position, sprite_corner_vector);
	sprite_wall.props = 0;
	sprite_wall.texture = ft_get_animation_texture(scene, sprite);
	inter->distance = sqrt(inter->real_distance) / inter->ray.dist;
	ft_prepare_sprite_rendering(scene, inter, &render);
	render.wall = sprite_wall;
	ft_render_sprite(scene, &render);
}

void	ft_handle_intersect(t_graphical_scene *scene, t_intersect *inter)
{
	if (inter->object.type == OBJECT_wall)
		ft_handle_wall_intersection(scene, inter);
	else if (inter->object.type == OBJECT_portal)
		ft_handle_portal_intersection(scene, inter);
	else if (inter->object.type == OBJECT_sprite)
		ft_handle_sprite_intersection(scene, inter);
}

void	ft_intersect_ray(t_graphical_scene *scene, t_intersect *inter,
	t_sector *sector)
{
	union u_render_object	object;

	inter->object.type = 0;
	inter->sector = sector;
	sector->walls.iterator = sector->walls.first;
	sector->portals.iterator = sector->portals.first;
	sector->sprites.iterator = sector->sprites.first;
	while ((object.wall = ttslist_iter_content(&sector->walls)))
		ft_get_ray_wall_intersect(&inter->ray, object.wall, inter);
	while ((object.portal = ttslist_iter_content(&sector->portals)))
		ft_get_ray_portal_intersect(&inter->ray, object.portal, inter);
	while ((object.sprite = ttslist_iter_content(&sector->sprites)))
		ft_get_ray_sprite_intersect(scene, &inter->ray, object.sprite, inter);
	inter->min_dist = inter->distance;
}
