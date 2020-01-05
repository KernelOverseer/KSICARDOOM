/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:02 by abiri             #+#    #+#             */
/*   Updated: 2018/10/09 23:51:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	number;
	int			i;

	i = 0;
	number = 0;
	if ((str[0] >= 9 && str[0] <= 13) || str[0] == ' ')
		return (ft_atoi(++str));
	if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
	{
		number = ft_atoi(++str);
		return (number * -1);
	}
	if (str[0] == '+' && str[1] >= '0' && str[1] <= '9')
		number = ft_atoi(++str);
	else if (str[0] != '-')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			number = (number * 10) + (str[i] - '0');
			++i;
		}
	}
	return ((int)number);
}
