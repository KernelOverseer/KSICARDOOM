/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:58:37 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/24 20:02:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** to do: make ft_bodies_input take input from different sources (keyboard, bot, conected user)
*/

int	ft_remote_client_player_input(void *env, void *body)
{
	unsigned char			*c;
	unsigned char			*k;
	t_doom_env				*e;
	t_body					*b;
	t_multiplayer_client	*client;

	e = (t_doom_env *)env;
	b = (t_body *)body;
	c =	b->player->input;
	k = e->keys;
	c[PLAYER_FORWARD]		= (k[SDL_SCANCODE_UP]) ?
			k[SDL_SCANCODE_UP] : k[SDL_SCANCODE_W];
	c[PLAYER_BACKWARDS]		= (k[SDL_SCANCODE_DOWN]) ?
			k[SDL_SCANCODE_DOWN] : k[SDL_SCANCODE_S];
	c[PLAYER_TURN_LEFT]		= k[SDL_SCANCODE_LEFT];
	c[PLAYER_TURN_RIGHT]	= k[SDL_SCANCODE_RIGHT];
	c[PLAYER_CROUCH]		= k[SDL_SCANCODE_LSHIFT];
	c[PLAYER_RUN]			= k[SDL_SCANCODE_RSHIFT];
	c[PLAYER_STRAFE_LEFT]	= k[SDL_SCANCODE_A];
	c[PLAYER_STRAFE_RIGHT]	= k[SDL_SCANCODE_D];
	c[PLAYER_JUMP]			= k[SDL_SCANCODE_SPACE];

	client = b->player->data;
	int i = 0;
	int is_moved = 0;
	SDL_GetRelativeMouseState(&b->player->mouse_rel.x, &b->player->mouse_rel.y);
	ft_memcpy(&b->player->mouse_buttons, e->mouse_buttons,
		sizeof(b->player->mouse_buttons));
	while (i < SDL_KEY_COUNT)
	{
		if (k[i])
		{
			is_moved = 1;
			break;
		}
		i++;
	}
	ft_client_sync_body_input_server(b, client);
	ft_client_sync_body_server(b, client);
	ft_client_sync_scene_server(e, client);
	sync_camera(env, body);
	e->main_inventory = b->player->inventory;
	return (1);
}

/*
** init player with NULL for non controlled bodies
*/

t_body	*ft_client_player_construct(t_vec3 pos, void *player,
	t_multiplayer_client *client)
{
	t_body *body;

	body = ft_memalloc(sizeof(t_body));
	*body = ft_default_body(pos);
	body->flags ^= ((player == NULL) ? IS_CONTROLLED : 0);
	body->player = player;
	body->player->data = client;
	ft_create_player_sprite(player);
	ft_fill_player_sprite_textures(g_parsed_scene, player,
		g_parsed_scene->textures_count - 8, 8);
	((t_player*)player)->sprite->parent = body;
	((t_player*)player)->sprite->parent_type = PARENT_TYPE_BODY;
	((t_player*)player)->inventory = (t_inventory){0, 100, 100, {20, 0, 0, 0, 0}};
	body->up.z = -CONF_WINDOW_HEIGHT / 2;
	return(body);
}
