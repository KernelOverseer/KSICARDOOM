/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:05:18 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:04:19 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

void	interfaceui(t_data *data)
{
	int i;

	i = 0;
	while (i < 70)
	{
		drawline(data, 1 + i, 3 + i, 0x111b1f);
		drawline(data, 4 + i, 6 + i, 0x212b2f);
		i += 6;
	}
	drawline(data, 71, 73, 0x550055);
	drawnsquares(data, 20);
}

void	interfacetext(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 2, 1, 0xEEEEEE, "Quit : ESC");
	mlx_string_put(data->mlx, data->win, 2, 20, 0xEEEEEE, "Move : Arrows");
	mlx_string_put(data->mlx, data->win, 2, 39, 0xEEEEEE, "Size : + -");
	mlx_string_put(data->mlx, data->win, 170, 1, 0xEEEEEE, "Alt    : 1 2");
	mlx_string_put(data->mlx, data->win, 170, 39, 0xEEEEEE, "Palette : 7 8");
	mlx_string_put(data->mlx, data->win, 170, 20, 0xEEEEEE, "Small Size  : 0");
}
