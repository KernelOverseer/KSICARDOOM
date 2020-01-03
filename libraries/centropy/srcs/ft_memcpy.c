/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:47:37 by merras            #+#    #+#             */
/*   Updated: 2018/10/09 18:56:07 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstdup;
	char	*srcdup;
	size_t	i;

	i = 0;
	dstdup = (char *)dst;
	srcdup = (char *)src;
	while (i < n && src != dst)
	{
		dstdup[i] = srcdup[i];
		i++;
	}
	return (dst);
}
