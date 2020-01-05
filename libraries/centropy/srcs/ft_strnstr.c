/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:41:09 by merras            #+#    #+#             */
/*   Updated: 2018/10/12 15:09:52 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strnstr(const char *haysta, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*h;

	h = (char *)haysta;
	i = 0;
	if (need[0] == '\0')
		return (h);
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (h[k] == need[j] && h[k] != 0 && k < len)
		{
			j++;
			k++;
			if (need[j] == '\0')
				return (h + i);
		}
		i++;
	}
	return (NULL);
}
