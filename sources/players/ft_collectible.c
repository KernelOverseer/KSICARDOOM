/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:48:15 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 20:23:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ft_collectible_destroy(t_body *body)
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

void	ft_collectible_intersection_handler(t_body *body, t_intersect inter)
{
	t_body				*intersected_body;
	t_inventory			*data;

	data = body->player->data;
	printf("intersection\n");
	if (inter.object.type == OBJECT_sprite)
	{
		if (inter.object.object.sprite->parent_type == PARENT_TYPE_BODY)
		{
			intersected_body = inter.object.object.sprite->parent;
			if (intersected_body)
			{
				intersected_body->player->inventory.health = ft_max(100,
					intersected_body->player->inventory.health + data->health);
				intersected_body->player->inventory.shield = ft_max(100,
					intersected_body->player->inventory.shield + data->shield);
				intersected_body->player->inventory.ammo[0] = ft_max(100,
					intersected_body->player->inventory.ammo[0] + data->ammo[0]);
				ft_push_notification(g_doom_env->menu_manager, "Collected", 100, 0xabffdd);
				body->player->data = NULL;
			}
		}
	}
}

/*
**	In here you should create a new bot,
**	which is just a body you give various properties to
*/

t_body	*ft_collectible_setup(t_doom_env *env, t_sector *sector, t_vec3 pos,
	t_inventory data)
{
	t_body					*body;

	if (!(body = ft_memalloc(sizeof(t_body))))
		return (NULL);
	*body = ft_default_body(pos);
	if (!(body->player = ft_player_construct(0)))
		return (NULL);
	if (!(body->player->data = ft_memalloc(sizeof(t_inventory))))
		return (NULL);
	*((t_inventory *)body->player->data) = data;
	body->flags = IS_CONTROLLED;
	body->player->sector = sector;
	ft_create_player_sprite(body->player);
	body->player->height[0] = 50;
	body->player->height[1] = 1000;
	ft_fill_player_sprite_textures(&env->main_scene, body->player,
		env->main_scene.textures_count - 8 - 12 - 60, 60);
	//body->player->sprite->props = PROP_NO_CLIP;
	body->player->sprite->animation.props = 0;
	body->player->sprite->animation.type = ANIMATION_TYPE_TIME;
	body->player->sprite->animation.speed = 3;
	body->player->sprite->parent = body;
	body->player->sprite->parent_type = PARENT_TYPE_BODY;
	body->update_gravity = NULL;
	body->events.on_intersect = &ft_collectible_intersection_handler;
	return body;
}

/*
**	In here you should write the code that gets executed everytime, every frame
**	To make the bot dynamic and do various things
*/

int		ft_collectible_iter(void *e, void *b)
{
	t_doom_env			*env;
	t_body				*body;

	env = e;
	body = b;

	if (!body->player->data)
	{
		printf("DELETED\n");
		ft_collectible_destroy(b);
		return (0);
	}
	sync_sprite(env, body);
	ft_physics_controllers(env, body);
	return (1);
}