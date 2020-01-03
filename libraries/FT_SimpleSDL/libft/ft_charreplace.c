/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:23:06 by abiri             #+#    #+#             */
/*   Updated: 2019/01/19 14:50:25 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_charreplace(char *str, char from, char to)
{
	int found;

	found = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == from)
		{
			found++;
			*str = to;
		}
		str++;
	}
	return (found);
}
