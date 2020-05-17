/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 01:44:02 by abiri             #+#    #+#             */
/*   Updated: 2020/05/15 01:48:42 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void 		ft_reload_sprite_settings(t_doom_editor *env)
{
	t_tts_gui		*gui_env;
	t_gui_component	*component;

	gui_env = &(env->gui);
	ft_disable_area(&(env->gui), "wall_settings");
	ft_disable_area(&(env->gui), "portal_settings");
	ft_disable_area(&(env->gui), "sector_settings");
	ft_enable_area(&(env->gui), "sprite_settings");
	component = ft_get_component_by_id(gui_env, "sprite_prop_no_clip");
    if (component && env->event.selected)
        ((t_gui_checkbox *)component->data)->value =
                &(((t_sprite *)env->event.selected)->props);
	component = ft_get_component_by_id(gui_env, "sprite_prop_fixed_angle");
    if (component && env->event.selected)
        ((t_gui_checkbox *)component->data)->value =
                &(((t_sprite *)env->event.selected)->props);
	component = ft_get_component_by_id(gui_env, "sprite_radius_slider");
	if (component && env->event.selected)
		((t_gui_slider*)component->data)->value =
				&(((t_sprite *)env->event.selected)->radius);
	component = ft_get_component_by_id(gui_env, "sprite_height_slider");
	if (component && env->event.selected)
		((t_gui_slider*)component->data)->value =
				&(((t_sprite *)env->event.selected)->height);
	component = ft_get_component_by_id(gui_env, "sprite_altitude_slider");
	if (component && env->event.selected)
		((t_gui_slider*)component->data)->value =
				&(((t_sprite *)env->event.selected)->altitude);
	component = ft_get_component_by_id(gui_env, "sprite_angle_slider");
	if (component && env->event.selected)
		((t_gui_slider*)component->data)->value =
				&(((t_sprite *)env->event.selected)->angle);
	component = ft_get_component_by_id(gui_env, "sprite_speed_slider");
	if (component && env->event.selected)
		((t_gui_slider*)component->data)->value =
				&(((t_sprite *)env->event.selected)->animation.speed);
	component = ft_get_component_by_id(gui_env, "sprite_texture_1_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[0]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_2_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[1]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_3_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[2]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_4_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[3]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_5_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[4]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_6_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[5]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_7_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[6]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_8_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[7]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_9_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[8]);
		component = ft_get_component_by_id(gui_env, "sprite_texture_10_canvas");
	if (component && env->event.selected)
		component->data =
				&(((t_sprite *)env->event.selected)->animation.textures[9]);
	component = ft_get_component_by_id(gui_env, "sprite_texture_selector");
	if (component && env->event.selected)
	{
		((t_gui_texture_selector*)component->data)->texture_list_size =
			env->data.textures_count;
		((t_gui_texture_selector*)component->data)->texture_list =
			env->data.textures;
	}
}

t_gui_area	*ft_load_sprite_settings_gui(t_doom_editor	*env)
{
	t_tts_gui	*gui_env;
	t_gui_area	*result;

	gui_env = &(env->gui);
	if (!(result = ft_new_gui_area((t_rect){1528, 90, 378, 949}, "sprite_settings")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
            " NO CLIP ", UI_COLOR_BLACK, gui_env),
                         "sprite_no_clip_label");
    ft_gui_fit_component(result, ft_gui_new_checkbox((t_rect){0, 0, 210, 32},
            NULL, PROP_NO_CLIP), "sprite_prop_no_clip");
	    ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
            " FIXED ANGLE ", UI_COLOR_BLACK, gui_env),
                         "sprite_fixed_angle_label");
    ft_gui_fit_component(result, ft_gui_new_checkbox((t_rect){0, 0, 210, 32},
            NULL, PROP_FIXED_ANGLE), "sprite_prop_fixed_angle");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" RADIUS ", UI_COLOR_BLACK, &(env->gui)),
			"sprite_radius_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL, SPRITE_RADIUS_MIN, SPRITE_RADIUS_MAX), "sprite_radius_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" HEIGHT ", UI_COLOR_BLACK, &(env->gui)),
			"sprite_height_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL, 0, SECTOR_HEIGHT_MAX * 4), "sprite_height_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" ALTITUDE ", UI_COLOR_BLACK, &(env->gui)),
			"sprite_altitude_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL, SECTOR_HEIGHT_MIN, SECTOR_HEIGHT_MAX), "sprite_altitude_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" ANGLE ", UI_COLOR_BLACK, &(env->gui)),
			"sprite_angle_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL, 0, 2 * M_PI), "sprite_angle_slider");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 378, 64},
			" ANIMATION ", UI_COLOR_BLACK, gui_env),
						 "sprite_texture_label");
	ft_gui_fit_component(result, ft_gui_new_label((t_rect){0, 0, 154, 32},
			" SPEED ", UI_COLOR_BLACK, &(env->gui)),
			"sprite_speed_label");
	ft_gui_fit_component(result, ft_gui_new_slider((t_rect){0, 0, 210, 32},
			NULL, 0, 5), "sprite_speed_slider");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_1_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_2_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_3_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_4_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_5_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_6_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_7_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_8_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_9_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_display((t_rect){0, 0, 70, 70},
			NULL), "sprite_texture_10_canvas");
	ft_gui_fit_component(result, ft_gui_new_texture_selector((t_rect){0, 0, 380, 142},
			env->data.textures, env->data.textures_count, NULL),"sprite_texture_selector");
	return (result);
}