/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_area_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 08:57:54 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 17:40:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

void	ft_gui_component_mouse_event(t_tts_gui *env, t_gui_component *comp,
		SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (env->focused != comp && !GET_PROP(comp->props, GUI_NEVER_FOCUS))
			ft_apply_component_handler(env, comp, comp->event.on_focus, e);
		if (!GET_PROP(comp->props, GUI_NEVER_FOCUS))
			env->focused = comp;
		ft_apply_component_handler(env, comp, comp->event.on_click, e);
	}
	else if (e.type == SDL_MOUSEMOTION)
	{
		env->hovered = comp;
		ft_apply_component_handler(env, comp, comp->event.on_hover, e);
	}
	else if (e.type == SDL_MOUSEWHEEL)
		ft_apply_component_handler(env, comp, comp->event.on_mouse_wheel, e);
}

void	ft_gui_area_mouse_event(t_gui_area *area, t_tts_gui *gui_env,
		SDL_Event e)
{
	t_gui_component	*component;

	area->children.iterator = area->children.first;
	while ((component = ttslist_iter_content(&(area->children))))
	{
		if (GET_PROP(component->props, GUI_ACTIVE) &&
				ft_is_mouse_in_component(component, gui_env->mouse_position.x,
					gui_env->mouse_position.y))
			break ;
	}
	if (component)
		ft_gui_component_mouse_event(gui_env, component, e);
	area->children.iterator = NULL;
}

int		ft_remove_mouse_focus(t_tts_gui *gui_env, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
	{
		if (gui_env->focused && GET_PROP(gui_env->focused->props, GUI_ACTIVE))
		{
			ft_apply_component_handler(gui_env, gui_env->focused,
					gui_env->focused->event.on_release, e);
			if (GET_PROP(gui_env->focused->props, GUI_NEVER_FOCUS))
				gui_env->focused = NULL;
		}
		return (1);
	}
	if (e.type == SDL_MOUSEMOTION)
		gui_env->hovered = NULL;
	return (0);
}

int		ft_gui_mouse_event(void *arg, SDL_Event e)
{
	t_tts_gui	*gui_env;
	t_gui_area	*gui_area;

	gui_env = arg;
	SDL_GetMouseState(&(gui_env->mouse_position.x), &(gui_env->mouse_position.y));
	if (ft_remove_mouse_focus(gui_env, e))
		return (1);
	gui_env->gui_areas.iterator = gui_env->gui_areas.first;
	while ((gui_area = ttslist_iter_content(&(gui_env->gui_areas))))
	{
		if (GET_PROP(gui_area->props, GUI_ACTIVE) &&
				ft_is_mouse_in_area(gui_area, gui_env->mouse_position.x,
					gui_env->mouse_position.y))
			break ;
	}
	if (gui_area)
		ft_gui_area_mouse_event(gui_area, gui_env, e);
	gui_env->gui_areas.iterator = NULL;
	return (1);
}