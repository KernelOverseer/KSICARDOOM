/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchreplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:09:31 by abiri             #+#    #+#             */
/*   Updated: 2019/03/25 20:56:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_occurences(char *str, char *old)
{
	int counter;
	int oldlen;

	counter = 0;
	oldlen = ft_strlen(old);
	while ((str = ft_strstr(str, old)))
	{
		str += oldlen;
		counter++;
	}
	return (counter);
}

static	char	*ft_allocsize(char *str, char *old, char *new)
{
	int len;
	int num;

	len = ft_strlen(str);
	num = ft_occurences(str, old);
	return (malloc(len - num * ft_strlen(old) + num * ft_strlen(new) + 1));
}

char			*ft_searchreplace(char *str, char *old, char *new)
{
	char	*result;
	char	*temp;
	int		index;
	int		goal;
	int		len;

	index = 0;
	temp = str;
	len = ft_strlen(old);
	result = ft_allocsize(str, old, new);
	while ((temp = ft_strstr(temp, old)))
	{
		goal = temp - str;
		ft_strncpy(result + index, temp - goal, goal);
		index += goal;
		ft_strcpy(result + index, new);
		index += ft_strlen(new);
		temp += len;
		str = temp;
	}
	ft_strcpy(result + index, str);
	return (result);
}
