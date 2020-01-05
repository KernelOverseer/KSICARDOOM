/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:23:09 by abiri             #+#    #+#             */
/*   Updated: 2018/10/09 23:26:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		diff = ft_memcmp(&s1[i], &s2[i], 1);
		if (diff == 0 && s1[i] != '\0' && s2[i] != '\0')
			i++;
		else
			return (diff);
	}
	return (0);
}
