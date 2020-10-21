/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_physics_controllers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:21:30 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/20 14:21:45 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_structs.h"
#include "physics_engine.h"
#include "doom_nukem.h"

t_body			ft_default_body(t_vec3 pos)
{
	return ((t_body){pos, ZERO_VEC3, ZERO_VEC3, ZERO_VEC3, FORW, RIGHT,
	UP, P_SPEED, MASS, DRAG, FRICTION, BOUNCE, 0.0,
	HAS_GRAVITY | HAS_COLLISION| IS_CONTROLLED,
	NULL, &ft_update_velocity, &ft_body_collision, &ft_body_move,
	&ft_update_force, &ft_update_gravity, &ft_force_add, &ft_force_change});
}

void    ft_physics_controllers(void *arg)
{
	t_doom_env				*env;
	t_body					*body;

	env = (t_doom_env *)arg;
	env->timer.update_time(&env->timer);
	if (env->timer.delta_time >= (1.0 / 50))
	{
		env->bodies.iterator = env->bodies.first;
		while ((body = ttslist_iter_content(&(env->bodies))))
		{
			if (body->flags & IS_CONTROLLED)
				ft_new_input_changes(body);
			body->update_gravity(body, env->phi.gravity_vec, env->timer.delta_time);
			body->update_force(body, env->timer.delta_time);
			body->update_velocity(body, env->timer.delta_time);
		}
		env->bodies.iterator = env->bodies.first;
		while ((body = ttslist_iter_content(&(env->bodies))))
		{
			body->collision(&env->main_scene, body, env->timer.delta_time);
			body->update_position(body, env->timer.delta_time);
		}
		env->timer.previous_tick = env->timer.current_time;
	}
}
