/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:15:20 by merras            #+#    #+#             */
/*   Updated: 2019/08/17 15:57:15 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;
	size_t len1;
	size_t len2;

	if (!s1 || !s2)
		return (-1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (i <= len1 && i <= len2)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
