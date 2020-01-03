/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:02:30 by merras            #+#    #+#             */
/*   Updated: 2019/10/23 23:02:31 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	ft_isnumber(char *string)
{
	int i;

	if (!string)
		return (0);
	i = -1;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]))
		{
			if (i == 0 && string[i] == '-')
				continue;
			return (0);
		}
	}
	return (1);
}
