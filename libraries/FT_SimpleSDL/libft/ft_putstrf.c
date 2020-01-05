/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:09:43 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 22:57:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrf(char *str)
{
	int count;

	count = 0;
	while (str[count])
		ft_putchar(str[count++]);
	free(str);
	return (count);
}
