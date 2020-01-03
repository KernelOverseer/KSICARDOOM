/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:45:54 by abiri             #+#    #+#             */
/*   Updated: 2018/10/10 01:44:34 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char		arr[12];
	int			c;
	long	int	nbim;

	c = 0;
	nbim = nb;
	if (nbim == 0)
		ft_putchar('0');
	if (nbim < 0)
	{
		ft_putchar('-');
		nbim *= (-1);
	}
	while (nbim != 0)
	{
		arr[c] = ((nbim % 10) + '0');
		nbim /= 10;
		c++;
	}
	while ((c - 1) >= 0)
	{
		ft_putchar(arr[c - 1]);
		c--;
	}
}
