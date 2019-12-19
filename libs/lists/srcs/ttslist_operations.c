/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:48:36 by abiri             #+#    #+#             */
/*   Updated: 2019/12/19 01:40:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

t_list_node	*ttslist_push(t_list_head *head, t_list_node *newnode)
{
	t_list_node	*last;

	if (!newnode || !head)
		return (NULL);
	last = head->last;
	head->last = newnode;
	if (last)
	{
		last->next = newnode;
		newnode->prev = last;
	}
	if (!head->first)
		head->first = newnode;
	head->size++;
	return (newnode);
}

t_list_node	*ttslist_push_front(t_list_head *head, t_list_node *newnode)
{
	t_list_node *first;

	if (!newnode || !head)
		return (NULL);
	first = head->first;
	head->first = newnode;
	if (first)
	{
		head->first->next = first;
		first->prev = newnode;
	}
	if (!head->last)
		head->last = newnode;
	head->size++;
	return (newnode);
}

t_list_node *ttslist_push_front_new(t_list_head *head, void *content)
{
	return (ttslist_push_front(head, ttslist_new_node(content, 0)));
}

t_list_node	*ttslist_push_new(t_list_head *head, void *content)
{
	return (ttslist_push(head, ttslist_new_node(content, 0)));
}
