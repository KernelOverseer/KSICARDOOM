/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:58:37 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/22 13:41:58 by abiri            ###   ########.fr       */
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
}

void	ft_local_player_input(void *env, void *body)
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
	ft_physics_controllers(env, body);
	sync_camera(env, body);
}

void	ft_init_player(t_player **player, Uint64 id) // init struct s_player values
{
	*player = (t_player *)ft_memalloc(sizeof(t_player));
	(*player)->id = id;
	(*player)->is_grounded = 0;
	(*player)->jump_power = JUMP_POWER;
	(*player)->height[0] = 10;
	(*player)->height[1] = 1500;
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
	ft_bzero(player->input, sizeof(player->input));
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
	return(body);
}
