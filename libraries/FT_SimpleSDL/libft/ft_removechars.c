/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removechars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:10:07 by abiri             #+#    #+#             */
/*   Updated: 2019/01/20 20:12:40 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_removechars(char **str, char toremove)
{
	char	*temp;
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *str;
	result = malloc(ft_strlen(temp) - ft_countchar(temp, toremove) + 1);
	while (temp[i])
	{
		if (temp[i] != toremove)
			result[j++] = temp[i];
		i++;
	}
	result[j] = '\0';
	free(temp);
	*str = result;
	return (result);
}
