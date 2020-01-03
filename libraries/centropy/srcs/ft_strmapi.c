/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:11:50 by merras            #+#    #+#             */
/*   Updated: 2018/10/13 04:26:08 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	slen;
	char	*fstr;
	char	*fstrdup;
	int		i;

	i = 0;
	slen = ft_strlen(s);
	fstr = (char *)malloc(sizeof(char) * (slen + 1));
	if (fstr == NULL)
		return (NULL);
	fstrdup = fstr;
	while (*s)
	{
		*fstr = f(i, *s);
		s++;
		fstr++;
		i++;
	}
	*fstr = '\0';
	return (fstrdup);
}
