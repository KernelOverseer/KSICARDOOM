/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:52:29 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 22:47:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cins(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static char	*parse1(char **str)
{
	int		i;
	char	*flag;

	i = 0;
	flag = ft_memalloc(5);
	if (!str || !(*str))
		return (0);
	while (cins("-0+# ", **str) && **str)
	{
		if (!cins(flag, **str))
			flag[i++] = **str;
		(*str)++;
	}
	return (flag);
}

static int	*parse2(char **str)
{
	char	*first;
	int		*minmax;

	minmax = (int*)malloc(sizeof(int) * 2);
	minmax[0] = (**str == '*') ? -5 : -1;
	minmax[1] = -1;
	first = *str;
	while (((**str <= '9' && **str >= '0') || **str == '*') && **str)
		(*str)++;
	if (first != *str && *first != '*')
		minmax[0] = ft_atoi(first);
	if (**str != '.')
		return (minmax);
	if (*(*str + 1) < '0' || *(*str + 1) > '9')
	{
		minmax[1] = 0;
		(*str)++;
	}
	else if (++(*str))
	{
		minmax[1] = ft_atoi((*str)++);
		while ((**str >= '0' && **str <= '9') && **str)
			(*str)++;
	}
	return (minmax);
}

static char	*parse3(char **str)
{
	if (**str)
	{
		if (cins("sSpdDioOuUxXcCb@", **str))
			return (ft_strsub((*str)++, 0, 1));
		if (cins("hl", **str))
		{
			if (**str == *(*str + 1))
			{
				if (ft_strchr("dDioOuUxXpcCsSb", *(*str + 2)) && ((*str += 3)))
					return (ft_strsub(*str - 3, 0, 3));
			}
			if (ft_strchr("dDioOuUxXpcCsSb", *(*str + 1)) && ((*str) += 2))
				return (ft_strsub(*str - 2, 0, 2));
		}
		if (cins("zj", **str))
		{
			if (cins("dDioOuUxXsScCb", *(*str + 1)) && ((*str) += 2))
				return (ft_strsub(*str - 2, 0, 2));
		}
	}
	while (cins("hljz", **str))
		(*str)++;
	return (ft_strdup(""));
}

t_print		*parse(char **str)
{
	int		*minmax;
	t_print	*result;

	if (!(**str))
		return (NULL);
	result = malloc(sizeof(t_print));
	result->flags = parse1(str);
	if (cins(result->flags, '-'))
		result->align = 1;
	else
		result->align = 0;
	minmax = parse2(str);
	result->fieldw = minmax[0];
	result->precis = minmax[1];
	result->arg = parse3(str);
	free(minmax);
	return (result);
}
