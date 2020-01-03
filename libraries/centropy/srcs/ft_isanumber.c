/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isanumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:46:05 by merras            #+#    #+#             */
/*   Updated: 2019/10/25 05:54:47 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	ft_isanumber(char *string, int flags)
{
	int i;

	if (!string || (string[0] == '0' && string[1] != 0))
		return (0);
	i = -1;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]))
		{
			if (!i && string[i] == '-' && F_GET(flags, POSITIVE_NEGATIVE))
				continue;
			return (0);
		}
	}
	return (1);
}
