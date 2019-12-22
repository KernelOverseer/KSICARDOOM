/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:48:46 by abiri             #+#    #+#             */
/*   Updated: 2018/10/11 12:10:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char				*result;
	char				*rendu;
	unsigned	int		length;
	unsigned	int		i;

	i = 0;
	rendu = NULL;
	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	if ((result = (char *)malloc(length + 1)))
	{
		rendu = result;
		while (s[i])
		{
			*(result++) = f(i, s[i]);
			i++;
		}
		*result = '\0';
	}
	return (rendu);
}
