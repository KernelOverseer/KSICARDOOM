/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:26:07 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 04:22:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void 		ft_reload_portal_settings(t_doom_editor *env)
{
	t_tts_gui		*gui_env;
	t_gui_component	*component;

	gui_env = &(env->gui);
    ft_disable_area(&(env->gui), "sector_settings");
    ft_disable_area(&(env->gui), "wall_settings");
    ft_enable_area(&(env->gui), "portal_settings");
	component = ft_get_component_by_id(gui_env, "portal_texture_canvas");
	if (component && env->event.selected)
		component->data = &(((t_portal *)env->event.selected)->wall.texture);
    component = ft_get_component_by_id(gui_env, "portal_texture_selector");
    if (component && env->event.selected)
	{
        ((t_gui_texture_selector *)component->data)->to_change =
                &(((t_portal *)env->event.selected)->wall.texture);
		((t_gui_texture_selector*)component->data)->texture_list_size =
			env->data.textures_count;
		((t_gui_texture_selector*)component->data)->texture_list =
			env->data.textures;
	}
    component = ft_get_component_by_id(gui_env, "portal_sector");
    if (component && env->event.selected)
		((t_gui_int_label *)component->data)->sector =
			&(((t_portal *)env->event.selected)->sector);
}

t_gui_area	*ft_load_portal_settings_gui(t_doom_editor *env)
{
	t_tts_gui	*gui_env;
	t_gui_area	*result;

	gui_env = &(env->gui);
	if (!(result = ft_new_gui_area((t_rect){1528, 90, 378, 649}, "portal_settings")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 100, 64},
            " SECTOR ", UI_COLOR_BLACK, gui_env),
                         "portal_texture_label");
    ft_gui_fit_component(result, ft_gui_new_int_label((t_rect){0, 0, 250, 64},
		NULL, env), "portal_sector");
    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 100, 64},
            " TEXTURE ", UI_COLOR_BLACK, gui_env),
                         "portal_texture_label");
    ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 250, 64},
            NULL), "portal_texture_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_selector((t_rect){0, 0, 380, 242},
			env->data.textures, env->data.textures_count, NULL),
			        "portal_texture_selector");
	return (result);
}