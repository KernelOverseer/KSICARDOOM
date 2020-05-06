/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_interface_loading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:07:20 by abiri             #+#    #+#             */
/*   Updated: 2020/01/12 20:46:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void			ft_disable_other_buttons(t_gui_component *button)
{
	t_gui_area		*area;
	t_gui_component	*other;
	t_gui_button	*button_data;

	area = button->parent;
	area->children.iterator = area->children.first;
	while ((other = ttslist_iter_content(&(area->children))))
	{
		if (other->draw == ft_gui_button_draw && other != button)
		{
			button_data = other->data;
			if (button_data)
				button_data->always_on = 0;
		}
	}
	button_data = button->data;
	if (button_data)
		button_data->always_on = 1;
}

static void			ft_switch_mode_button(void *arg, t_gui_component *button)
{
	t_doom_editor	*gui_env;

	gui_env = arg;
	if (ft_strequ(button->id, "edit_mode_add"))
		gui_env->event.edit_mode = EDIT_MODE_ADD;
	else if (ft_strequ(button->id, "edit_mode_link_wall"))
		gui_env->event.edit_mode = EDIT_MODE_LINK_WALL;
	else if (ft_strequ(button->id, "edit_mode_link_portal"))
		gui_env->event.edit_mode = EDIT_MODE_LINK_PORTAL;
	else if (ft_strequ(button->id, "edit_mode_delete"))
		gui_env->event.edit_mode = EDIT_MODE_EDIT;
	ft_disable_other_buttons(button);
}

static void			ft_switch_edit_button(void *arg, t_gui_component *button)
{
	t_doom_editor	*env;
	t_tts_gui		*gui_env;
	t_gui_area		*to_disable;
	t_gui_area		*to_enable;

	env = arg;
	gui_env = &(env->gui);
	to_disable = ft_get_area_by_id(gui_env, "main_render_area");
	to_enable = ft_get_area_by_id(gui_env, "main_edit_area");
	if (to_enable)
		ACTIVATE_PROP(to_enable->props, GUI_ACTIVE);
	if (to_disable)
		DISACTIVATE_PROP(to_disable->props, GUI_ACTIVE);
	env->event.preview_mode = PREVIEW_EDIT;
	ft_disable_other_buttons(button);
}

static void			ft_switch_render_button(void *arg, t_gui_component *button)
{
	t_doom_editor	*env;
	t_tts_gui	*gui_env;
	t_gui_area	*to_disable;
	t_gui_area	*to_enable;

	env = arg;
	gui_env = &(env->gui);
	to_enable = ft_get_area_by_id(gui_env, "main_render_area");
	to_disable = ft_get_area_by_id(gui_env, "main_edit_area");
	if (to_enable)
		ACTIVATE_PROP(to_enable->props, GUI_ACTIVE);
	if (to_disable)
		DISACTIVATE_PROP(to_disable->props, GUI_ACTIVE);
	env->event.preview_mode = PREVIEW_RENDER;
	ft_disable_other_buttons(button);
}


static t_gui_area	*ft_load_editor_logo(t_tts_gui *gui_env)
{
	t_gui_area	*result;

	if (!(result = ft_new_gui_area((t_rect){0, 0, 406, 39}, "main_logo_area")))
		return (NULL);
	result->background_color = UI_COLOR_GREEN;
	ft_gui_add_component(result, ft_gui_new_label((t_rect){0, 0, 406, 39},
				" DOOM NUKEM EDITOR ", 0xFFFFFFFF, gui_env), "main_logo");
	return (result);
}

static t_gui_area	*ft_load_render_mode_bar(t_tts_gui *gui_env, t_doom_editor *env)
{
	t_gui_area		*result;
	t_gui_component	*button;

	if (!(result = ft_new_gui_area((t_rect){406, 0, 1109, 39}, "render_mode_bar")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
	button = ft_gui_new_button((t_rect){406, 0, 149, 39},
				ft_get_text_image(" EDIT ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_edit_button, env);
	((t_gui_button *)button->data)->always_on = 1;
	ft_gui_add_component(result, button, "render_mode_edit");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){555, 0, 149, 39},
				ft_get_text_image(" RENDER ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_render_button, env), "render_mode_render");
	return (result);
}

static t_gui_area	*ft_load_main_render_area(t_tts_gui *gui_env)
{
	t_gui_area	*result;

	(void)gui_env;
	if (!(result = ft_new_gui_area((t_rect){406, 39, 1109, 1002},
					"main_render_area")))
		return (NULL);
	result->background_color = UI_COLOR_GREEN;
	DISACTIVATE_PROP(result->props, GUI_ACTIVE);
	ft_gui_add_component(result,
			ft_gui_new_canvas((t_rect){408, 41, EDIT_WIDTH, EDIT_HEIGHT}, NULL),
			"main_render_canvas");
	return (result);
}

static t_gui_area	*ft_load_main_edit_area(t_tts_gui *gui_env)
{
	t_gui_area	*result;

	(void)gui_env;
	if (!(result = ft_new_gui_area((t_rect){406, 39, 1109, 1002},
					"main_edit_area")))
		return (NULL);
	result->background_color = UI_COLOR_BLACK;
	ft_gui_add_component(result,
			ft_gui_new_canvas((t_rect){408, 41, EDIT_WIDTH, EDIT_HEIGHT}, NULL),
			"main_edit_canvas");
	return (result);
}

static t_gui_area	*ft_load_add_select_delete_bar(t_tts_gui *gui_env, t_doom_editor *env)
{
	t_gui_area		*result;
	t_gui_component	*button;

	(void)env;
	if (!(result = ft_new_gui_area((t_rect){406, 1041, 1109, 39},
					"main_edit_area")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
	button = ft_gui_new_button((t_rect){406, 1041, 149, 39},
				ft_get_text_image(" POINT ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_mode_button, env);
	if (button)
		((t_gui_button*)button->data)->always_on = 1;
	ft_gui_add_component(result, button, "edit_mode_add");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){555, 1041, 149, 39},
				ft_get_text_image(" WALL ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_mode_button, env), "edit_mode_link_wall");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){704, 1041, 149, 39},
				ft_get_text_image(" PORTAL ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_mode_button, env), "edit_mode_link_portal");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){853, 1041, 149, 39},
				ft_get_text_image(" SPRITE ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_mode_button, env), "edit_mode_sprite");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){1002, 1041, 149, 39},
				ft_get_text_image(" EDIT ", (t_rect){0, 0, 149, 39}, 0x0, gui_env->font),
				ft_switch_mode_button, env), "edit_mode_delete");
	return (result);
}

static t_gui_area	*ft_load_sector_select_bar(t_tts_gui *gui_env, t_doom_editor *env)
{
	t_gui_area	*result;

	(void)gui_env;
	(void)env;
	if (!(result = ft_new_gui_area((t_rect){14, 90, 378, 439},
					"sector_select_area")))
		return (NULL);
	result->background_color = UI_COLOR_WHITE;
	return (result);	
}

static t_gui_area	*ft_load_sector_add_bar(t_tts_gui *gui_env, t_doom_editor *env)
{
	t_gui_area	*result;

	(void)gui_env;
	(void)env;
	if (!(result = ft_new_gui_area((t_rect){0, 39, 406, 39},
					"sector_select_area")))
		return (NULL);
	result->background_color = UI_COLOR_GREY;
	ft_gui_add_component(result, ft_gui_new_button((t_rect){343, 45, 46, 26},
				ft_get_text_image(" NEW ", (t_rect){0, 0, 46, 26}, UI_COLOR_BLACK, gui_env->font),
				ft_add_sector, env), "sector_create_new");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){17, 45, 46, 26},
				ft_get_text_image(" SAVE ", (t_rect){0, 0, 46, 26}, UI_COLOR_BLACK, gui_env->font),
				ft_save_map_data, env), "sector_create_new");
	ft_gui_add_component(result, ft_gui_new_button((t_rect){117, 45, 46, 26},
				ft_get_text_image(" LOAD ", (t_rect){0, 0, 46, 26}, UI_COLOR_BLACK, gui_env->font),
				ft_load_map_data, env), "sector_create_new");
	return (result);	
}

int		ft_main_interface_loading(t_tts_gui *gui_env, t_doom_editor *env)
{
	t_gui_area *area;

	gui_env->background_color = UI_COLOR_GREY;
	if (!(area = ft_load_editor_logo(gui_env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_render_mode_bar(gui_env, env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_main_render_area(gui_env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_main_edit_area(gui_env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_add_select_delete_bar(gui_env, env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_sector_select_bar(gui_env, env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_sector_add_bar(gui_env, env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_sector_settings_gui(env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_wall_settings_gui(env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	if (!(area = ft_load_portal_settings_gui(env)))
		return (0);
	gui_env->gui_areas.push(&(gui_env->gui_areas), area);
	return (1);
}
