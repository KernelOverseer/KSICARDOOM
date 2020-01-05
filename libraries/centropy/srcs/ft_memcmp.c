/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:50:57 by merras            #+#    #+#             */
/*   Updated: 2018/10/09 20:18:06 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1s;
	unsigned char	*s2s;

	i = 0;
	s1s = (unsigned char *)s1;
	s2s = (unsigned char *)s2;
	while (i < n)
	{
		if (s1s[i] != s2s[i])
			return (s1s[i] - s2s[i]);
		i++;
	}
	return (0);
}
