/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:08:36 by merras            #+#    #+#             */
/*   Updated: 2019/12/19 06:03:26 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_simplesdl_memalloc(size_t size)
{
	int		*memloc;
	size_t	i;

	i = 0;
	memloc = (int *)malloc(sizeof(int) * size);
	if (memloc == NULL)
		return (NULL);
	while (i < size)
	{
		memloc[i] = 0;
		i++;
	}
	return (memloc);
}
