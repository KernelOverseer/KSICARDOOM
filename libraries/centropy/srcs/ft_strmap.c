/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:36:05 by merras            #+#    #+#             */
/*   Updated: 2018/10/13 04:25:30 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	slen;
	char	*fstr;
	char	*fstrdup;

	slen = ft_strlen(s);
	fstr = (char *)malloc(sizeof(char) * (slen + 1));
	if (fstr == NULL)
		return (NULL);
	fstrdup = fstr;
	while (*s)
	{
		*fstr = f(*s);
		s++;
		fstr++;
	}
	*fstr = '\0';
	return (fstrdup);
}
