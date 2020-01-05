/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:03:06 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 07:03:26 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int		array_length(char **array)
{
	int i;

	if (!array)
		return (0);
	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	print_array(char **array)
{
	int i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		ft_putendl(array[i]);
}
