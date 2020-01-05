/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:10:11 by merras            #+#    #+#             */
/*   Updated: 2018/10/12 11:40:14 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*sstr;

	i = 0;
	sstr = (char *)s;
	while (i < n)
	{
		if (sstr[i] == c)
			return (sstr + i);
		i++;
	}
	return (NULL);
}
