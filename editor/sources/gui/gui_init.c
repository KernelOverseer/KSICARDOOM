/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:00:14 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 09:28:28 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

int		ft_gui_init(t_tts_gui *env, t_sdl_env *sdl, t_sdl_image *image)
{
	if(TTF_Init() == -1)
		return (0);
	ttslist_init(&(env->gui_areas));
	env->assets = ft_gui_load_assets();
	if (!env->assets)
		return (0);
	env->font = TTF_OpenFont(FONT_FILE, FONT_SIZE);
	if (!env->font)
		return (0);
	env->image = image;
	env->display_env = sdl;
	ft_sdl_hook(&ft_gui_mouse_event, env, SDL_MOUSEMOTION);
	ft_sdl_hook(&ft_gui_mouse_event, env, SDL_MOUSEBUTTONUP);
	ft_sdl_hook(&ft_gui_mouse_event, env, SDL_MOUSEBUTTONDOWN);
	ft_sdl_hook(&ft_gui_mouse_event, env, SDL_MOUSEWHEEL);
	return (1);
}