/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:44:35 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 21:09:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puthex(long long nb, t_print *data)
{
	if (ft_strchr(data->arg, 'b'))
		return (ft_itob((unsigned int)nb, BINARY));
	if (ft_strchr(data->flags, '#') && ft_strchr(data->flags, '0')
			&& !(ft_strchr(data->flags, '-')))
		data->fieldw -= 2;
	if (ft_strequ(data->arg, "x"))
		return (ft_itob((unsigned int)nb, HEX));
	if (ft_strchr(data->arg, 'X'))
		return (ft_itob((unsigned int)nb, HEX2));
	return (ft_itob(nb, HEX));
}
