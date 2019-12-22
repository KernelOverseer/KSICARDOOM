/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 02:11:29 by abiri             #+#    #+#             */
/*   Updated: 2018/10/10 20:36:01 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

static	int		alphasort(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
		{
			return (1);
		}
		else if (s1[i] < s2[i])
			return (0);
	}
	return (0);
}

void			ft_strsort(char **tab, int wordcount)
{
	int i;
	int j;

	i = 1;
	while (i < wordcount)
	{
		j = i;
		while (j < wordcount)
		{
			if (alphasort(tab[i], tab[j]))
			{
				swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}
