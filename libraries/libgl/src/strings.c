/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:50:04 by msidqi            #+#    #+#             */
/*   Updated: 2019/12/31 19:25:18 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int x;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		x = nb * -1;
	}
	else
	{
		x = nb;
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd(x % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(x + '0', fd);
	}
}
