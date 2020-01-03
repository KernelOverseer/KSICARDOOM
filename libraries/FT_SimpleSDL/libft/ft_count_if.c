/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:54:50 by abiri             #+#    #+#             */
/*   Updated: 2018/10/11 13:21:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int ifcount;

	if (!tab || !f)
		return (-1);
	i = 0;
	ifcount = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]))
			ifcount++;
		i++;
	}
	return (ifcount);
}
