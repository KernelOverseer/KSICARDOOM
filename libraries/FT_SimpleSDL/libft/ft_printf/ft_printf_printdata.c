/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:56:40 by abiri             #+#    #+#             */
/*   Updated: 2019/05/03 18:30:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdata(t_print *data, va_list list)
{
	int c;

	c = 0;
	if (data->fieldw == -5)
		data->fieldw = va_arg(list, int);
	if (ft_strchr(data->arg, '@'))
		ft_setcolor(data);
	else if (ft_strchr(data->arg, 'S') || ft_strequ(data->arg, "ls"))
		c += ft_putwstr(data, va_arg(list, int *));
	else if (ft_strchr(data->arg, 's'))
		c += ft_putwstr(data, (int *)ft_justify(data, va_arg(list, char *)));
	else if (ft_strchr(data->arg, 'c'))
		c += ft_putwcharf(data, va_arg(list, int));
	else if (ft_strchr(data->arg, 'C'))
		c += ft_putwcharf(data, va_arg(list, int));
	else if (ft_strchr("dDioOuUxXpb", data->arg[0]))
		c += ft_putstrf(ft_print_num(va_arg(list, long), data));
	else if (ft_strchr("hljz", data->arg[0]))
		c += ft_putstrf(ft_putlongf(va_arg(list, long), data));
	else
		c += ft_putstrf(data->arg);
	return (c);
}
