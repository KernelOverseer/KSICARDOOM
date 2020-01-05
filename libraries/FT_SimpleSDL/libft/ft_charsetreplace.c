/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charsetreplace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:50:37 by abiri             #+#    #+#             */
/*   Updated: 2019/01/20 20:11:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_charsetreplace(char *str, char *chars, char newchar)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_ischarin(chars, str[i]))
			str[i] = newchar;
		i++;
	}
}
