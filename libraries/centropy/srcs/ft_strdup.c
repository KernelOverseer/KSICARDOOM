/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:05:01 by merras            #+#    #+#             */
/*   Updated: 2019/07/30 09:40:51 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	srclen;
	char	*dupdup;

	if (!src)
		return (NULL);
	srclen = ft_strlen(src);
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
