/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:29:34 by abiri             #+#    #+#             */
/*   Updated: 2018/10/05 00:13:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occurence;
	int		ended;

	ended = 0;
	occurence = NULL;
	while (!ended)
	{
		if (*s == '\0')
			ended = 1;
		if (*s == c)
			occurence = (char *)s;
		s++;
	}
	return (occurence);
}
