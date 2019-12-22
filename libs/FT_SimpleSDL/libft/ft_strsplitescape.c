/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitescape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:49:17 by abiri             #+#    #+#             */
/*   Updated: 2019/03/25 20:49:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wordcount(const char *str, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (str[0] != c && str[0])
		word++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i - (i > 0)] != '\\')
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
				word++;
		}
		i++;
	}
	return (word);
}

static	int	wordlen(const char *str, char c)
{
	int	len;
	int i;

	len = 1;
	i = 0;
	if (str[i] == c)
		return (0);
	while (str[i + 1])
	{
		if (str[i + 1] == c && str[i] != '\\')
			break ;
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplitescape(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = wordcount(s, c);
	tab = (char **)malloc(sizeof(*tab) * wordcount(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub(s, 0, wordlen(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s += wordlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
