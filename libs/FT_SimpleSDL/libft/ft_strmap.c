/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:56:57 by abiri             #+#    #+#             */
/*   Updated: 2018/10/10 12:56:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	char				*result;
	char				*rendu;
	unsigned	int		length;

	rendu = NULL;
	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	if ((result = (char *)malloc(length + 1)))
	{
		rendu = result;
		while (*s)
			*(result++) = f(*(s++));
		*result = '\0';
	}
	return (rendu);
}
