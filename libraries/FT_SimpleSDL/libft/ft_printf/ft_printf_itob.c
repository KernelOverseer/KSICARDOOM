/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itob.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:48:34 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 19:48:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	append(char *str, int index, char c)
{
	str[index] = c;
}

static int	checkbase(char *base)
{
	int i;
	int j;
	int leng;

	i = 0;
	leng = ft_strlen(base);
	while (i < leng)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (j < leng)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

static int	nbrsize(unsigned long long nbr, int base)
{
	long long			i;
	unsigned long long	count;

	i = 0;
	count = 1;
	if (nbr == 0)
		return (1);
	while (nbr % base != 0 || nbr / base != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_itob(unsigned long long nbr, char *base)
{
	unsigned long long	num;
	int					multip;
	int					index;
	int					i;
	char				*result;

	multip = ft_strlen(base);
	index = nbrsize(nbr, multip);
	result = ft_memalloc(index-- + 1);
	num = (unsigned long long)nbr;
	if (!checkbase(base))
		return (ft_strdup(""));
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		i = (num % multip);
		append(result, index--, base[i]);
		num /= multip;
	}
	return (result);
}
