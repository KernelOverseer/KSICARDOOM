/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunescape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:45:43 by abiri             #+#    #+#             */
/*   Updated: 2019/03/25 21:37:17 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strunescape(char *str)
{
	char	*result;
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] != '\\')
			counter--;
		counter++;
		i++;
	}
	result = ft_memalloc(counter + 1);
	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (str[i] == '\\' && str[i + 1] != '\\')
			continue ;
		result[counter++] = str[i];
	}
	return (result);
}
