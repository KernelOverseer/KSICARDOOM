#include "doom_nukem.h"

static void	ft_join_multiplayer_button(t_menu_button *button, void *arg)
{
	t_doom_env	*env;

	env = arg;
	(void)button;
	if (!ft_init_doom_multiplayer(env, NETWORK_ROLE_CLIENT))
	{
		ft_sound_play_track(sound_menu_error, 0, 0);
		return ;
	}
	ft_controller_construct(env, &ft_remote_client_player_input,
		ft_client_player_construct((t_vec3){env->main_scene.camera.position.x,
			env->main_scene.camera.position.y, 0}, ft_player_construct(1337),
			&env->multiplayer.client));
	ft_sdl_loop_hook(ft_main_loop, env);
	ft_push_notification("Welcome to multiplayer mode", 150, 0xFFFFFF);
	ft_sound_play_track(sound_main_theme, 0, -1);
}

static void	ft_start_multiplayer_button(t_menu_button *button, void *arg)
{
	t_doom_env	*env;

	env = arg;
	(void)button;
	env->main_scene.resolution_ratio = 1280;
	ft_init_doom_multiplayer(env, NETWORK_ROLE_SERVER);
	ft_controller_construct(env, &ft_local_player_input,
		ft_body_construct((t_vec3){env->main_scene.camera.position.x,
			env->main_scene.camera.position.y, 0}, ft_player_construct(1337)));
	ft_sdl_loop_hook(ft_main_loop, env);
	ft_push_notification("Welcome to hosted mode", 150, 0xFFFFFF);
	ft_sound_play_track(sound_main_theme, 0, -1);
}

int	ft_load_settings_menu(t_menu_system *menu_manager,
	t_doom_env *env, t_sdl_image *select_indicator)
{
	t_menu		*new_menu;
	t_menu_button	*button;

	new_menu = ft_new_menu();
	new_menu->position = (t_rect){0, 0, env->main_image->width,
		env->main_image->height};
	new_menu->background = ft_load_new_image(SETTINGS_BACKGROUND_IMAGE);
	new_menu->select_indicator = select_indicator;
	if (!new_menu->background || !new_menu->select_indicator)
		return (ERROR);
	ft_add_menu(env->menu_manager, new_menu);
	button = ft_helper_create_menu_button(new_menu, "QUICK JOIN",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2 - 100,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_join_multiplayer_button);
	if (button)
		button->arg = (void *)(0L);
	button = ft_helper_create_menu_button(new_menu, "HOST",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_start_multiplayer_button);
	if (button)
		button->arg = (void *)(0L);
	button = ft_helper_create_menu_button(new_menu, "return",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2 + 100,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_button_switch_menu);
	if (button)
		button->arg = (void *)(0L);
	return (SUCCESS);
}
