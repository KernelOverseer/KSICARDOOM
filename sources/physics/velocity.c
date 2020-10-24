/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:26:02 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/24 19:02:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physics_engine.h"

void    ft_new_input_changes(t_body *body)
{
	t_vec3 move_dir;
	unsigned char *c;
	t_vec3 *v;

	move_dir = ZERO_VEC3;
	v = &body->player->input_velocity;
	*v = (t_vec3){v->x, v->y, v->z};
	c = body->player->input;
	// changing height on crouch
	if (c[PLAYER_CROUCH])
	{
		if (body->player->height[1] > body->player->height[2] / 2)
			body->player->height[1] *= 0.8;
		c[PLAYER_RUN] = 0;
	}
	else
	{
		if (body->player->height[1] < body->player->height[2])
			body->player->height[1] /= 0.8;
	}
	// rotating player
	if (c[PLAYER_TURN_RIGHT])
	{
		body->forw = ft_vec3_rotate_z(body->forw, -ANGLE);
		body->right = ft_vec3_cross_product(body->forw, UP);
	}
	if (c[PLAYER_TURN_LEFT])
	{
		body->forw = ft_vec3_rotate_z(body->forw, ANGLE);
		body->right = ft_vec3_cross_product(body->forw, UP);
	}
	// move direction
	if (c[PLAYER_FORWARD] && body->player->is_grounded)
		move_dir = body->forw;
	if (c[PLAYER_BACKWARDS] && body->player->is_grounded)
		move_dir = ft_vec3_add(move_dir, ft_vec3_scalar(body->forw, -1));
	if (c[PLAYER_STRAFE_RIGHT] && body->player->is_grounded)
		move_dir = ft_vec3_add(move_dir, body->right);
	if (c[PLAYER_STRAFE_LEFT] && body->player->is_grounded)
		move_dir = ft_vec3_add(move_dir, ft_vec3_scalar(body->right, -1));
	move_dir = ft_vec3_normalize(move_dir);
	// applying movement+crouching speed+run speed
	*v = ft_vec3_add(*v, ft_vec3_scalar(move_dir, body->speed + (c[PLAYER_RUN] * P_RUN_SPEED) - (c[PLAYER_CROUCH]  * body->speed / 2)));
	// Jump
	if (c[PLAYER_JUMP] && body->player->is_grounded)
	{
		*v = ft_vec3_add(*v, ft_vec3_scalar(UP, body->player->jump_power));
		body->player->is_grounded = false;
	}
	// printf("forw: x: %f, y: %f, z: %f | right: x: %f, y: %f, z: %f | pos: x: %f, y: %f, z: %f\n",
	// body->forw.x, body->forw.y, body->forw.z,
	// body->right.x, body->right.y, body->right.z,
	// body->pos.x, body->pos.y, body->pos.z);
}

void	ft_body_move(t_body *body, double delta_time)
{
	body->pos = ft_vec3_add(body->pos, ft_vec3_scalar(body->velocity, delta_time));
}

void	ft_update_velocity(t_body *body, double delta_time)
{
	if (body->flags & IS_CONTROLLED)
	{
		body->velocity.x = body->player->input_velocity.x * body->friction;//ft_lerp(body->player->input_velocity.x, body->velocity.x, delta_time * 90);
		body->velocity.y = body->player->input_velocity.y * body->friction;//ft_lerp(body->player->input_velocity.y, body->velocity.y, delta_time * 90);
		body->velocity.z = body->player->input_velocity.z;
		body->velocity = ft_vec3_add(body->velocity, body->gravity);
	}
	else
	{
    	body->velocity = ft_vec3_add(body->velocity, body->gravity);
	}
	(void)delta_time;
}
