/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:29:41 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 17:21:12 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

/*
**	This function allocates a new image struct with the width and height given
*/

t_sdl_image	*newimage(int width, int height)
{
	t_sdl_image *image;

	image = malloc(sizeof(t_sdl_image));
	if (!image)
	{
		ft_sdl_error("FT_SDL: cannot allocate enough memory for image");
		return (NULL);
	}
	image->width = width;
	image->height = height;
	image->pixels = ft_simplesdl_memalloc(height * width * sizeof(Uint32));
	if (!image->pixels)
	{
		free(image);
		ft_sdl_error("FT_SDL: cannot allocate enough memory for image");
		return (NULL);
	}
	return (image);
}

/*
**	This function places a pixel on the image, in the given posision
**		and with the given color
*/

void		ft_sdl_image_pixel(t_sdl_image *image, int x, int y, Uint32 color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	image->pixels[y * image->width + x] = color;
}

/*
**	This function transforms the image into a texture stored in the env
**		ready to be rendered
*/

void		ft_sdl_put_image(t_sdl_image *image, t_sdl_env *env)
{
	SDL_UpdateTexture(env->texture, NULL, image->pixels,
			env->width * sizeof(Uint32));
}

/*
**	After turning the image into a texture this function renders the texture
**		with the renderer into the window in the same env struct
*/

void		ft_sdl_render_texture(t_sdl_env *env)
{
	SDL_RenderClear(env->renderer);
	SDL_RenderCopy(env->renderer, env->texture, NULL, NULL);
	SDL_RenderPresent(env->renderer);
}

/*
**	This function fills the given image with the color given
*/

void		ft_sdl_clear_image(t_sdl_image *image, Uint32 color)
{
	size_t i;
	size_t max;

	i = 0;
	max = image->width * image->height;
	while (i < max)
	{
		image->pixels[i] = color;
		i++;
	}
}
