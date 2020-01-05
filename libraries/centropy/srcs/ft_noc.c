/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:00:32 by merras            #+#    #+#             */
/*   Updated: 2019/05/27 13:23:15 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_noc(char *str, char c)
{
	int		noccount;
	int		i;
	int		j;
	char	*noc;

	i = 0;
	noccount = 0;
	while (str[i])
	{
		if (str[i] != c)
			noccount++;
		i++;
	}
	noc = (char *)malloc(sizeof(char) * (noccount + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			noc[j++] = str[i];
		i++;
	}
	noc[j] = '\0';
	return (noc);
}
