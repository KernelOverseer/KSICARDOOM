/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:47:07 by abiri             #+#    #+#             */
/*   Updated: 2018/10/11 13:25:22 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char*)(s1 + i)) != *((unsigned char*)(s2 + i)))
			return (*((unsigned char*)(s1 + i)) - (*(unsigned char*)(s2 + i)));
		i++;
	}
	return (0);
}
