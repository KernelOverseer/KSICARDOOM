/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:43:58 by merras            #+#    #+#             */
/*   Updated: 2019/06/24 17:24:36 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	int		slen1;
	int		slen2;
	int		i;
	int		j;

	i = -1;
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	joint = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (joint == NULL)
		return (NULL);
	while (++i < slen1)
		joint[i] = s1[i];
	j = 0;
	while (j < slen2)
	{
		joint[i] = s2[j];
		i++;
		j++;
	}
	joint[i] = '\0';
	return (joint);
}
