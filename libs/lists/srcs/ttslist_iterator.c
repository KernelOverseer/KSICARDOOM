/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:00:49 by abiri             #+#    #+#             */
/*   Updated: 2019/12/20 12:14:14 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"
#include <stdio.h>

void		*ttslist_iter_content(t_list_head	*head)
{
	void				*result;

	if (!head->iterator)
		return (NULL);
	result = head->iterator->content;
	head->iterator = head->iterator->next;
	return (result);
}

t_list_node	*ttslist_iter(t_list_head	*head)
{
	t_list_node			*result;

	if (!head->iterator)
		return (NULL);
	result = head->iterator;
	head->iterator = head->iterator->next;
	return (result);
}
