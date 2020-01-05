/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:42 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 17:20:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

void		*ttslist_splice(t_list_head *head, t_list_node *node)
{
	t_list_node *before;
	t_list_node *after;
	void		*result;

	if (!node || !head)
		return (NULL);
	before = node->prev;
	after = node->next;
	if (node != head->first)
		before->next = node->next;
	else
		head->first = node->next;
	if (node != head->last)
		after->prev = node->prev;
	else
		head->last = node->prev;
	result = node->content;
	free(node);
	head->size--;
	return (result);
}

t_list_node	*ttslist_pop(t_list_head *head)
{
	t_list_node *result;
	t_list_node *newlast;

	if (!head || !head->last)
		return (NULL);
	result = head->last;
	newlast = head->last->prev;
	if (newlast)
		newlast->next = NULL;
	else
		head->first = NULL;
	head->last = newlast;
	head->size--;
	return (result);
}

t_list_node	*ttslist_pop_front(t_list_head *head)
{
	t_list_node	*to_pop;

	if (!head || !head->first)
		return (NULL);
	to_pop = head->first;
	if (to_pop->next)
		to_pop->next->prev = NULL;
	head->first = to_pop->next;
	if (!head->first)
		head->last = NULL;
	head->size--;
	return (to_pop);
}

void		*ttslist_pop_front_content(t_list_head *head)
{
	t_list_node	*result_node;
	void		*result;

	if (!(result_node = ttslist_pop_front(head)))
		return (NULL);
	result = result_node->content;
	free(result_node);
	return (result);
}

void		*ttslist_pop_content(t_list_head *head)
{
	t_list_node	*result_node;
	void		*result;

	if (!(result_node = ttslist_pop(head)))
		return (NULL);
	result = result_node->content;
	free(result_node);
	return (result);
}
