/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:15:36 by merras            #+#    #+#             */
/*   Updated: 2019/08/02 19:31:48 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

static void		ft_strdel_dispatcher(char *s1, char *s2, char p)
{
	if (p == 1)
		free(s1);
	else if (p == 2)
		free(s2);
	else if (p == 3)
	{
		free(s1);
		free(s2);
	}
}

char			*ft_strjoin_free(char *s1, char *s2, int p)
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
	ft_strdel_dispatcher(s1, s2, p);
	return (joint);
}
