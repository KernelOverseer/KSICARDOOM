/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:40:09 by merras            #+#    #+#             */
/*   Updated: 2018/10/10 15:39:58 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *bdup;

	bdup = (unsigned char *)b;
	while (len > 0)
	{
		*bdup = c;
		bdup++;
		len--;
	}
	return (b);
}
