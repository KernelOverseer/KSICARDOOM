/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:33:18 by abiri             #+#    #+#             */
/*   Updated: 2019/12/23 18:30:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"
#include <fcntl.h>

int		ft_sdl_load_image(char *filename, t_sdl_image *result)
{
	int			fd;
	int			size;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if (read(fd, &(result->width), 4) != 4)
		return (0);
	if (read(fd, &(result->height), 4) != 4)
		return (0);
	if ((size = result->width * result->height * 4) > MAX_IMAGE_SIZE)
		return (0);
	if (!(result->pixels = (Uint32 *)ft_simplesdl_memalloc(size)))
		return (0);
	if (read(fd, result->pixels, size) != size)
	{
		free(result->pixels);
		return (0);
	}
	return (1);
}
