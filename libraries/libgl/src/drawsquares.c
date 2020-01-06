/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:27:53 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:02:32 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

void	drawnsquares(t_data *data, int onedlen)
{
	int j;
	int x;

	x = 0;
	j = 0;
	while ((j / data->winwidth) < onedlen)
	{
		x = 0;
		while (x < onedlen)
		{
			data->image[151380 + j + x] = 0x30b1c3;
			data->image[151410 + j + x] = 0xabe9f0;
			data->image[151440 + j + x] = 0x9a4e00;
			data->image[151470 + j + x] = 0xba7e00;
			data->image[151500 + j + x] = 0xff6700;
			data->image[151530 + j + x] = 0xffa700;
			data->image[151560 + j + x] = 0xffF700;
			data->image[151590 + j + x] = 0xfcffcd;
			x++;
		}
		j += data->winwidth;
	}
}
