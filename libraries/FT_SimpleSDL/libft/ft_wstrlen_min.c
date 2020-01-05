/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:40:27 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 20:15:46 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrlen_min(int *str, int min)
{
	int result;

	result = 0;
	if (min < 0)
		return (ft_wstrlen(str));
	while (*str && result + ft_wcharlen(*str) <= min)
		result += ft_wcharlen(*str);
	return (result);
}
