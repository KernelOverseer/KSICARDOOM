/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 21:18:14 by abiri             #+#    #+#             */
/*   Updated: 2019/02/17 21:48:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_sep(const char *str, char c)
{
	return (ft_ischarin((char *)str, c));
}

static	int	wordcount(const char *str, const char *c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (!is_sep(c, str[0]) && str[0])
		word++;
	while (str[i] != '\0')
	{
		if (is_sep(c, str[i]))
		{
			if (!is_sep(c, str[i + 1]) && str[i + 1] != '\0')
				word++;
		}
		i++;
	}
	return (word);
}

static	int	wordlen(const char *s, char *c)
{
	int	len;

	len = 0;
	while (!is_sep(c, *s) && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplitcharset(char const *s, char *c)
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
		while (is_sep(c, *s) && *s != '\0')
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
