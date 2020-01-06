/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:43:32 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/16 17:43:54 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

static double	ft_atodigit(const char *str)
{
	double	res;
	int		i;

	if (str == NULL)
		return (0);
	res = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	return (res);
}

static int		ft_iswhitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n')
			|| (c == '\v') || (c == '\r') || (c == '\f'))
		return (1);
	return (0);
}

double			ft_atof(char *nbr)
{
	double	res;
	int		sign;
	double	dec;
	size_t	len;
	int		i;

	i = 0;
	if (nbr == NULL)
		return (0);
	while (nbr[i] && ft_iswhitespace(nbr[i]))
		i++;
	sign = nbr[i] == '-' ? 1 : 0;
	i += nbr[i] == '+' || nbr[i] == '-' ? 1 : 0;
	res = ft_atodigit(nbr + i);
	while (nbr[i] != '\0' && nbr[i] != '.')
		i++;
	len = nbr[i] != '\0' ? ft_strlen(nbr + i + 1) + 1 : 1;
	dec = nbr[i] != '\0' ? ft_atodigit(nbr + i + 1) : 0;
	while (--len > 0)
		dec = dec / 10;
	res += dec;
	res = sign == 1 ? -res : res;
	return (res);
}
