#include "doom_nukem.h"

static void	ft_start_menu_button(t_menu_button *button, void *arg)
{
	t_doom_env	*env;

	env = arg;
	(void)button;
	ft_sdl_loop_hook(ft_main_loop, env);
	ft_push_notification(env->menu_manager, "Welcome to the game", 150, 0xFFFFFF);
}

static void	ft_exit_menu_button(t_menu_button *button, void *arg)
{
	t_doom_env *env;

	env = arg;
	(void)button;
	env->display.quit = 1;
}

static t_menu	*ft_load_first_menu(t_menu_system *menu_manager,
	t_doom_env *env)
{
	t_menu		*new_menu;
	t_menu_button	*button;

	new_menu = ft_new_menu();
	new_menu->position = (t_rect){0, 0, env->main_image->width,
		env->main_image->height};
	new_menu->background = ft_load_new_image(BACKGROUND_IMAGE);
	new_menu->select_indicator = ft_load_new_image(SELECT_INDICATOR);
	if (!new_menu->background || !new_menu->select_indicator)
		return (NULL);
	ft_add_menu(env->menu_manager, new_menu);
	ft_helper_create_menu_button(new_menu, "START",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2 - 100,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_start_menu_button);
	button = ft_helper_create_menu_button(new_menu, "SETTINGS",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_button_switch_menu);
	if (button)
		button->arg = (void *)(1L);
	ft_helper_create_menu_button(new_menu, "EXIT",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2 + 100,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_exit_menu_button);
	return (new_menu);
}

int	ft_main_menu_init(t_doom_env *env)
{
	t_menu	*main_menu;

	if (!(env->menu_manager = ft_memalloc(sizeof(t_menu_system))))
		return (ERROR);
	ft_init_menu_system(env->menu_manager, NULL);
	env->menu_manager->font = TTF_OpenFont(MENU_FONT, LARGE_FONT_SIZE);
	env->menu_manager->medium_font = TTF_OpenFont(MENU_FONT, MEDIUM_FONT_SIZE);
	env->menu_manager->small_font = TTF_OpenFont(MENU_FONT, SMALL_FONT_SIZE);
	if (!env->menu_manager->font || !env->menu_manager->medium_font ||
		!env->menu_manager->small_font)
		return (ERROR);
	if (!(main_menu = ft_load_first_menu(env->menu_manager, env)))
		return (ERROR);
	if (!ft_load_settings_menu(env->menu_manager, env,
		main_menu->select_indicator))
		return (ERROR);
	env->menu_manager->current = main_menu;
	return (SUCCESS);
}

