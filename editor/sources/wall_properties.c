/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_properties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:38:32 by abiri             #+#    #+#             */
/*   Updated: 2020/05/14 03:01:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void 		ft_reload_wall_settings(t_doom_editor *env)
{
	t_tts_gui		*gui_env;
	t_gui_component	*component;

	gui_env = &(env->gui);
	ft_disable_area(&(env->gui), "portal_settings");
	ft_disable_area(&(env->gui), "sector_settings");
	ft_disable_area(&(env->gui), "sprite_settings");
	ft_enable_area(&(env->gui), "wall_settings");
	component = ft_get_component_by_id(gui_env, "wall_texture_canvas");
	if (component && env->event.selected)
		component->data = &(((t_wall *)env->event.selected)->texture);
	component = ft_get_component_by_id(gui_env, "wall_prop_transparent");
	if (component && env->event.selected)
        ((t_gui_checkbox *)component->data)->value =
                &(((t_wall *)env->event.selected)->props);
	component = ft_get_component_by_id(gui_env, "wall_prop_no_clip");
    if (component && env->event.selected)
        ((t_gui_checkbox *)component->data)->value =
                &(((t_wall *)env->event.selected)->props);
    component = ft_get_component_by_id(gui_env, "wall_texture_selector");
    if (component && env->event.selected)
	{
        ((t_gui_texture_selector *)component->data)->to_change =
                &(((t_wall *)env->event.selected)->texture);
		((t_gui_texture_selector*)component->data)->texture_list_size =
			env->data.textures_count;
		((t_gui_texture_selector*)component->data)->texture_list =
			env->data.textures;
	}
}

t_gui_area	*ft_load_wall_settings_gui(t_doom_editor *env)
{
	t_tts_gui	*gui_env;
	t_gui_area	*result;

	gui_env = &(env->gui);
	if (!(result = ft_new_gui_area((t_rect){1528, 90, 378, 749}, "wall_settings")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
            " TRANSPARENT ", UI_COLOR_BLACK, gui_env),
                         "wall_transparent_label");
	ft_gui_fit_component(result, ft_gui_new_checkbox((t_rect){0, 0, 210, 32},
	        NULL, PROP_TRANSPARENT), "wall_prop_transparent");
    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
            " NO CLIP ", UI_COLOR_BLACK, gui_env),
                         "wall_no_clip_label");
    ft_gui_fit_component(result, ft_gui_new_checkbox((t_rect){0, 0, 210, 32},
            NULL, PROP_NO_CLIP), "wall_prop_no_clip");
    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 64},
            " TEXTURE ", UI_COLOR_BLACK, gui_env),
                         "wall_texture_label");
    ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 210, 64},
            NULL), "wall_texture_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_selector((t_rect){0, 0, 380, 342},
			env->data.textures, env->data.textures_count, NULL),
			        "wall_texture_selector");
	return (result);
}
