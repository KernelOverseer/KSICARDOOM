/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:23:03 by abiri             #+#    #+#             */
/*   Updated: 2019/01/21 15:55:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getnextvar(char *str)
{
	int i;
	int l;

	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '$' || (str[i] != '\\' && str[i + 1] == '$'))
		{
			i += 1 + (str[i] != '$');
			while (ft_isalpha(str[i + l]) || str[i + l] == '_')
				l++;
			if (l)
				return (ft_strsub(str, i - 1, l + 1));
		}
		i++;
	}
	return (NULL);
}
