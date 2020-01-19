/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:58:37 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/19 21:23:37 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** to do: make ft_bodies_input take input from different sources (keyboard, bot, conected user)
*/

void	ft_bodies_input(void *params)
{
	unsigned char *c;
	unsigned char *k;
	t_doom_env *env;

	env = (t_doom_env *)params;
	c =	((t_body *)env->bodies.first->content)->player->controller;
	k = env->keys;
	c[PLAYER_FORWARD] = (k[SDL_SCANCODE_UP]) ?
			k[SDL_SCANCODE_UP] : k[SDL_SCANCODE_W];
	c[PLAYER_BACKWARDS] = (k[SDL_SCANCODE_DOWN]) ?
			k[SDL_SCANCODE_DOWN] : k[SDL_SCANCODE_S];
	c[PLAYER_TURN_LEFT] = k[SDL_SCANCODE_LEFT];
	c[PLAYER_TURN_RIGHT] = k[SDL_SCANCODE_RIGHT];
	c[PLAYER_CROUCH] = k[SDL_SCANCODE_LCTRL];
	c[PLAYER_RUN] = k[SDL_SCANCODE_LSHIFT];
	c[PLAYER_STRAFE_LEFT] = k[SDL_SCANCODE_A];
	c[PLAYER_STRAFE_RIGHT] = k[SDL_SCANCODE_D];
	c[PLAYER_JUMP] = k[SDL_SCANCODE_SPACE];
	SDL_GetRelativeMouseState(&env->mouse_rel.x, &env->mouse_rel.y);
}

void	ft_init_player(t_player **player, int id)
{
	*player = (t_player *)ft_memalloc(sizeof(t_player));
	(*player)->id = id;
	(*player)->is_jumping = 0;
	(*player)->jump_power = JUMP_POWER;
	(*player)->max_jump = 5;
	(*player)->height[0] = 4;
	(*player)->height[1] = 4;
	ft_bzero((*player)->controller, sizeof((*player)->controller));
}

void	ft_free_player(t_body *body)
{
	ft_memdel((void **)&body->player);
	body->flags = body->flags ^ IS_CONTROLLED;
}

int ft_init_bodies(t_doom_env *env)
{
	t_body *body;
	t_body default_body;

	default_body = ft_default_body((t_vec3){2000, 2000, 2});
	body = ft_memalloc(sizeof(t_body));
	ft_memcpy(body, &default_body, sizeof(t_body));
	ft_init_player(&body->player, 1337);
	ttslist_init(&(env->bodies));
	env->bodies.push(&(env->bodies), (void *)body);
	return(SUCCESS);
}
