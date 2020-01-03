/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:25 by abiri             #+#    #+#             */
/*   Updated: 2018/11/07 20:15:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wcharlen(int unicode)
{
	if (unicode >= 0 && unicode <= 0x7f)
		return (1);
	if (unicode <= 0x7ff)
		return (2);
	if (unicode <= 0xffff)
		return (3);
	if (unicode <= 0x1fffff)
		return (4);
	return (0);
}
