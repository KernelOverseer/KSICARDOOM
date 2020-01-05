/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:15:41 by merras            #+#    #+#             */
/*   Updated: 2018/10/12 11:14:17 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dstdup;
	char	*srcdup;
	char	cuc;
	size_t	i;

	cuc = (unsigned char)c;
	dstdup = (char *)dst;
	srcdup = (char *)src;
	i = 0;
	while (srcdup[i] != cuc && i < n)
	{
		dstdup[i] = srcdup[i];
		i++;
	}
	if (srcdup[i] == cuc)
		dstdup[i] = cuc;
	if (i == n)
		return (NULL);
	return (dst + i + 1);
}
