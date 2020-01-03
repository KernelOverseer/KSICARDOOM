/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:46:52 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 19:46:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	append(char *str, int index, char c)
{
	str[index] = c;
}

static int	nbrsize(long long nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr % 10 != 0 || nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	nbrsizeu(unsigned long long nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr % 10 != 0 || nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoal(long long nbr)
{
	unsigned long	num;
	int				index;
	char			*result;

	index = nbrsize(nbr);
	result = ft_memalloc(index-- + 1);
	num = (nbr < 0) ? -nbr : nbr;
	if (nbr < 0)
		result[0] = '-';
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		append(result, index--, '0' + (num % 10));
		num /= 10;
	}
	return (result);
}

char		*ft_itoalu(unsigned long long nbr)
{
	int					index;
	char				*result;

	index = nbrsizeu(nbr);
	result = ft_memalloc(index-- + 1);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		append(result, index--, '0' + (nbr % 10));
		nbr /= 10;
	}
	return (result);
}
