/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:21:12 by merras            #+#    #+#             */
/*   Updated: 2018/10/09 13:38:51 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *dstdup;

	dstdup = dst;
	while (*src && len > 0)
	{
		*dst = *src;
		src++;
		dst++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (dstdup);
}
