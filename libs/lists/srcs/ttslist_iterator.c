/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:00:49 by abiri             #+#    #+#             */
/*   Updated: 2019/12/19 03:13:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

void		*ttslist_iter_content(t_list_head	*head)
{
	static	t_list_node	*node;
	static	t_list_head	*lasthead;
	void				*result;

	if (!head)
	{
		lasthead = NULL;
		node = NULL;
		return (NULL);
	}
	if (head && head != lasthead && !node)
	{
		node = head->first;
		lasthead = head;
	}
	if (!node)
		return (NULL);
	result = node->content;
	node = node->next;
	return (result);
}

t_list_node	*ttslist_iter(t_list_head	*head)
{
	static	t_list_node	*node;
	static	t_list_head	*lasthead;
	t_list_node			*result;

	if (!head)
	{
		lasthead = NULL;
		node = NULL;
		return (NULL);
	}
	if (head && head != lasthead && !node)
	{
		node = head->first;
		lasthead = head;
	}
	if (!node)
		return (NULL);
	result = node;
	node = node->next;
	return (result);
}
