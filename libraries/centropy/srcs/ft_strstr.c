/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:41:09 by merras            #+#    #+#             */
/*   Updated: 2018/10/10 02:37:35 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*h;

	h = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		k = i;
		while (h[k] == needle[j] && h[k] != 0)
		{
			j++;
			k++;
			if (needle[j] == '\0')
			{
				return (h + i);
			}
		}
		i++;
	}
	return (NULL);
}
