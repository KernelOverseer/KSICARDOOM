/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:41:25 by merras            #+#    #+#             */
/*   Updated: 2019/08/03 16:19:07 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

char	**t_string_to_array(t_string *list)
{
	int			i;
	char		**array;
	t_string	*head;

	i = 0;
	head = list;
	while (list)
	{
		list = list->next;
		i++;
	}
	array = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (head)
	{
		array[i] = ft_strdup(head->string);
		head = head->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
