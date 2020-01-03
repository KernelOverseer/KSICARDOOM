/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:39:26 by merras            #+#    #+#             */
/*   Updated: 2018/10/13 04:56:16 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

static int	help(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		l;
	char	*trimmed;
	int		k;

	k = 0;
	j = 0;
	l = ft_strlen(s);
	i = help(s);
	k = l;
	while ((s[k - 1] == ' ' || s[k - 1] == '\n' || s[k - 1] == '\t') && i != l)
	{
		j++;
		k--;
	}
	k = 0;
	l = l - i - j;
	trimmed = (char *)malloc(sizeof(char) * (l + 1));
	if (trimmed == NULL)
		return (NULL);
	while (k < l)
		trimmed[k++] = s[i++];
	trimmed[k] = '\0';
	return (trimmed);
}
