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

int	ft_remote_server_player_input(void *env, void *body)
{
	unsigned char	*c;
	t_doom_env		*e;
	t_body			*b;
	t_multiplayer_remote_client	*client;
	
	e = (t_doom_env *)env;
	b = (t_body *)body;
	c =	b->player->input;

	client = b->player->data;
	ft_bzero(b->player->input, sizeof(b->player->input));
	ft_server_sync_body_input_client(b, client);
	fsync(client->socket_fd);
	
	if (b->player->mouse_rel.x != 0)
	{
		b->forw = ft_vec3_rotate_z(b->forw, -b->player->mouse_rel.x * MOUSE_HORIZONTAL_SENSITIVITY);
		b->right = ft_vec3_cross_product(b->forw, UP);
	}
	if (b->player->mouse_rel.y != 0)
	{
		b->up.z -= b->player->mouse_rel.y * MOUSE_VERTICAL_SENSITIVITY;
		b->up.z = ft_min(b->up.z, -CONF_WINDOW_HEIGHT);
		b->up.z = ft_max(b->up.z, 0);
	}
	ft_physics_controllers(env, body);
	static int cooldown = 0;
	if (cooldown <= 0)
	{
		if (b->player->mouse_buttons[MOUSE_BUTTON_LEFT])
		{
			////// TEMP DEBUG
			t_vec3	direction;
			direction = b->forw;
			direction.z = (b->up.z + CONF_WINDOW_HEIGHT / 2) * 0.021;
			if (b->player->inventory.ammo[0] > 0)
			{
				ft_controller_construct(e, &ft_projectile_iter,
				ft_projectile_setup(e, b->player->sector, (t_projectile_data){b,
					(t_vec3){b->pos.x, b->pos.y, b->pos.z + b->player->height[1]},
					direction, 10000, 10}));
				b->player->inventory.ammo[0]--;
			}
			else
				ft_sound_play_track(sound_empty_gun, 0, 0);
			cooldown = 2;
		}
	}
	else
		cooldown--;
	sync_sprite(e, b);
	ft_server_sync_body_client(b, client);
	ft_server_sync_scene_client(e, client);
	e->main_inventory = b->player->inventory;
	return (1);
}

/*
** init player with NULL for non controlled bodies
*/

t_body	*ft_server_player_construct(t_vec3 pos, void *player,
	t_multiplayer_remote_client *client)
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
