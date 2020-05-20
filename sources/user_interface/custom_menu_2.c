#include "doom_nukem.h"

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
	button = ft_helper_create_menu_button(new_menu, "OPTION 1",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2 - 100,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_button_switch_menu);
	if (button)
		button->arg = (void *)(0L);
	button = ft_helper_create_menu_button(new_menu, "OPTION 2",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_button_switch_menu);
	if (button)
		button->arg = (void *)(0L);
	button = ft_helper_create_menu_button(new_menu, "OPTION 3",
		(t_text){new_menu->position.x + new_menu->position.w / 2,
		new_menu->position.y + new_menu->position.h / 2 + 100,
		0xFFFFFF, ALIGN_CENTER_CENTER}, &ft_button_switch_menu);
	if (button)
		button->arg = (void *)(0L);
	return (SUCCESS);
}
