/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:48:47 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 18:56:34 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"

static Uint32 get_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;
	Uint32	*target_pixel;
	
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	target_pixel = (Uint32*)p;	
	return (*target_pixel);
}

t_sdl_image	*ft_get_text_image(char *text, t_rect rect, uint32_t color,
		TTF_Font *font)
{
	t_sdl_image	*result;
	SDL_Surface	*surface;

	surface = TTF_RenderText_Solid(font, text, (SDL_Color){255, 255, 255, 0});
	SDL_LockSurface(surface);
	if (surface->w < rect.w)
		rect.w = surface->w;
	if (surface->h < rect.h)
		rect.h = surface->h;
	result = newimage(rect.w, rect.h);
	for (int y = 0; y < result->height && y < surface->h; y++)
	{
		for (int x = 0; x < result->width && x < surface->w; x++)
		{
			result->pixels[y * result->width + x] =
		color | (RGB_A(get_pixel(surface, x, y)) << 24);
		}
	}	
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
	return (result);
}

