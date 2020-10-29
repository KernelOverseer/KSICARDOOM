/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projectile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:48:15 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 20:23:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ft_projectile_destroy(t_body *body)
{
	if (body)
	{
		if (body->player)
		{
			if (body->player->sprite)
			{
				ttslist_remove_node_with_content(&body->player->sector->sprites,
					body->player->sprite);
				free(body->player->sprite->animation.textures);
				free(body->player->sprite);
			}
			free(body->player->data);
			free(body->player);
		}
		free(body);
	}
	return (0);
}

void	ft_projectile_intersection_handler(t_body *body, t_intersect inter)
{
	t_projectile_data	*data;
	t_body				*intersected_body;

	data = body->player->data;
	printf("%p\n", data);
	if (!data)
		return ;
	if (inter.object.type == OBJECT_sprite)
	{
		if (inter.object.object.sprite->parent_type == PARENT_TYPE_BODY)
		{
			intersected_body = inter.object.object.sprite->parent;
			if (intersected_body && intersected_body != data->owner)
			{
				if (intersected_body->player->inventory.shield > 0)
				{
					intersected_body->player->inventory.shield -=
						2 * data->damage;
					if (intersected_body->player->inventory.shield < 0)
						intersected_body->player->inventory.shield = 0;
				}
				else
					intersected_body->player->inventory.health -= data->damage;
				if (intersected_body->player->inventory.health <= 0)
					ft_push_notification("+1 KILL", 100, 0xFFFFFF);
			}
			else
				return ;
		}
	}
	data->distance = 0;
}

/*
**	In here you should create a new bot,
**	which is just a body you give various properties to
*/

t_body	*ft_projectile_setup(t_doom_env *env, t_sector *sector, t_projectile_data data)
{
	t_body					*body;

	if (!(body = ft_memalloc(sizeof(t_body))))
		return (NULL);
	*body = ft_default_body(data.source);
	if (!(body->player = ft_player_construct(0)))
		return (NULL);
	if (!(body->player->data = ft_memalloc(sizeof(t_projectile_data))))
		return (NULL);
	*((t_projectile_data *)body->player->data) = data;
	body->flags ^= IS_CONTROLLED;
	body->player->sector = sector;
	ft_create_player_sprite(body->player);
	body->player->height[0] = 50;
	body->player->height[1] = 1000;
	ft_fill_player_sprite_textures(&env->main_scene, body->player,
		env->main_scene.textures_count - 8 - 12 - 60, 60);
	body->player->sprite->props = PROP_NO_CLIP;
	body->player->sprite->animation.props = 0;
	body->player->sprite->animation.type = ANIMATION_TYPE_TIME;
	body->player->sprite->animation.speed = 3;
	body->player->sprite->parent = body;
	body->player->sprite->parent_type = PARENT_TYPE_BODY;
	body->update_gravity = NULL;
	body->events.on_intersect = &ft_projectile_intersection_handler;
	ft_sound_play_track(sound_gun_shoot,
		ft_get_sound_body_distance(body), 0);
	return body;
}

t_animation	ft_load_destroy_animation(void)
{
	t_animation result;
	int			i;

	i = 0;
	ft_bzero(&result, sizeof(result));
	result.textures = ft_memalloc(sizeof(t_sdl_image *) * 12);
	while (i < 12)
	{
		result.textures[i] = &g_parsed_scene->textures[g_parsed_scene->textures_count - 8 - 12 + i];
		i++;
	}
	result.type = ANIMATION_TYPE_TIME;
	result.frame_count = 12;
	result.speed = 2;
	return (result);
}

/*
**	In here you should write the code that gets executed everytime, every frame
**	To make the bot dynamic and do various things
*/

int		ft_projectile_iter(void *e, void *b)
{
	t_doom_env			*env;
	t_body				*body;
	t_projectile_data	*data;

	env = e;
	body = b;
	data = body->player->data;
	if (data->distance <= 0)
	{
		if (data->distance == 0)
		{
			ft_sound_play_track(sound_projectile_explosion,
				ft_get_sound_body_distance(body), 0);
			body->player->sprite->animation = ft_load_destroy_animation();
		}
		else if (ft_on_animation_end(body->player->sprite->animation,
			g_doom_env->timer.current_time + 1)
			|| data->distance < -100)
			return (ft_projectile_destroy(body));
		data->distance--;
		return (1);
	}
	body->velocity = ft_vec3_scalar(data->direction, 2000);
	data->distance--;
	sync_sprite(env, body);
	ft_physics_controllers(env, body);
	return (1);
}