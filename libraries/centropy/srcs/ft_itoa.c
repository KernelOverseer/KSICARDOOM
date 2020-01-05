/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:28:31 by merras            #+#    #+#             */
/*   Updated: 2018/10/13 05:16:31 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

static int		digits(long long int n)
{
	int	d;
	int s;

	d = 0;
	s = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		s = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		d++;
	}
	return (d + s);
}

char			*ft_itoa(int n)
{
	char		*numbs;
	int			i;
	int			digitcount;
	long int	nlong;

	i = 0;
	nlong = (long int)n;
	digitcount = digits(n);
	numbs = (char *)malloc(sizeof(char) * (digitcount + 1));
	if (numbs == NULL)
		return (NULL);
	if (n < 0)
	{
		numbs[i++] = '-';
		nlong = nlong * -1;
	}
	numbs[digitcount] = '\0';
	digitcount--;
	while (digitcount >= i)
	{
		numbs[digitcount] = (nlong % 10) + '0';
		nlong = nlong / 10;
		digitcount--;
	}
	return (numbs);
}
