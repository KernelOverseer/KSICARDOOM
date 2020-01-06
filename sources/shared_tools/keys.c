/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:21:50 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/06 11:21:52 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		key_code(SDL_Event event)
{
	return (event.key.keysym.scancode);
}

int		scan_code(SDL_Event event)
{
	return (event.key.keysym.sym);
}

int		scan_code_up(SDL_Event event)
{
	if (event.type == SDL_KEYUP)
		return (event.key.keysym.scancode);
	return (0);
}

int		scan_code_down(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		return (event.key.keysym.scancode);
	return (0);
}

int		ft_shift_is_down(void)
{
	return ((SDL_GetModState() & KMOD_SHIFT));
}
