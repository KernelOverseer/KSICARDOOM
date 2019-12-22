/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_area_event_handlers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 08:18:03 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 08:35:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

void	ft_apply_component_handler(t_tts_gui *gui_env,
		t_gui_component *component, t_gui_component_function *handler,
		SDL_Event e)
{
	component->event.e = e;
	if (handler)
		handler(gui_env, component);
}
