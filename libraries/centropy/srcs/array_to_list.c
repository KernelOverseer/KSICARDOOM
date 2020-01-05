/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:58:42 by merras            #+#    #+#             */
/*   Updated: 2019/08/03 18:03:13 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

t_string	*array_to_t_string(char **array)
{
	t_string *head;

	while (*array)
	{
		t_string_push(&head, ft_strdup(*array));
		array++;
	}
	return (head);
}

t_string	*t_string_copy(t_string *list)
{
	t_string *copy;

	copy = NULL;
	while (list)
	{
		t_string_push(&copy, ft_strdup(list->string));
		list = list->next;
	}
	return (copy);
}
