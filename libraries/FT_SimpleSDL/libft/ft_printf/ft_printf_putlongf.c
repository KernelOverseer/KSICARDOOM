/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putlongf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:59:06 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 21:12:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*getbase(t_print *data, char base, unsigned long long nb)
{
	if (base == 'x')
		return (prefix(data, base, ft_itob(nb, HEX)));
	if (base == 'X')
		return (prefix(data, base, ft_itob(nb, HEX2)));
	if (base == 'o' || base == 'O')
		return (prefix(data, base, ft_itob(nb, OCTAL)));
	if (base == 'u')
		return (prefix(data, base, ft_itoalu((unsigned long)nb)));
	if (base == 'U')
		return (prefix(data, base, ft_itoalu((unsigned long)nb)));
	if (base == 'D')
		return (ft_itoal(nb));
	if (base == 'b')
		return (ft_itob((unsigned long long)nb, BINARY));
	return (ft_strdup(""));
}

static char	*putshort(long long nb, t_print *data)
{
	if ((data->arg)[1] == 'h')
	{
		if ((data->arg)[2] == 'd' || (data->arg)[2] == 'i')
			return (numsign(data, ft_itoal((signed char)nb)));
		if ((data->arg)[2] == 'D')
			return (numsign(data, ft_itoal((unsigned short int)nb)));
		if (ft_strchr("oxXub", data->arg[2]))
			return (getbase(data, data->arg[2], (unsigned char)nb));
		if (data->arg[2] == 'O')
			return (prefix(data, 'O', ft_itob(nb, OCTAL)));
		if (data->arg[2] == 'U')
			return (prefix(data, 'O', ft_itoalu(nb)));
	}
	if ((data->arg)[1] == 'd' || (data->arg)[1] == 'i')
		return (numsign(data, ft_itoal((short int)nb)));
	if ((data->arg)[1] == 'D')
		return (numsign(data, ft_itoal((int)nb)));
	if (ft_strchr("oOxXub", (data->arg)[1]))
		return (getbase(data, (data->arg)[1], (unsigned short int)nb));
	if (data->arg[1] == 'U')
		return (getbase(data, 'U', (unsigned long)nb));
	return (ft_strdup(""));
}

static char	*putlong(long long nb, t_print *data)
{
	if ((data->arg)[2] == 'p' || (data->arg)[1] == 'p')
	{
		(data->arg)[0] = 'p';
		return (ft_print_num(nb, data));
	}
	if ((data->arg)[1] == 'l')
	{
		if ((data->arg)[2] == 'd' || (data->arg)[2] == 'i')
			return (numsign(data, ft_itoal((long long)nb)));
		if (ft_strchr("oOxXuUDb", data->arg[2]))
			return (getbase(data, data->arg[2], (unsigned long long)nb));
	}
	if ((data->arg)[1] == 'd' || (data->arg)[1] == 'i')
		return (numsign(data, ft_itoal((long int)nb)));
	if (ft_strchr("oOxXuUDb", data->arg[1]))
		return (getbase(data, data->arg[1], (unsigned long)nb));
	return (ft_strdup(""));
}

static char	*putsizet(long long nb, t_print *data)
{
	if ((data->arg)[0] == 'z')
	{
		if (ft_tolower((data->arg)[1]) == 'd' || (data->arg)[1] == 'i')
			return (numsign(data, ft_itoal((size_t)nb)));
		if (ft_strchr("oOxXuUb", data->arg[1]))
			return (getbase(data, data->arg[1], (size_t)nb));
	}
	if ((data->arg)[0] == 'j')
	{
		if (ft_tolower((data->arg)[1]) == 'd' || (data->arg)[1] == 'i')
			return (numsign(data, ft_itoal((intmax_t)nb)));
		if (ft_strchr("oOxXuUb", data->arg[1]))
			return (getbase(data, data->arg[1], (uintmax_t)nb));
	}
	return (ft_strdup(""));
}

char		*ft_putlongf(long long nb, t_print *data)
{
	char	*result;

	result = ft_strdup("");
	if ((data->arg)[0] == 'l')
		result = putlong(nb, data);
	else if ((data->arg)[0] == 'h')
		result = putshort(nb, data);
	else if ((data->arg)[0] == 'j' || (data->arg)[0] == 'z')
		result = putsizet(nb, data);
	if (data->precis > -1)
		result = addzeros(result, data->fieldw - 1, data->precis);
	else if (ft_strchr(data->flags, '0'))
		result = addzeros(result, 0, data->fieldw - 1);
	data->precis = -2;
	result = ft_justify(data, result);
	return (result);
}
