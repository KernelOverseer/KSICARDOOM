/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:26:12 by abiri             #+#    #+#             */
/*   Updated: 2018/10/08 14:20:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len2;

	if (*s2 == '\0')
		return ((char *)s1);
	len2 = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= len2)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, len2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
