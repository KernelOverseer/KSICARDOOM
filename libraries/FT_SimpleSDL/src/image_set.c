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
**	This function places a pixel on the image, in the given posision
**		and with the given color
*/

void		ft_sdl_set_image_pixel(t_sdl_image *image, int x, int y, Uint32 color)
{
	ft_sdl_image_pixel(image, x, y, (0xFF000000 | color));
}
