#include "doom_nukem.h"

int	ft_push_notification(t_menu_system *menu_manager, char *content,
	double duration, int color)
{
	t_notification	*new_notification;

	if (!(new_notification = ft_memalloc(sizeof(t_notification))))
		return (ERROR);
	new_notification->content = ft_strdup(content);
	new_notification->duration = duration;
	new_notification->color = color;
	menu_manager->notifications.push(&(menu_manager->notifications),
		new_notification);
}

int	ft_draw_notifications(t_doom_env *env)
{
	t_sdl_image 	*main_image;
	t_notification	*notif;
	t_list_node	*node;
	int		offset;

	offset = 0;
	main_image = env->main_scene.render_image;
	env->menu_manager->notifications.iterator =
		env->menu_manager->notifications.first;
	while ((node = ttslist_iter(&env->menu_manager->notifications)))
	{
		notif = node->content;
		ft_sdl_put_text(notif->content, (t_text){NOTIF_XPOS, NOTIF_YPOS
			+ offset, notif->color}, env->menu_manager->small_font,
			main_image);
		if (-offset > CONF_WINDOW_HEIGHT / 2)
			break;
		notif->duration--;
		if (notif->duration < 0)
		{
			ttslist_splice(&env->menu_manager->notifications, node);
			free(notif->content);
			free(notif);
		}
		offset += NOTIF_OFFSET;
	}
}
