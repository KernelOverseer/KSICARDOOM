/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:05:01 by merras            #+#    #+#             */
/*   Updated: 2019/12/19 06:02:59 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_sdl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_simplesdl_strdup(const char *src)
{
	char			*dup;
	size_t			srclen;
	char			*dupdup;

	if (!src)
		return (NULL);
	srclen = ft_sdl_strlen(src);
	dup = malloc(sizeof(char) * (srclen + 1));
	if (dup == NULL)
		return (NULL);
	dupdup = dup;
	while (*src)
	{
		*dup = *src;
		src++;
		dup++;
	}
	*dup = '\0';
	return (dupdup);
}
