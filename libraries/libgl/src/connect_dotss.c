/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:46:27 by msidqi            #+#    #+#             */
/*   Updated: 2019/05/14 15:46:28 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

static void		plotlinelow(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int			var[4];
	t_vec2		tmp;

	var[1] = b.x - a.x;
	var[2] = b.y - a.y;
	var[3] = 1;
	if (var[2] < 0)
	{
		var[3] = -1;
		var[2] = -var[2];
	}
	var[0] = 2 * var[2] - var[1];
	tmp.y = a.y;
	tmp.x = a.x;
	while (tmp.x <= b.x)
	{
		ft_image_fill(data, tmp.x, tmp.y, color);
		if (var[0] > 0)
		{
			tmp.y = tmp.y + var[3];
			var[0] = var[0] - 2 * var[1];
		}
		var[0] = var[0] + 2 * var[2];
		tmp.x++;
	}
}

static void		plotlinehigh(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int			var[4];
	t_vec2		tmp;

	var[1] = b.x - a.x;
	var[2] = b.y - a.y;
	var[3] = 1;
	if (var[1] < 0)
	{
		var[3] = -1;
		var[1] = -var[1];
	}
	var[0] = 2 * var[1] - var[2];
	tmp.x = a.x;
	tmp.y = a.y;
	while (tmp.y <= b.y)
	{
		ft_image_fill(data, tmp.x, tmp.y, color);
		if (var[0] > 0)
		{
			tmp.x = tmp.x + var[3];
			var[0] = var[0] - 2 * var[2];
		}
		var[0] = var[0] + 2 * var[1];
		tmp.y++;
	}
}

void			connect_dotss(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	if (fabs(b.y - a.y) < fabs(b.x - a.x))
	{
		if (a.x > b.x)
			plotlinelow(data, b, a, color);
		else
			plotlinelow(data, a, b, color);
	}
	else
	{
		if (a.y > b.y)
			plotlinehigh(data, b, a, color);
		else
			plotlinehigh(data, a, b, color);
	}
}
