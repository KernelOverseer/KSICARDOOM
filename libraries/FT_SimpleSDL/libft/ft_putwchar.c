/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:44:05 by abiri             #+#    #+#             */
/*   Updated: 2018/11/11 20:26:44 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(int unicode)
{
	if (unicode >= 0 && unicode <= 0x7f)
		ft_putchar(unicode);
	else if (unicode <= 0x7ff)
	{
		ft_putchar((unicode >> 6) | 192);
		ft_putchar((unicode & 63) | 128);
	}
	else if (unicode <= 0xffff)
	{
		ft_putchar((unicode >> 12) | 224);
		ft_putchar(((unicode >> 6) & 63) | 128);
		ft_putchar((unicode & 63) | 128);
	}
	else if (unicode <= 0x1fffff)
	{
		ft_putchar((unicode >> 18) | 240);
		ft_putchar(((unicode >> 12) & 63) | 128);
		ft_putchar(((unicode >> 6) & 63) | 128);
		ft_putchar((unicode & 63) | 128);
	}
}
