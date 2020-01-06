/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawNline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:21:36 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:03:39 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

void	drawline(t_data *data, int startline, int nlines, int color)
{
	int p;
	int t;

	t = nlines * data->winwidth;
	p = (0 + data->winwidth * startline);
	while (p < t)
	{
		data->image[p] = color;
		p++;
	}
}
