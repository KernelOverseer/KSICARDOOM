/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:02:19 by merras            #+#    #+#             */
/*   Updated: 2018/10/13 04:24:17 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (size + 1));
	if (newstr == NULL)
		return (NULL);
	while (i <= size)
	{
		newstr[i] = '\0';
		i++;
	}
	return (newstr);
}
