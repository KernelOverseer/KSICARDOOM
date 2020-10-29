#include "doom_nukem.h"

void	ft_button_switch_menu(t_menu_button *button, void *arg)
{
	t_doom_env	*env;
	t_menu		*next;
	long		menu_index;

	env = arg;
	ft_sound_play_track(sound_menu_return, 0, 0);
	menu_index = (long long)(button->arg);
	next = ttslist_get_id_content(&env->menu_manager->menu_list,
	menu_index);
	if (next)
		env->menu_manager->current = next;
}

t_menu_button	*ft_helper_create_menu_button(t_menu *menu, const char *text,
	t_text format, t_menu_button_handler *handler)
{
	t_menu_button	*new_button;

	if (!(new_button = ft_new_button(text)))
		return (NULL);
	new_button->format = format;
	new_button->handler = handler;
	ft_add_button(menu, new_button);
	return (new_button);
}
