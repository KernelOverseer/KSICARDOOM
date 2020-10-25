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

void	sync_camera(t_doom_env *env, t_body *body)
{
	double angle;
	t_vec3 cross;

	if (body->flags & IS_CONTROLLED)
		env->main_scene.camera.height = body->pos.z + body->player->height[1];
	env->main_scene.camera.position.x = body->pos.x;
	env->main_scene.camera.position.y = body->pos.y;
	angle = acos(ft_vec3_dot_product(body->forw, RIGHT));
	cross = ft_vec3_cross_product(body->forw, RIGHT);
	if (ft_vec3_dot_product(DOWN, cross) < 0)
		angle = -angle;
	env->main_scene.camera.angle = angle;
	env->main_scene.camera.tilt = body->up.z;
	env->main_scene.current_sector = body->player->sector;
}

int	ft_local_player_input(void *env, void *body)
{
	unsigned char	*c;
	unsigned char	*k;
	t_doom_env		*e;
	t_body			*b;

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
	SDL_GetRelativeMouseState(&e->mouse_rel.x, &e->mouse_rel.y);
	if (e->mouse_rel.x != 0)
	{
		b->forw = ft_vec3_rotate_z(b->forw, -e->mouse_rel.x * MOUSE_HORIZONTAL_SENSITIVITY);
		b->right = ft_vec3_cross_product(b->forw, UP);
	}
	if (e->mouse_rel.y != 0)
	{
		b->up.z -= e->mouse_rel.y * MOUSE_VERTICAL_SENSITIVITY;
		b->up.z = ft_min(b->up.z, -CONF_WINDOW_HEIGHT);
		b->up.z = ft_max(b->up.z, 0);
	}	
	ft_physics_controllers(env, body);
	sync_camera(env, body);
	static int cooldown = 0;
	if (cooldown <= 0)
	{
		if (e->mouse_buttons[MOUSE_BUTTON_LEFT])
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
	e->main_inventory = b->player->inventory;
	return (1);
}

void	ft_init_player(t_player **player, Uint64 id) // init struct s_player values
{
	*player = (t_player *)ft_memalloc(sizeof(t_player));
	(*player)->id = id;
	(*player)->is_grounded = 0;
	(*player)->jump_power = JUMP_POWER;
	(*player)->height[0] = 2000;
	(*player)->height[1] = 2000;
	ft_bzero((*player)->input, sizeof((*player)->input));
}

void	ft_free_player(t_body *body)
{
	ft_memdel((void **)&body->player);
	body->flags = body->flags ^ IS_CONTROLLED;
}

int	ft_init_bodies(t_doom_env *env)
{
	t_body *body;
	t_body default_body;

	default_body = ft_default_body((t_vec3){2000, 2000, 2}); // pass start position
	body = ft_memalloc(sizeof(t_body));
	ft_memcpy(body, &default_body, sizeof(t_body));
	ft_init_player(&body->player, 1337); // 1337 => generate unique ID
	ttslist_init(&(env->bodies));
	env->bodies.push(&(env->bodies), (void *)body);
	return(SUCCESS);
}

t_player *ft_player_construct(Uint64 id)
{
	t_player *player;
	
	player = (t_player *)ft_memalloc(sizeof(t_player));
	player->id = id;
	player->is_grounded = 1;
	player->jump_power = JUMP_POWER;
	player->height[0] = 50;
	player->height[1] = 1500;
	player->height[2] = player->height[1];
	ft_bzero(player->input, sizeof(player->input));
	player->sector = g_parsed_scene->current_sector;
	return (player);
}

/*
** init player with NULL for non controlled bodies
*/

t_body	*ft_body_construct(t_vec3 pos, void *player)
{
	t_body *body;

	body = ft_memalloc(sizeof(t_body));
	*body = ft_default_body(pos);
	body->flags ^= ((player == NULL) ? IS_CONTROLLED : 0);
	body->player = player;
	ft_create_player_sprite(player);
	ft_fill_player_sprite_textures(g_parsed_scene, player,
		g_parsed_scene->textures_count - 8, 8);
	((t_player*)player)->sprite->parent = body;
	((t_player*)player)->sprite->parent_type = PARENT_TYPE_BODY;
	((t_player*)player)->inventory = (t_inventory){0, 100, 100, {20, 0, 0, 0, 0}};
	body->up.z = -CONF_WINDOW_HEIGHT / 2;
	return(body);
}
