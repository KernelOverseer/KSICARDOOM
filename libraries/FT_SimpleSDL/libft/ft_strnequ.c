/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:50:16 by abiri             #+#    #+#             */
/*   Updated: 2018/10/08 18:11:28 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ended;

	i = 0;
	ended = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (!ended && i < n)
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				ended = 1;
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
