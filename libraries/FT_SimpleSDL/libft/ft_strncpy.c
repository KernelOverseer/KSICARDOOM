/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:25:17 by abiri             #+#    #+#             */
/*   Updated: 2018/10/04 14:44:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned	int	i;
	char			*arr;

	i = 0;
	arr = dest;
	while (*src && i < len)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	while (i < len)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (arr);
}
