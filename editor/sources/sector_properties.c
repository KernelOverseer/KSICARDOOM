/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:19:23 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 20:27:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void 		ft_reload_sector_settings(t_doom_editor *env)
{
	t_tts_gui		*gui_env;
	t_gui_component	*component;

	gui_env = &(env->gui);
	ft_disable_area(&(env->gui), "wall_settings");
	ft_disable_area(&(env->gui), "portal_settings");
	ft_enable_area(&(env->gui), "sector_settings");
	component = ft_get_component_by_id(gui_env, "sector_brightness_slider");
	if (component && env->data.current_sector)
		((t_gui_slider*)component->data)->value =
				&(env->data.current_sector->brightness);
	component = ft_get_component_by_id(gui_env, "sector_floor_slider");
	if (component && env->data.current_sector)
		((t_gui_slider*)component->data)->value =
				&(env->data.current_sector->floor_height);
	component = ft_get_component_by_id(gui_env, "sector_ceiling_slider");
	if (component && env->data.current_sector)
		((t_gui_slider*)component->data)->value =
				&(env->data.current_sector->ceil_height);
	component = ft_get_component_by_id(gui_env, "ceiling_texture_canvas");
	if (component && env->data.current_sector)
		component->data = &(env->data.current_sector->ceil_texture);
	component = ft_get_component_by_id(gui_env, "floor_texture_canvas");
	if (component && env->data.current_sector)
		component->data = &(env->data.current_sector->floor_texture);
	component = ft_get_component_by_id(gui_env, "sector_texture_selector");
	if (component && env->data.current_sector)
		((t_gui_texture_selector*)component->data)->to_change = &(env->data.current_sector->floor_texture);
}

t_gui_area	*ft_load_sector_settings_gui(t_doom_editor	*env)
{
	t_tts_gui	*gui_env;
	t_gui_area	*result;

	gui_env = &(env->gui);
	if (!(result = ft_new_gui_area((t_rect){1528, 90, 378, 649}, "sector_settings")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" BRIGHTNESS ", UI_COLOR_BLACK, &(env->gui)),
			"sector_brightness_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL,0, 1),"sector_brightness_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" FLOOR ", UI_COLOR_BLACK, gui_env),
						 "sector_floor_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL,0, 1000),"sector_floor_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" CEILING ", UI_COLOR_BLACK, gui_env),
						 "sector_ceiling_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL,0, 1000),"sector_ceiling_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 64},
			" CEILING TEXTURE ", UI_COLOR_BLACK, gui_env),
						 "ceiling_texture_label");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 210, 64},
			NULL),"ceiling_texture_canvas");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 64},
			" FLOOR TEXTURE ", UI_COLOR_BLACK, gui_env),
						 "floor_texture_label");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 210, 64},
			NULL),"floor_texture_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_selector((t_rect){0, 0, 380, 242},
			&(env->gui.assets[asset_render_placeholder + 1]), GUI_ASSET_COUNT, NULL),"sector_texture_selector");
	return (result);
}