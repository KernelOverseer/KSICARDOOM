/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:26:12 by abiri             #+#    #+#             */
/*   Updated: 2018/10/07 11:13:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int				j;
	const	char	*t;

	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		t = haystack;
		j = 0;
		while (*haystack == needle[j] && needle[j] != '\0')
		{
			haystack++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)t);
		haystack = t + 1;
	}
	return (NULL);
}
