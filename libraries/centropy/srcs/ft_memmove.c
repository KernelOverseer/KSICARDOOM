/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:56:19 by merras            #+#    #+#             */
/*   Updated: 2018/10/12 11:39:24 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *holder;

	holder = (char *)malloc(sizeof(void) * len);
	if (holder != NULL)
	{
		ft_memcpy(holder, src, len);
		ft_memcpy(dst, holder, len);
		free(holder);
	}
	return (dst);
}
