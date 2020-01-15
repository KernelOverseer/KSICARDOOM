/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:26:51 by abiri             #+#    #+#             */
/*   Updated: 2020/01/14 20:39:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include <stdio.h>

t_animation	ft_create_temp_animation(char *anim_name, double speed, int count)
{
	t_animation	result;
	int			i;
	char		*img_name;

	i = 1;
	result.textures = ft_memalloc(sizeof(t_sdl_image *) * count);
	while (i <= count)
	{
		img_name = ft_strjoin_free(
			ft_strjoin_free(anim_name, ft_itoa(i), 2), ".tex", 1);
		result.textures[i - 1] = ft_memalloc(sizeof(t_sdl_image));
		ft_sdl_load_image(img_name, result.textures[i - 1]);
		free(img_name);
		i++;
	}
	result.current_frame = 0;
	result.speed = speed;
	result.frame_count = count;
	return (result);
}

int	ft_debug_create_temp_map(t_graphical_scene *scene)
{
	t_sector *new_sector;
	t_sector *new_sector2;
	t_wall	*new_wall;
	t_portal	*new_portal;
	t_sprite	*new_sprite;

	new_sector = ft_new_sector();
	new_sector2 = ft_new_sector();
	new_wall = ft_new_wall((t_point){500, 500}, (t_point){1000, 1000});
	new_sector->walls.push(&(new_sector->walls), new_wall);
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("render_placeholder.tex", new_wall->texture);

	new_wall = ft_new_wall((t_point){100, 100}, (t_point){100, 300});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_wall->texture);
	new_sector->walls.push(&(new_sector->walls), new_wall);

	new_wall = ft_new_wall((t_point){100, 100}, (t_point){300, 100});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_wall->texture);
	new_sector->walls.push(&(new_sector->walls), new_wall);

	new_wall = ft_new_wall((t_point){300, 100}, (t_point){300, 300});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_wall->texture);
	new_sector->walls.push(&(new_sector->walls), new_wall);

	new_sprite = ft_memalloc(sizeof(t_sprite));
	new_sprite->radius = 30;
	new_sprite->height = DEFAULT_WALL_HEIGHT;
	new_sprite->animation = ft_create_temp_animation("fire_texture/fire_texture",
		1, 60);
	new_sector->sprites.push(&(new_sector->sprites), new_sprite);
	
	new_sprite = ft_memalloc(sizeof(t_sprite));
	new_sprite->radius = 30;
	new_sprite->height = DEFAULT_WALL_HEIGHT;
	new_sprite->position = (t_vec2){-200, -200};
	new_sprite->animation = ft_create_temp_animation("fire_texture/fire_texture",
		1, 60);
	new_sector->sprites.push(&(new_sector->sprites), new_sprite);
	
	new_sprite = ft_memalloc(sizeof(t_sprite));
	new_sprite->radius = 30;
	new_sprite->height = DEFAULT_WALL_HEIGHT;
	new_sprite->position = (t_vec2){-300, -300};
	new_sprite->animation = ft_create_temp_animation("fire_texture/fire_texture",
		1, 60);
	new_sector->sprites.push(&(new_sector->sprites), new_sprite);

	new_sprite = ft_memalloc(sizeof(t_sprite));
	new_sprite->position = (t_vec2){-100, -100};
	new_sprite->radius = 50;
	new_sprite->height = DEFAULT_WALL_HEIGHT / 2;
/*	new_sprite->animation = ft_create_temp_animation("animation/ricardo_",
		0.2, 56);*/
	new_sprite->animation = ft_create_temp_animation("fire_texture/fire_texture",
		1, 60);
	new_sector->sprites.push(&(new_sector->sprites), new_sprite);

	new_wall = ft_new_wall((t_point){90, 290}, (t_point){290, 290});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_wall->texture);
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	new_portal = ft_new_portal((t_point){100, 300}, (t_point){300, 300}, new_sector2);
	new_portal->wall.texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_portal->wall.texture);
	new_sector->portals.push(&(new_sector->portals), new_portal);

	new_portal = ft_new_portal((t_point){100, 300}, (t_point){300, 300}, new_sector);
	new_portal->wall.texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_portal->wall.texture);
	new_sector2->portals.push(&(new_sector2->portals), new_portal);

	new_wall = ft_new_wall((t_point){100, 300}, (t_point){200, 500});
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	new_wall = ft_new_wall((t_point){300, 300}, (t_point){400, 500});
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	scene->sectors.push(&(scene->sectors), new_sector);
	scene->sectors.push(&(scene->sectors), new_sector2);
	scene->current_sector = new_sector;
	return (SUCCESS);
}

t_vec2	ft_vector_from_angle(double size, double angle)
{
	t_vec2	result;

	result.x = size * cos(angle);
	result.y = size * sin(angle);
	return (result);
}

void	ft_rotate_sectors(t_doom_env *env)
{
	t_list_node *node;
	t_list_node	*chosen;

	chosen = NULL;
	env->main_scene.sectors.iterator = env->main_scene.sectors.first;
	while ((node = ttslist_iter(&env->main_scene.sectors)))
	{
		if (node->content == env->main_scene.current_sector)
			break;
	}
	if (node && node->next)
		chosen = node->next;
	if (!chosen)
		chosen = env->main_scene.sectors.first;
	env->main_scene.current_sector = chosen->content;
}

int	temp_apply_movement(t_doom_env *env)
{
	t_vec2	movement_vector;

	movement_vector = (t_vec2){0, 0};
	if (env->keys[SDL_SCANCODE_LEFT])
		env->main_scene.camera.angle += 0.05;
	if (env->keys[SDL_SCANCODE_RIGHT])
		env->main_scene.camera.angle -= 0.05;
	if (env->keys[SDL_SCANCODE_UP])
		movement_vector = ft_vec2_from_angle(10, env->main_scene.camera.angle);
	if (env->keys[SDL_SCANCODE_DOWN])
		movement_vector = ft_vec2_from_angle(-10, env->main_scene.camera.angle);
	if (env->keys[SDL_SCANCODE_PAGEUP])
		env->main_scene.camera.height += 50;
	if (env->keys[SDL_SCANCODE_PAGEDOWN])
		env->main_scene.camera.height -= 50;
	if (env->keys[SDL_SCANCODE_S])
		env->main_scene.camera.tilt -= 10;
	if (env->keys[SDL_SCANCODE_W])
		env->main_scene.camera.tilt += 10;
	if (env->keys[SDL_SCANCODE_DELETE])
		env->main_scene.current_sector->ceil_height += 50;
	if (env->keys[SDL_SCANCODE_HOME])
		env->main_scene.current_sector->ceil_height -= 50;
	if (env->keys[SDL_SCANCODE_KP_7])
		env->main_scene.current_sector->floor_height += 50;
	if (env->keys[SDL_SCANCODE_KP_4])
		env->main_scene.current_sector->floor_height -= 50;
	if (env->keys[SDL_SCANCODE_0])
		ft_rotate_sectors(env);
	env->main_scene.camera.position.x += movement_vector.x;
	env->main_scene.camera.position.y += movement_vector.y;
	return (SUCCESS);
}

void	sync_camera_pos(t_doom_env *env, t_vec3 pos)
{
	env->main_scene.camera.position.x = pos.x;
	env->main_scene.camera.position.y = pos.y;
}

void	ft_apply_controllers(t_doom_env *env)
{
	t_controller	*controller;

	env->controllers.iterator = env->controllers.first;
	while ((controller = ttslist_iter_content(&(env->controllers))))
	{
		if (controller->function)
			controller->function(controller->arg);
	}
}

int	ft_main_loop(void *arg)
{
	t_doom_env *env;

	env = arg;
	ft_players_input(env);
	ft_apply_controllers(env);
	sync_camera_pos(env, ((t_body *)env->bodies.first->content)->pos);
	ft_sdl_image_rect(env->main_scene.render_image, (t_rect){0, 0, CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT + env->main_scene.camera.tilt},
			0x383838);
	ft_sdl_image_rect(env->main_scene.render_image, (t_rect){0, CONF_WINDOW_HEIGHT + env->main_scene.camera.tilt , CONF_WINDOW_WIDTH, 2 * CONF_WINDOW_HEIGHT + env->main_scene.camera.tilt},
			0x707070);
	ft_render_scene(&env->main_scene);
	env->main_scene.frame_count++;
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
	t_doom_env		env;
	t_controller	physics_controller;
	(void)argc;
	(void)argv;

	ft_init_game_window(&env);
	ft_init_graphical_scene(&env);
	physics_controller.function = &ft_physics_controllers;
	physics_controller.arg = &env;
	env.controllers.push(&(env.controllers), &physics_controller);
	ft_init_bodies(&env);
	ft_debug_create_temp_map(&env.main_scene);
	ft_sdl_hook(ft_keyboard_button_on, &env, SDL_KEYDOWN);
	ft_sdl_hook(ft_keyboard_button_off, &env, SDL_KEYUP);
	ft_sdl_hook(ft_mouse_data, &env, SDL_MOUSEMOTION);
	ft_sdl_loop_hook(ft_menu_loop, &env);
	ft_sdl_loop(&env.display);
	return (0);
}
