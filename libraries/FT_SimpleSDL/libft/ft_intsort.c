/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 02:12:13 by abiri             #+#    #+#             */
/*   Updated: 2018/10/11 13:32:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_intsort(int *tab, int size)
{
	int i;
	int j;
	int temp;
	int good;

	i = 0;
	j = 0;
	good = 1;
	while (i++ < size)
	{
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			else
				good += 1;
			j++;
		}
	}
	if (good < size)
		ft_intsort(tab, size);
}
