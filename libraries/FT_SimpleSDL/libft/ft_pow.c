/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:54:32 by abiri             #+#    #+#             */
/*   Updated: 2018/10/08 19:01:01 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int num, int power)
{
	int i;
	int result;

	i = 1;
	result = num;
	if (power < 0)
		return (-1);
	if (power == 0)
		return (1);
	while (i < power)
	{
		result *= num;
		i++;
	}
	return (result);
}
