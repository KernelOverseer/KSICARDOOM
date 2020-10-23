/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:26:51 by abiri             #+#    #+#             */
/*   Updated: 2020/10/23 20:44:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include <stdio.h>

int	ft_debug_create_temp_map(t_graphical_scene *scene)
{
	//ft_old_debug_create_temp_map(scene);
	//return (1);
	return (ft_load_map(scene, "./editor/save_test_doom_map.map"));
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

void	ft_apply_controllers(t_doom_env *env)
{
	t_controller	*controller;

	env->timer.update_time(&env->timer);
	env->controllers.iterator = env->controllers.first;
	while ((controller = ttslist_iter_content(&(env->controllers))))
	{
		if (controller->function)
			controller->function(controller->env, controller->body);
	}
	//ft_physics_controllers(env);
	env->timer.previous_tick = env->timer.current_time;
}

int	ft_main_loop(void *arg)
{
	t_doom_env *env;

	env = arg;
	ft_apply_controllers(env);
	ft_sdl_image_rect(env->main_scene.render_image, (t_rect){0, 0,
	CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT + env->main_scene.camera.tilt}, 0x383838);
	ft_sdl_image_rect(env->main_scene.render_image, (t_rect){0, CONF_WINDOW_HEIGHT
	+ env->main_scene.camera.tilt, CONF_WINDOW_WIDTH, 2 * CONF_WINDOW_HEIGHT +
	env->main_scene.camera.tilt}, 0x707070);
	ft_render_scene(&env->main_scene);
	env->main_scene.frame_count++;
	// temp_apply_movement(env);
	temp_render_graphics(&(env->main_scene));
	ft_render_hud(env);
	ft_sdl_put_image(env->main_scene.render_image, &env->display);
	ft_sdl_render_texture(&env->display);
	// printf("cam_height : %d wallheight : %d\n", env->main_scene.camera.height, (int)DEFAULT_WALL_HEIGHT);
	return (SUCCESS);
}

void	ft_controller_construct(t_doom_env *env, int f(void *, void *), t_body *b)
{
	t_controller	*new_controller;

	new_controller = ft_memalloc(sizeof(t_controller));
	env->bodies.push(&(env->bodies), (void *)b);
	new_controller->function = f;
	new_controller->env = env;
	new_controller->body = b;
	env->controllers.push(&(env->controllers), new_controller);
}

int main(int argc, char **argv)
{
	t_doom_env		env;
	(void)argc;
	(void)argv;

	ft_bzero(&env, sizeof(t_doom_env));
	ft_init_game_window(&env);
	ft_init_graphical_scene(&env);
	if (!ft_main_menu_init(&env))
	{
		ft_raise_exception(ERROR_graphical_init, "Error loading menus");
		return (ERROR);
	}
	if (!(ft_debug_create_temp_map(&env.main_scene)))
		return (1);

	ft_controller_construct(&env, &ft_bot_input, ft_new_bot(env.main_scene.current_sector, (t_vec3){env.main_scene.camera.position.x - 1000,
			env.main_scene.camera.position.y, 0}));

	ft_controller_construct(&env, &ft_local_player_input,
		ft_body_construct((t_vec3){env.main_scene.camera.position.x,
			env.main_scene.camera.position.y, 0}, ft_player_construct(1337)));
	
	ft_controller_construct(&env, &ft_default_bot_iter,
	ft_default_bot_setup(&env, env.main_scene.current_sector, (t_vec3){0, 0, 0}));


	env.main_scene.resolution_ratio = CONF_RES_RATIO;
	//ft_sound_play_track("sound/theme.wav");
	ft_sdl_hook(ft_keyboard_button_on, &env, SDL_KEYDOWN);
	ft_sdl_hook(ft_keyboard_button_off, &env, SDL_KEYUP);
	ft_sdl_hook(ft_mouse_data, &env, SDL_MOUSEMOTION);
	ft_sdl_loop_hook(ft_menu_loop, &env);
	ft_sdl_loop(&env.display);
	return (0);
}

// t_animation	ft_create_temp_animation(char *anim_name, double speed, int count)
// {
// 	t_animation	result;
// 	int			i;
// 	char		*img_name;

// 	i = 1;
// 	result.textures = ft_memalloc(sizeof(t_sdl_image *) * count);
// 	while (i <= count)
// 	{
// 		img_name = ft_strjoin_free(
// 			ft_strjoin_free(anim_name, ft_itoa(i), 2), ".tex", 1);
// 		result.textures[i - 1] = ft_memalloc(sizeof(t_sdl_image));
// 		ft_sdl_load_image(img_name, result.textures[i - 1]);
// 		free(img_name);
// 		i++;
// 	}
// 	result.current_frame = 0;
// 	result.speed = speed;
// 	result.frame_count = count;
// 	result.type = ANIMATION_TYPE_TIME;
// 	return (result);
// }

/*int	ft_old_debug_create_temp_map(t_graphical_scene *scene)
{
	t_sector *new_sector;
	t_sector *new_sector2;
	t_wall	*new_wall;
	t_portal	*new_portal;
	t_sprite	*new_sprite;

	new_sector = ft_new_sector();
	new_sector->floor_height = 0;
	new_sector->ceil_height = 0;
	new_sector2 = ft_new_sector();
	new_sector2->brightness = 1;
	new_sector->brightness = 0.5;
	new_wall = ft_new_wall((t_point){5000, 5000}, (t_point){10000, 10000});
	new_sector->walls.push(&(new_sector->walls), new_wall);
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("render_placeholder.tex", new_wall->texture);

	new_wall = ft_new_wall((t_point){1000, 1000}, (t_point){1000, 3000});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_wall->texture);
	new_sector->walls.push(&(new_sector->walls), new_wall);

	new_wall = ft_new_wall((t_point){1000, 1000}, (t_point){3000, 1000});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_wall->texture);
	new_sector->walls.push(&(new_sector->walls), new_wall);

	new_wall = ft_new_wall((t_point){3000, 1000}, (t_point){3000, 3000});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_wall->texture);
	new_sector->walls.push(&(new_sector->walls), new_wall);

	new_wall = ft_new_wall((t_point){1000, 3000}, (t_point){2500, 2500});
	new_wall->props |= PROP_TRANSPARENT;
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("cell.tex", new_wall->texture);
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
	new_sprite->position = (t_vec2){-2000, -2000};
	new_sprite->animation = ft_create_temp_animation("fire_texture/fire_texture",
		1, 60);
	new_sector->sprites.push(&(new_sector->sprites), new_sprite);

	new_sprite = ft_memalloc(sizeof(t_sprite));
	new_sprite->radius = 400;
	new_sprite->height = DEFAULT_WALL_HEIGHT;
	new_sprite->position = (t_vec2){2999, 1999};
//new_sprite->animation = ft_create_temp_animation("fire_texture/fire_texture",
		1, 60);
	new_sprite->animation = ft_create_temp_animation("animation/ricardo_",
		0.5, 56);
	new_sprite->props |= PROP_FIXED_ANGLE;
	new_sector->sprites.push(&(new_sector->sprites), new_sprite);

	new_sprite = ft_memalloc(sizeof(t_sprite));
	new_sprite->position = (t_vec2){1400, 1400};
	new_sprite->radius = 5;
	new_sprite->height = 100;
	new_sprite->animation = ft_create_temp_animation("player_animation/doomguy_",
		1, 8);
	new_sprite->animation.type = ANIMATION_TYPE_DIRECTION;

	new_sector->sprites.push(&(new_sector->sprites), new_sprite);
	new_wall = ft_new_wall((t_point){900, 2900}, (t_point){2900, 2900});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_wall->texture);
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	new_portal = ft_new_portal((t_point){1000, 3000}, (t_point){3000, 3000}, new_sector2);
	new_portal->wall.texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_portal->wall.texture);
	new_sector->portals.push(&(new_sector->portals), new_portal);

	new_portal = ft_new_portal((t_point){1000, 3000}, (t_point){3000, 3000}, new_sector);
	new_portal->wall.texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("ironwall.tex", new_portal->wall.texture);
	new_sector2->portals.push(&(new_sector2->portals), new_portal);

	new_wall = ft_new_wall((t_point){1000, 3000}, (t_point){2000, 5000});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_wall->texture);
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	new_wall = ft_new_wall((t_point){3000, 3000}, (t_point){4000, 5000});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_wall->texture);
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	new_wall = ft_new_wall((t_point){2000, 5000}, (t_point){4000, 5000});
	new_wall->texture = ft_memalloc(sizeof(t_sdl_image));
	ft_sdl_load_image("floor.tex", new_wall->texture);
	new_sector2->walls.push(&(new_sector2->walls), new_wall);

	new_sector2->ceil_height = -1000;
	scene->sectors.push(&(scene->sectors), new_sector);
	scene->sectors.push(&(scene->sectors), new_sector2);
	scene->current_sector = new_sector;

	scene->skybox = ft_memalloc(sizeof(t_sdl_image));
	printf("LOADING SKY : %d\n", ft_sdl_load_image("sky.tex", scene->skybox));

	new_sector->ceil_texture = ft_memalloc(sizeof(t_sdl_image));
	printf("LOADING ceiling : %d\n", ft_sdl_load_image("ironwall.tex", new_sector->ceil_texture));

	new_sector2->ceil_texture = ft_memalloc(sizeof(t_sdl_image));
	printf("LOADING ceiling : %d\n", ft_sdl_load_image("floor.tex", new_sector2->ceil_texture));

	return (SUCCESS);
}
*/
// int	temp_apply_movement(t_doom_env *env)
// {
// 	t_vec2	movement_vector;

// 	movement_vector = (t_vec2){0, 0};
// 	// if (env->keys[SDL_SCANCODE_LEFT])
// 	// 	env->main_scene.camera.angle += 0.05;
// 	// if (env->keys[SDL_SCANCODE_RIGHT])
// 	// 	env->main_scene.camera.angle -= 0.05;
// 	// if (env->keys[SDL_SCANCODE_UP])

// 	// 	movement_vector = ft_vec2_from_angle(10, env->main_scene.camera.angle);
// 	// if (env->keys[SDL_SCANCODE_DOWN])
// 		// movement_vector = ft_vec2_from_angle(-10, env->main_scene.camera.angle);

// 	if (env->keys[SDL_SCANCODE_DELETE])
// 		env->main_scene.camera.height += 50;
// 	if (env->keys[SDL_SCANCODE_HOME])
// 		env->main_scene.camera.height -= 50;

// 	if (env->keys[SDL_SCANCODE_PAGEDOWN] && env->main_scene.camera.tilt >=
// 			- env->main_scene.render_image->height + 10)
// 		env->main_scene.camera.tilt -= 10;
// 	if (env->keys[SDL_SCANCODE_PAGEUP] && env->main_scene.camera.tilt <=
// 			- 10)
// 		env->main_scene.camera.tilt += 10;
// 	if (env->keys[SDL_SCANCODE_KP_7])
// 		env->main_scene.current_sector->floor_height += 50;
// 	if (env->keys[SDL_SCANCODE_KP_4])
// 		env->main_scene.current_sector->floor_height -= 50;
// 	if (env->keys[SDL_SCANCODE_0])
// 		ft_rotate_sectors(env);
// 	if ((env->mouse_rel.y > 0 && env->main_scene.camera.tilt >=
// 			- env->main_scene.render_image->height + 10)
// 		|| (env->mouse_rel.y < 0 && env->main_scene.camera.tilt <= - 10))
// 		env->main_scene.camera.tilt -= env->mouse_rel.y;
// 	if (env->mouse_rel.x)
// 		env->main_scene.camera.angle += env->mouse_rel.x * -0.01;
// 	// env->main_scene.camera.position.x += movement_vector.x;
// 	// env->main_scene.camera.position.y += movement_vector.y;
// 	return (SUCCESS);
// }