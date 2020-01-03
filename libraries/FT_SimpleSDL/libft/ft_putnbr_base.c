/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:52:02 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 20:19:22 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	checkbase(char *base)
{
	int i;
	int j;
	int leng;

	i = 0;
	leng = len(base);
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

int	ft_putnbr_base(long nbr, char *base)
{
	unsigned long	start;
	unsigned long	num;
	int				multip;
	char			numsize;

	start = 1;
	multip = len(base);
	numsize = 0;
	if (!checkbase(base))
		return (0);
	if (nbr == 0)
		ft_putchar(base[0]);
	num = (nbr < 0) ? -nbr : nbr;
	while (start <= num)
		start *= multip;
	if (start != num)
		start /= multip;
	while (start >= 1)
	{
		ft_putchar(base[num / start]);
		num = num % start;
		start /= multip;
		numsize++;
	}
	return (numsize ? numsize : 1);
}
