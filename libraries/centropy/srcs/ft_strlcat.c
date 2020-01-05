/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:38:42 by merras            #+#    #+#             */
/*   Updated: 2018/10/10 21:13:58 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int siz;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j])
		++j;
	if (size <= i)
		j += size;
	else
		j += i;
	siz = 0;
	while (src[siz] && i + 1 < size)
	{
		dest[i] = src[siz];
		siz++;
		i++;
	}
	dest[i] = '\0';
	return (j);
}
