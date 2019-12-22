/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:49:55 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 21:06:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*addzeros(char *res, int zeroes, int p)
{
	char	*result;
	int		i;

	i = ft_strlen(res) - 1;
	if ((ft_strequ(res, "0")) && p == 0)
		return (ft_strdup(""));
	if ((ft_strequ(res, "00")) && p == 0)
		return (ft_strdup("0"));
	if (p != -1)
		zeroes = (ft_strchr(" -+", res[0])) ? p + 1 : p;
	if (zeroes <= i + 1)
		return (res);
	result = ft_memalloc(zeroes + 1);
	result = ft_memset(result, '0', zeroes--);
	if (ft_strchr(res, '-'))
		result[0] = '-';
	else if (ft_strchr(res, '+'))
		result[0] = '+';
	else if (ft_strchr(res, ' '))
		result[0] = ' ';
	while (i >= (result[0] != '0') && zeroes >= (result[0] != '0'))
		result[zeroes--] = res[i--];
	return (result);
}

char	*numsign(t_print *data, char *str)
{
	char *result;

	if (ft_strchr(data->flags, '+') && str[0] != '-')
		result = ft_strjoin("+", str);
	else if (ft_strchr(data->flags, ' ') && str[0] != '-' && str[0] != '+')
		result = ft_strjoin(" ", str);
	else
		return (str);
	free(str);
	return (result);
}

char	*prefix(t_print *data, char type, char *str)
{
	char *result;

	if (!ft_strchr(data->flags, '#') && type != 'p')
		return (str);
	if (type == 'x' && !ft_strzero(str))
		result = ft_strjoin("0x", str);
	else if (type == 'X' && !ft_strzero(str))
		result = ft_strjoin("0X", str);
	else if ((type == 'o' || type == 'O') && str[0] != '0')
		result = ft_strjoin("0", str);
	else if (type == 'p')
		result = ft_strjoin("0x", str);
	else
		return (str);
	free(str);
	return (result);
}

char	*ft_print_num(long long nb, t_print *data)
{
	char *result;

	if (ft_strequ(data->arg, "d") || ft_strequ(data->arg, "i"))
		result = numsign(data, ft_itoa((int)nb));
	else if (ft_strequ(data->arg, "D"))
		result = numsign(data, ft_itoal(nb));
	else if (ft_strequ(data->arg, "u"))
		result = ft_itoal((unsigned int)nb);
	else if (ft_strequ(data->arg, "U"))
		result = ft_itoalu((unsigned long long)nb);
	else if (ft_strchr("xXpb", (data->arg)[0]))
		result = ft_puthex(nb, data);
	else if (ft_strequ(data->arg, "o"))
		result = ft_itob((unsigned int)nb, OCTAL);
	else if (ft_strequ(data->arg, "O"))
		result = ft_itob((unsigned long)nb, OCTAL);
	if ((data->arg)[0] == 'p' && ft_strchr(data->flags, '0'))
		data->fieldw -= 2;
	if (data->precis > -1)
		result = addzeros(result, data->fieldw, data->precis);
	else if (ft_strchr(data->flags, '0') && data->align == 0)
		result = addzeros(result, data->fieldw, data->precis);
	data->precis = -2;
	result = ft_justify(data, prefix(data, (data->arg)[0], result));
	return (result);
}
