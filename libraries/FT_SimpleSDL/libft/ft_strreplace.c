/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:26:37 by abiri             #+#    #+#             */
/*   Updated: 2019/03/25 20:56:39 by abiri            ###   ########.fr       */
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

char			*ft_strreplace(char *str, char *old, char *new, int start)
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
	temp = ft_strstr(temp + start, old);
	goal = temp - str;
	ft_strncpy(result + index, temp - goal, goal);
	index += goal;
	ft_strcpy(result + index, new);
	index += ft_strlen(new);
	temp += len;
	str = temp;
	ft_strcpy(result + index, str);
	return (result);
}
