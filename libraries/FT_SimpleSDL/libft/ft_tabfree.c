/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:43:59 by abiri             #+#    #+#             */
/*   Updated: 2019/01/25 23:13:25 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabfree(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (1);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}
