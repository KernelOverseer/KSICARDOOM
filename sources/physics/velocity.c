/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:26:02 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/04 16:26:03 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"

void    ft_new_input_changes(t_body *body)
{
	unsigned char *c;
	t_vec3 *v;
	v = &body->player->input_velocity;
	*v = (t_vec3){0, 0, 0};
	c = body->player->controller;
	body->player->height[1] = (c[PLAYER_CROUCH]) ? body->player->height[0] / 2 : body->player->height[0];
	if (c[PLAYER_TURN_RIGHT])
	{
		body->forw = ft_vec3_rotate_z(body->forw, ANGLE);
		body->right = ft_vec3_cross_product(body->forw, DOWN);
	}
	if (c[PLAYER_TURN_LEFT])
	{
		body->forw = ft_vec3_rotate_z(body->forw, -ANGLE);
		body->right = ft_vec3_cross_product(body->forw, DOWN);
	}
	if (c[PLAYER_FORWARD])
		*v = ft_vec3_scalar(body->forw, body->speed + (c[PLAYER_RUN] * P_RUN_SPEED));
	else if (c[PLAYER_BACKWARDS])
		*v = ft_vec3_scalar(body->forw, -body->speed + (c[PLAYER_RUN] * P_RUN_SPEED));
	if (c[PLAYER_STRAFE_RIGHT])
		*v = ft_vec3_add(*v, ft_vec3_scalar(body->right, body->speed + (c[PLAYER_RUN] * P_RUN_SPEED)));
	else if (c[PLAYER_STRAFE_LEFT])
		*v = ft_vec3_add(*v, ft_vec3_scalar(body->right, -body->speed + (c[PLAYER_RUN] * P_RUN_SPEED)));
	if (c[PLAYER_JUMP])// && !body->player->is_jumping)
	{
		*v = ft_vec3_add(*v, ft_vec3_scalar(body->up, body->player->jump_power));
		body->player->is_jumping = 1;
	}
	// printf("forw: x: %f, y: %f, z: %f | right: x: %f, y: %f, z: %f | pos: x: %f, y: %f, z: %f\n",
	// body->forw.x, body->forw.y, body->forw.z,
	// body->right.x, body->right.y, body->right.z,
	// body->pos.x, body->pos.y, body->pos.z);
}

double	ft_lerp(double goal, double current, double delta_time)
{
	double diff;

	diff = goal - current;
	if (diff > delta_time)
		return (current + delta_time);
	if (diff < -delta_time)
		return (current - delta_time);
	return (goal);
}

void	ft_body_move(t_body *body, double delta_time)
{
	body->pos = ft_vec3_add(body->pos, ft_vec3_scalar(body->velocity, delta_time * 20));
}

void	ft_update_velocity(t_body *body, t_vec3 global_gravity, double delta_time)
{
	if (body->flags & IS_CONTROLLED)
	{
		body->velocity.x = ft_lerp(body->player->input_velocity.x, body->velocity.x, delta_time * 90);
		body->velocity.y = ft_lerp(body->player->input_velocity.y, body->velocity.y, delta_time * 90);
		body->velocity.z = body->player->input_velocity.z * (delta_time * 20);
    	body->velocity = ft_vec3_add(body->velocity, body->gravity);
	}
	else
	{
		body->pos = ft_vec3_add(body->pos, ft_vec3_scalar(body->velocity, delta_time * 20));
		body->velocity = ft_vec3_add(body->velocity, ft_vec3_scalar(global_gravity, delta_time * 5)); // gravity
	}
}
