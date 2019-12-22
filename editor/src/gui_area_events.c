/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_area_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 08:57:54 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 12:15:24 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

void	ft_gui_component_mouse_event(t_tts_gui *env, t_gui_component *comp,
		SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (env->focused != comp)
			ft_apply_component_handler(env, comp, comp->event.on_focus, e);
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
		if (ft_is_mouse_in_component(component, e.button.x, e.button.y))
			break;
	}
	if (component)
		ft_gui_component_mouse_event(gui_env, component, e);
	area->children.iterator = NULL;
}

int		ft_remove_mouse_focus(t_tts_gui *gui_env, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONUP)
	{
		if (gui_env->focused)
			ft_apply_component_handler(gui_env, gui_env->focused,
					gui_env->focused->event.on_release, e);
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
	if (ft_remove_mouse_focus(gui_env, e))
		return (1);
	gui_env->gui_areas.iterator = gui_env->gui_areas.first;
	while ((gui_area = ttslist_iter_content(&(gui_env->gui_areas))))
	{
		if (ft_is_mouse_in_area(gui_area, e.button.x, e.button.y))
			break;
	}
	if (gui_area)
		ft_gui_area_mouse_event(gui_area, gui_env, e);
	gui_env->gui_areas.iterator = NULL;
	return (1);
}
