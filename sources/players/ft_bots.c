/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:58:37 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/22 14:06:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_body	*ft_new_bot(t_sector *sector, t_vec3 pos)
{
	t_body *body;

	if (!(body = ft_memalloc(sizeof(t_body))))
		return (NULL);
	*body = ft_default_body(pos);
	body->player = ft_player_construct(42);
	if (!(body->player->sprite = ft_memalloc(sizeof(t_sprite))))
	{
		free(body->player);
		free(body);
		return (NULL);
	}
	body->flags ^= IS_CONTROLLED;
	body->player->sprite->position = (t_vec2){pos.x, pos.y};
	body->player->sprite->props = PROP_FOLLOW_ANGLE;
	body->player->sprite->radius = body->player->height[0];
	body->player->sprite->height = body->player->height[1];
	body->player->sprite->angle = acos(ft_vec3_dot_product(body->forw, RIGHT));
	body->player->sprite->altitude = pos.z;
	body->player->sprite->animation.props = PROP_FOLLOW_ANGLE;
	body->player->sprite->animation.type = ANIMATION_TYPE_DIRECTION;
	body->player->sprite->animation.textures = ft_memalloc(sizeof(t_sdl_image *) * 8);
	for (int i = 0; i < 8; i++)
	{
		body->player->sprite->animation.textures[i] = ft_memalloc(sizeof(t_sdl_image));
		*(body->player->sprite->animation.textures[i]) = g_parsed_scene->textures[g_parsed_scene->textures_count - 8 + i];
	}
	body->player->sprite->animation.frame_count = 8;
	sector->sprites.push(&(sector->sprites), body->player->sprite);
	return body;
}

void	sync_sprite(t_doom_env *env, t_body *body)
{
	double angle;
	t_vec3 cross;

	body->player->sprite->position = (t_vec2){body->pos.x, body->pos.y};
	body->player->sprite->radius = body->player->height[0];
	body->player->sprite->height = body->player->height[1];
	body->player->sprite->altitude = body->pos.z;
	angle = acos(ft_vec3_dot_product(ft_vec3_normalize(body->velocity), RIGHT));
	cross = ft_vec3_cross_product(ft_vec3_normalize(body->velocity), RIGHT);
	if (ft_vec3_dot_product(DOWN, cross) < 0)
		angle = -angle;
	body->player->sprite->angle = angle;
}

void ft_bot_input(void *env, void *body) // pass env awsell
{
	unsigned char *input;
	t_body *b;
	t_doom_env *e;

	b = (t_body *)body;
	e = (t_doom_env *)env;
	t_body *main_player_body;
	t_list_head temp_bodies;

	temp_bodies = e->bodies;
	temp_bodies.iterator = temp_bodies.first;
	while ((main_player_body = ttslist_iter_content(&temp_bodies)))
	{
		if (main_player_body->flags & IS_CONTROLLED)
			break;
	}
	/*if (main_player_body)
		b->velocity = ft_vec3_scalar(ft_vec3_normalize(ft_vec3_sub(main_player_body->pos, b->pos)), 200);*/
	b->velocity = (t_vec3){500, 0, 0};
	ft_physics_controllers(env, body);
	sync_sprite(env, body);
}
