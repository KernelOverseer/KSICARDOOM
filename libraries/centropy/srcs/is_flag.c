/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:05:02 by merras            #+#    #+#             */
/*   Updated: 2019/08/03 16:07:17 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int		is_flag(char *flag, char *supported)
{
	while (*flag)
	{
		if (!ft_strchr(supported, *flag))
			return (0);
		flag++;
	}
	return (1);
}
