/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:35:19 by abiri             #+#    #+#             */
/*   Updated: 2019/12/21 08:39:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include "centropy.h"
# include "ft_simplesdl.h"
# include "ttsgui.h"
# define WINDOW_WIDTH 540
# define WINDOW_HEIGHT 720

typedef struct	s_doom_editor
{
	t_sdl_env	*display_env;
	t_sdl_image	*main_image;
	t_tts_gui	gui;
}				t_doom_editor;

# endif
