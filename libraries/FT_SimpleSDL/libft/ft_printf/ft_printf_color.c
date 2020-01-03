/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:23:31 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 21:31:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setcolor(t_print *data)
{
	int text;
	int back;

	text = 39;
	back = 49;
	if (data->fieldw > -1)
		text = data->fieldw;
	if (data->precis > -1)
		text = data->precis;
	ft_startc(text);
	ft_startc(back);
}
