/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:09:01 by merras            #+#    #+#             */
/*   Updated: 2018/10/12 10:11:16 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	ft_putnbr(int nb)
{
	int bn;

	bn = nb;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		bn = 147483648;
	}
	if (bn < 0)
	{
		ft_putchar('-');
		bn = -bn;
	}
	if (bn < 10)
	{
		ft_putchar(bn + '0');
	}
	else
	{
		ft_putnbr(bn / 10);
		ft_putnbr(bn % 10);
	}
}
