/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:57:59 by abiri             #+#    #+#             */
/*   Updated: 2018/10/10 15:19:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*fnl;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i <= j)
			i++;
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > i)
			j--;
		fnl = malloc(j - i + 2);
		if (!fnl)
			return (NULL);
		ft_strncpy(fnl, &s[i], j - i + 1);
		fnl[j - i + 1] = '\0';
		return (fnl);
	}
	return (NULL);
}
