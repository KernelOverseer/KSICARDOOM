#include "doom_nukem.h"

static int	ft_place_label_value(t_doom_env *env, char *label,
	char *value, t_text rect)
{
	t_sdl_image	*main_image;

	main_image = env->main_scene.render_image;
	ft_sdl_put_text(label, rect,
		env->menu_manager->medium_font, main_image);
	ft_sdl_put_text(value, (t_text){rect.x + 200, rect.y,
		rect.color, rect.align}, env->menu_manager->medium_font,
		main_image);
	free(value);
	return (SUCCESS);
}

int	ft_render_hud(t_doom_env *env)
{
	ft_place_label_value(env, "HEALTH: ",
		ft_itoa(env->main_inventory.health),
		(t_text){0, 5, 0xFFFFFF, 0});	
	ft_place_label_value(env, "SHIELD: ",
		ft_itoa(env->main_inventory.shield),
		(t_text){0, 35, 0xFFFFFF, 0});
	ft_place_label_value(env, "AMMO: ",
		ft_itoa(env->main_inventory.ammo[0]),
		(t_text){0, 65, 0xFFFFFF, 0});
	ft_draw_notifications(env);
	return (SUCCESS);
}
