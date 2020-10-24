/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:58:37 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/24 14:45:18 by abiri            ###   ########.fr       */
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
	ft_create_player_sprite(body->player);
	ft_fill_player_sprite_textures(g_parsed_scene, body->player,
		g_parsed_scene->textures_count - 8, 8);
	body->player->sector = sector;
	sector->sprites.push(&(sector->sprites), body->player->sprite);
	body->player->sprite->parent = body;
	body->player->sprite->parent_type = PARENT_TYPE_BODY;
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

int	ft_bot_input(void *env, void *body) // pass env awsell
{
	static t_vec3	go_pos = {0, 0, 0};
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
	t_vec3 pos2d = (t_vec3){b->pos.x, b->pos.y, 0};
	if (main_player_body)
	{
		if (go_pos.x == 0 && go_pos.y == 0 && go_pos.z == 0)
			go_pos = (t_vec3){main_player_body->pos.x, main_player_body->pos.y, 0};
		if (ft_vec3_mag(ft_vec3_sub(go_pos, pos2d)) < 100)
			go_pos = (t_vec3){main_player_body->pos.x, main_player_body->pos.y, 0};
	}
	b->velocity = ft_vec3_scalar(ft_vec3_normalize(ft_vec3_sub(go_pos, pos2d)), 200);
	//b->velocity = (t_vec3){500, 0, 0};
	ft_physics_controllers(env, body);
	sync_sprite(env, body);
	return (1);
}
