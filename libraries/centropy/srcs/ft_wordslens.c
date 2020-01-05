/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordslens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:45:07 by merras            #+#    #+#             */
/*   Updated: 2019/05/27 13:09:52 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	*ft_wordslens(char const *s, char c)
{
	int i;
	int j;
	int k;
	int *wordslens;

	wordslens = (int *)malloc(sizeof(int) * (ft_wordscount(s, c) + 1));
	i = 0;
	k = -1;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			j = 0;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				j++;
			}
			wordslens[++k] = j;
		}
		else
			i++;
	}
	return (wordslens);
}
