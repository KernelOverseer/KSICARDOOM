/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:42:19 by abiri             #+#    #+#             */
/*   Updated: 2018/10/11 13:30:34 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)(src + i)) == (unsigned char)c)
		{
			*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
			return ((unsigned char*)(dst + i + 1));
		}
		*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
		i++;
	}
	return (NULL);
}
