/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:59:44 by abiri             #+#    #+#             */
/*   Updated: 2020/01/19 20:01:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

int	ft_apply_brightness(double brightness, int color)
{
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;

	red = ft_max(brightness * (double)RGB_R(color), 255);
	green = ft_max(brightness * (double)RGB_G(color), 255);
	blue = ft_max(brightness * (double)RGB_B(color), 255);
	return (red << 16 | green << 8 | blue);
}

void	ft_set_image_pixel(t_graphical_scene *scene, int x, int y, int color)
{
	int index;
	int jndex;

	index = 0;
	while (index < scene->resolution_ratio)
	{
		jndex = 0;
		while (jndex < scene->resolution_ratio)
		{
			ft_sdl_set_image_pixel(scene->render_image, x + index,
				y + jndex, color);
			jndex++;
		}
		index++;
	}
}
