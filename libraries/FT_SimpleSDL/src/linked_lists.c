/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:23:23 by abiri             #+#    #+#             */
/*   Updated: 2019/07/29 12:00:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

t_linked_list	*ft_list_newnode(void *content)
{
	t_linked_list *result;

	result = malloc(sizeof(t_linked_list));
	if (!result)
	{
		ft_sdl_error("FT_SDL: Cannot allocate enough memory");
		return (NULL);
	}
	result->content = content;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

t_linked_list	*ft_list_push(t_linked_list_head *head, t_linked_list *newnode)
{
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!head->first)
		head->first = newnode;
	else
	{
		head->last->next = newnode;
		newnode->prev = head->last;
		newnode->next = NULL;
	}
	head->last = newnode;
	return (newnode);
}

void			*ft_list_queue_pop(t_linked_list_head *head)
{
	t_linked_list	*target;
	void			*content;

	target = head->first;
	if (!target)
		return (NULL);
	head->first = target->next;
	if (head->last == target)
		head->last = NULL;
	content = target->content;
	free(target);
	return (content);
}

void		ft_list_extract(t_linked_list_head *head, t_linked_list *element)
{
	if (head->first == element)
		head->first = element->next;
	if (head->last == element)
		head->last = element->prev;
	if (head->last != element && head->first != element)
	{
		if (element->prev)
			element->prev->next = element->next;
		if (element->next)
			element->next->prev = element->prev;
	}
}

void			ft_list_delete(t_linked_list_head *head, t_linked_list *element)
{
	ft_list_extract(head, element);
	free(element);
}
