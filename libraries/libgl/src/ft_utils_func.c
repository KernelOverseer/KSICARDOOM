/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:17:26 by msidqi            #+#    #+#             */
/*   Updated: 2019/05/02 03:17:27 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libgl.h"

void		ft_color_change(int *col, t_data *data)
{
	int				tmp;
	unsigned char	*ptr;

	tmp = *col;
	ptr = (unsigned char*)col;
	ptr[0] = data->color.blue * (tmp) / MAX_ITER;
	ptr[1] = data->color.green * (tmp) / MAX_ITER;
	ptr[2] = data->color.red * (tmp) / MAX_ITER;
}

double		ft_get_world_pos(double screen_coord, double widheight, double zoom)
{
	return (((screen_coord - widheight / 2) / zoom));
}

double		lerp(double x1, double x2, double lerp)
{
	return (x1 + lerp * (x2 - x1));
}

t_vec2		ft_vec2_lerp(t_vec2 v1, t_vec2 v2, double lrp)
{
	return ((t_vec2){lerp(v1.x, v2.x, lrp), lerp(v1.y, v2.y, lrp)});
}

double	ft_lerp(double goal, double current, double delta_time)
{
	double diff;

	diff = goal - current;
	if (diff > delta_time)
		return (current + delta_time);
	if (diff < -delta_time)
		return (current - delta_time);
	return (goal);
}
