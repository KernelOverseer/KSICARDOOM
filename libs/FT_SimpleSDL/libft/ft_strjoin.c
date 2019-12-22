/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:33:02 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 15:55:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoin(const char *s1, const char *s2)
{
	char			*result;
	unsigned	int	len;
	unsigned	int	i;
	unsigned	int	j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	if ((result = malloc(len + ft_strlen(s2) + 1)))
	{
		ft_strcpy(result, s1);
		ft_strcpy(result + len, s2);
	}
	return (result);
}
