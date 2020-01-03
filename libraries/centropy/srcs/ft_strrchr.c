/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:25:00 by merras            #+#    #+#             */
/*   Updated: 2018/10/10 01:40:57 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*schar;

	schar = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
	{
		return (schar + i);
	}
	while (i >= 0)
	{
		if (schar[i] == c)
		{
			return (schar + i);
		}
		i--;
	}
	return (NULL);
}
