/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:25:00 by merras            #+#    #+#             */
/*   Updated: 2018/10/10 01:34:17 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*schar;

	schar = (char *)s;
	i = 0;
	if (c == '\0')
	{
		return (schar + ft_strlen(s));
	}
	while (schar[i] != '\0')
	{
		if (schar[i] == c)
		{
			return (schar + i);
		}
		i++;
	}
	return (NULL);
}
