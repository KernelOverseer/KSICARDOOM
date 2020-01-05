/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 08:08:37 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 08:39:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

static t_gui_component	*ft_get_component_from_area(t_gui_area *area, char *id)
{
	t_gui_component *current_component;

	area->children.iterator = area->children.first;
	while ((current_component = ttslist_iter_content(&(area->children))))
	{
		if (current_component->id && ft_strequ(id, current_component->id))
			return (current_component);
	}
	return (NULL);
}

t_gui_area		*ft_get_area_by_id(t_tts_gui *gui_env, char *id)
{
	t_gui_area		*current_area;

	if (!id)
		return (NULL);
	gui_env->gui_areas.iterator = gui_env->gui_areas.first;
	while ((current_area = ttslist_iter_content(&(gui_env->gui_areas))))
	{
		if (current_area->id && ft_strequ(id, current_area->id))
			return (current_area);
	}
	return (NULL);
}

t_gui_component	*ft_get_component_by_id(t_tts_gui *gui_env, char *id)
{
	t_gui_area		*current_area;
	t_gui_component	*result;

	result = NULL;
	if (!id)
		return (NULL);
	gui_env->gui_areas.iterator = gui_env->gui_areas.first;
	while ((current_area = ttslist_iter_content(&(gui_env->gui_areas))))
	{
		result = ft_get_component_from_area(current_area, id);
		if (result)
			break ;
	}
	return (result);
}
