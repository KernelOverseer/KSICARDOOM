/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putwchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:07:30 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 22:56:33 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putwstr(t_print *data, int *str)
{
	int res;
	int len;
	int *tofree;

	res = 0;
	if (!(tofree = str))
		str = L"(null)";
	if (ft_strequ(data->arg, "s") || ft_strequ(data->arg, "lls"))
		return (ft_putstrf((char *)str));
	len = ft_wstrlen_min(str, data->precis);
	while (data->fieldw-- > len && !ft_strchr(data->flags, '-') && ++res)
		ft_putchar((ft_strchr(data->flags, '0')) ? '0' : ' ');
	len = 0;
	while (*str && (len <= (data->precis - ft_wcharlen(*str))
				|| data->precis == -1))
	{
		len += ft_wcharlen(*str);
		ft_putwchar(*str++);
	}
	while (data->fieldw-- + 1 > len && ft_strchr(data->flags, '-') && ++res)
		ft_putchar(' ');
	free(tofree);
	return (res + len);
}

int	ft_putwcharf(t_print *data, int c)
{
	int		i;
	int		wlen;
	char	fill;

	fill = ' ';
	if (ft_strchr(data->flags, '0') && !ft_strchr(data->flags, '-'))
		fill = '0';
	i = -1;
	if (ft_strchr(data->arg, 'C') || ft_strequ(data->arg, "lc"))
		wlen = ft_wcharlen(c);
	else
		wlen = 1;
	if ((ft_strchr(data->arg, 'C') || ft_strequ(data->arg, "lc"))
			&& ft_strchr(data->flags, '-'))
		ft_putwchar(c);
	else if (ft_strchr(data->flags, '-'))
		ft_putchar(c);
	while (++i < data->fieldw - wlen)
		ft_putchar(fill);
	if ((ft_strchr(data->arg, 'C') || ft_strequ(data->arg, "lc"))
			&& !ft_strchr(data->flags, '-'))
		ft_putwchar(c);
	else if (!ft_strchr(data->flags, '-'))
		ft_putchar(c);
	return (i + wlen);
}
