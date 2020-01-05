/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:54:12 by merras            #+#    #+#             */
/*   Updated: 2019/08/03 16:06:47 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	ft_strsplit_cleanup(char **last, int *wordsize, char *noc)
{
	*last = NULL;
	free(wordsize);
	free(noc);
}

char	**ft_strsplit(char const *s, char c)
{
	char		**fstr;
	char		*noc;
	int			*wordsize;
	t_3tuple	i;

	i.i = -1;
	noc = ft_noc((char *)s, c);
	wordsize = ft_wordslens(s, c);
	fstr = (char **)malloc(sizeof(char *) * (ft_wordscount(s, c) + 1));
	if ((i.k = -1) && fstr == NULL)
		return (NULL);
	while (++i.i < ft_wordscount(s, c))
	{
		fstr[i.i] = (char *)malloc(sizeof(char) * (wordsize[i.i] + 1));
		if ((i.j = -1) && fstr[i.i] == NULL)
			continue;
		while (++i.j < wordsize[i.i])
			fstr[i.i][i.j] = noc[++i.k];
		fstr[i.i][i.j] = '\0';
	}
	ft_strsplit_cleanup(&(fstr[i.i]), wordsize, noc);
	return (fstr);
}
