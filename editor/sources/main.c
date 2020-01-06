/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:34:58 by abiri             #+#    #+#             */
/*   Updated: 2020/01/05 22:40:44 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		ft_display_init(t_doom_editor *env)
{
	t_sdl_init_config	sdl_config;

	ft_bzero(env, sizeof(t_doom_editor));
	sdl_config = ft_sdl_new_config();
	sdl_config.window_title = "doom_nukem_editor";
	sdl_config.screen_width = WINDOW_WIDTH;
	sdl_config.screen_height = WINDOW_HEIGHT;
	ttslist_init(&(env->event.points));
	ttslist_init(&(env->data.sectors));
	if (!ft_sdl_init(&(env->display_env), sdl_config))
		return (0);
	env->main_image = newimage(sdl_config.screen_width, sdl_config.screen_height);
	env->edit_image = newimage(EDIT_WIDTH, EDIT_HEIGHT);
	env->render_image = newimage(EDIT_WIDTH, EDIT_HEIGHT);
	if (!env->main_image || !env->edit_image)
		return (0);
	return (1);
}

int	ft_main_loop(void *arg)
{
	t_doom_editor	*env;

	env = arg;
	ft_sdl_clear_image(env->main_image, env->gui.background_color);
	if (env->event.preview_mode == PREVIEW_EDIT)
    {
		ft_draw_points(env);
		ft_draw_player(env);
		ft_draw_lines(env);
	}
	else if (env->event.preview_mode == PREVIEW_RENDER)
		ft_render_scene(&(env->data));
	ft_draw_gui_areas(&(env->gui));
	ft_sdl_put_image(env->main_image, &(env->display_env));
	ft_sdl_render_texture(&(env->display_env));
	return (1);
}

int	ft_events_init(t_doom_editor *env)
{
	t_sector	*first_sector;

	env->editor_canvas = ft_get_component_by_id(&(env->gui), "main_render_canvas");
	env->editor_canvas->data = env->render_image;
	env->editor_canvas = ft_get_component_by_id(&(env->gui), "main_edit_canvas");
	env->editor_canvas->data = env->edit_image;
	if (!(first_sector = ft_new_sector()))
		return (0);
	if (!env->data.sectors.push(&(env->data.sectors), first_sector))
		return (0);
	env->data.current_sector = first_sector;
	ft_reload_sector_settings(env);
	env->event.scale = EDIT_SCALE;
	env->data.render_image = env->render_image;
	env->data.camera.position = (t_vector){(env->render_image->width / 2) * env->event.scale, (env->render_image->height / 2) * env->event.scale};
	env->event.edit_mode = EDIT_MODE_ADD;
	if (!ft_load_sector_events(&(env->gui), env))
		return (0);
	ft_sdl_loop_hook(&ft_main_loop, env);
	ft_sdl_hook(&ft_editor_mouse_event, env, SDL_MOUSEWHEEL);
	ft_sdl_hook(&ft_editor_mouse_event, env, SDL_MOUSEMOTION);
	ft_sdl_hook(&ft_editor_mouse_event, env, SDL_MOUSEBUTTONDOWN);
	ft_sdl_hook(&ft_editor_mouse_event, env, SDL_MOUSEBUTTONUP);
	return (1);
}

int main(void) {
	t_doom_editor env;

	if (!ft_display_init(&env))
	{
		ft_putstr_fd("An initialisation error occured\n", 2);
		return (-1);
	}
	if (!ft_gui_init(&(env.gui), &(env.display_env), env.main_image))
	{
		ft_putstr_fd("A GUI initialisation error occured\n", 2);
		return (-1);
	}
	ft_main_interface_loading(&(env.gui), &env);
	if (!ft_events_init(&env))
	{
		ft_putstr_fd("An EDITOR initialisation error occured\n", 2);
		return (-1);
	}
	ft_sdl_loop(&(env.display_env));
	return (0);
}
