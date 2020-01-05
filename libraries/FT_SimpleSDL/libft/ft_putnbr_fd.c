/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:44:28 by abiri             #+#    #+#             */
/*   Updated: 2018/10/06 23:23:59 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char		arr[12];
	int			c;
	long	int	nbim;

	c = 0;
	nbim = nb;
	if (nbim == 0)
		ft_putchar_fd('0', fd);
	if (nbim < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(arr[c - 1], fd);
		c--;
	}
}
