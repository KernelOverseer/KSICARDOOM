/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:10:35 by abiri             #+#    #+#             */
/*   Updated: 2018/10/07 10:10:17 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	append(char *str, char c, int index)
{
	str[index] = c;
}

static	void	neg(long int *nbim, int *index, char *final)
{
	if (*nbim < 0)
	{
		append(final, '-', (*index)++);
		*nbim = *nbim * (-1);
	}
}

char			*ft_itoa(int nb)
{
	char		arr[12];
	char		*final;
	int			c;
	long	int	nbim;
	int			index;

	c = 0;
	index = 0;
	nbim = nb;
	if (!(final = (char *)malloc(12)))
		return (NULL);
	if (nbim == 0)
		append(final, '0', index++);
	neg(&nbim, &index, final);
	while (nbim != 0)
	{
		arr[c] = ((nbim % 10) + '0');
		nbim /= 10;
		c++;
	}
	while ((c - 1) >= 0)
		append(final, arr[--c], index++);
	final[index] = '\0';
	return (final);
}
