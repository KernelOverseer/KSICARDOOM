/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:26:51 by abiri             #+#    #+#             */
/*   Updated: 2020/01/05 21:55:41 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include <stdio.h>

int	ft_debug_create_temp_map(t_graphical_scene *scene)
{
	t_sector *new_sector;
	t_sector *new_sector2;
	t_wall	*new_wall;

	new_sector = ft_new_sector();
	new_sector2 = ft_new_sector();
	new_wall = ft_new_wall((t_point){100, 100}, (t_point){100, 300});
	new_sector->walls.push(&(new_sector->walls), new_wall);
	new_wall = ft_new_wall((t_point){100, 300}, (t_point){400, 300});
	new_sector->walls.push(&(new_sector->walls), new_wall);
	new_wall = ft_new_wall((t_point){400, 300}, (t_point){400, 100});
	new_sector->walls.push(&(new_sector->walls), new_wall);
	new_wall = ft_new_wall((t_point){100, 100}, (t_point){400, 100});
	new_sector->walls.push(&(new_sector->walls), new_wall);
	new_wall = ft_new_wall((t_point){400, 300}, (t_point){700, 700});
	new_sector2->walls.push(&(new_sector2->walls), new_wall);
	new_wall = ft_new_wall((t_point){400, 300}, (t_point){400, 800});
	new_sector2->walls.push(&(new_sector2->walls), new_wall);
	scene->sectors.push(&(scene->sectors), new_sector);
	scene->sectors.push(&(scene->sectors), new_sector2);
	scene->current_sector = new_sector;
	return (SUCCESS);
}

t_vector	ft_vector_from_angle(double size, double angle)
{
	t_vector	result;

	result.x = size * cos(angle);
	result.y = size * sin(angle);
	return (result);
}

int	temp_apply_movement(t_doom_env *env)
{
	t_vector	movement_vector;

	if (env->keys[SDL_SCANCODE_LEFT])
		env->main_scene.camera.angle += 0.05;
	if (env->keys[SDL_SCANCODE_RIGHT])
		env->main_scene.camera.angle -= 0.05;
	if (env->keys[SDL_SCANCODE_UP])
		movement_vector = ft_vector_from_angle(10, env->main_scene.camera.angle);
	env->main_scene.camera.position.x += movement_vector.x;
	env->main_scene.camera.position.y += movement_vector.y;
	return (SUCCESS);
}

int	ft_main_loop(void *arg)
{
	t_doom_env *env;

	env = arg;

	//ft_apply_controllers(env);
	//ft_render_graphics(env);
	temp_render_graphics(&(env->main_scene));
	temp_apply_movement(env);
	ft_sdl_put_image(env->main_scene.render_image, &env->display);
	ft_sdl_render_texture(&env->display);
	return (SUCCESS);
}

int	ft_menu_loop(void *arg)
{
	t_doom_env *env;

	env = arg;

	//ft_interact_menu(env);
	//ft_render_menu(env);
	ft_sdl_loop_hook(ft_main_loop, env);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_doom_env	env;
	(void)argc;
	(void)argv;

	ft_init_game_window(&env);
	ft_init_graphical_scene(&env);
	ft_debug_create_temp_map(&env.main_scene);
	ft_sdl_hook(ft_keyboard_button_on, &env, SDL_KEYDOWN);
	ft_sdl_hook(ft_keyboard_button_off, &env, SDL_KEYUP);
	ft_sdl_loop_hook(ft_menu_loop, &env);
	ft_sdl_loop(&env.display);
	return (0);
}
