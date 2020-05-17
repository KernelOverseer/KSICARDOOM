/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:51:27 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 05:00:17 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

static Uint32	get_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;
	Uint32	*target_pixel;
	
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	target_pixel = (Uint32*)p;	
	return (*target_pixel);
}

t_rect	ft_sdl_put_text(char *text, t_text info, TTF_Font *font,
	t_sdl_image *image)
{
	t_rect		off;
	SDL_Surface	*surface;

	surface = TTF_RenderText_Solid(font, text, (SDL_Color){255, 255, 255, 0});
	if (!surface)
		return ((t_rect){0, 0, 0, 0});
	off = (t_rect){info.x, info.y, surface->w, surface->h};
	if (info.align == ALIGN_CENTER_CENTER)
		off = (t_rect){info.x - (surface->w / 2),
			info.y - (surface->h / 2), surface->w, surface->h};
	SDL_LockSurface(surface);
	for (int y = 0; y < image->height && y < surface->h; y++)
	{
		for (int x = 0; x < image->width && x < surface->w; x++)
		{
			if (RGB_A(get_pixel(surface, x, y)))
				ft_sdl_set_image_pixel(image, off.x + x, off.y + y, info.color);
		}
	}	
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
	return (off);
}