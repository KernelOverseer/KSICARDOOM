/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:35:35 by abiri             #+#    #+#             */
/*   Updated: 2019/05/03 18:22:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_freeprint(t_print *data, char *tofree)
{
	if (data)
	{
		free(data->arg);
		free(data->flags);
		free(data);
	}
	if (tofree)
		free(tofree);
	return (1);
}

static char	*ft_init(char **copy, const char *format,
		int *result, t_print **data)
{
	*data = NULL;
	*result = 0;
	*copy = ft_strdup(format);
	return (*copy);
}

int			ft_printf(const char *format, ...)
{
	va_list	list;
	char	*copy;
	char	*duped;
	int		result;
	t_print	*data;

	va_start(list, format);
	duped = ft_init(&copy, format, &result, &data);
	while (*copy)
	{
		if (*copy == '%' && (copy++))
		{
			if (ft_freeprint(data, NULL) && !(data = parse(&copy)))
				break ;
			if (!(data->arg)[0] && *(copy))
				result += ft_putwcharf(data, *(copy++));
			else if ((data->arg)[0])
				result += ft_printdata(data, list);
		}
		else if (result++ || 1)
			ft_putchar(*(copy++));
	}
	va_end(list);
	ft_freeprint(data, duped);
	return (result);
}
