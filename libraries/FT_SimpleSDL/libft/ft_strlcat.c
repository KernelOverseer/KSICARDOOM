/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:02:27 by abiri             #+#    #+#             */
/*   Updated: 2018/10/11 13:15:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lengthdest;
	size_t	length;

	i = 0;
	lengthdest = ft_strlen(dst);
	j = lengthdest;
	length = lengthdest + ft_strlen(src);
	if (j >= size)
		return (length - j + size);
	while (src[i] != '\0' && (i + lengthdest) < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (length);
}
