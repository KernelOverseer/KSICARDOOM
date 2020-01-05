/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:09:01 by merras            #+#    #+#             */
/*   Updated: 2018/10/12 15:54:05 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int bn;

	bn = nb;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		bn = 147483648;
	}
	if (bn < 0)
	{
		ft_putchar_fd('-', fd);
		bn = -bn;
	}
	if (bn < 10)
	{
		ft_putchar_fd(bn + '0', fd);
	}
	else
	{
		ft_putnbr_fd(bn / 10, fd);
		ft_putnbr_fd(bn % 10, fd);
	}
}
