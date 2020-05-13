/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:33:18 by abiri             #+#    #+#             */
/*   Updated: 2020/05/13 00:34:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"
#include <fcntl.h>

Uint32	ft_sdl_get_image_pixel(t_sdl_image *image, int x, int y)
{
	if (!image || !image->pixels)
		return (DEFAULT_EMPTY_PIXEL);
	x %= image->width;
	y %= image->height;
	if (x < 0)
		x += image->width;
	if (y < 0)
		y += image->height;
	return (image->pixels[y * image->width + x]);
}

int		ft_sdl_load_image(char *filename, t_sdl_image *result)
{
	int			fd;
	int			size;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (IMAGE_ERROR_file);
	if (read(fd, &(result->width), 4) != 4)
		return (IMAGE_ERROR_format);
	if (read(fd, &(result->height), 4) != 4)
		return (IMAGE_ERROR_format);
	if ((size = result->width * result->height * 4) > MAX_IMAGE_SIZE)
		return (IMAGE_ERROR_size_limit);
	if (!(result->pixels = (Uint32 *)ft_simplesdl_memalloc(size)))
		return (IMAGE_ERROR_memory);
	if (read(fd, result->pixels, size) != size)
	{
		free(result->pixels);
		return (IMAGE_ERROR_size);
	}
	close(fd);
	return (1);
}
