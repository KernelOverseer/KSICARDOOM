/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:00:49 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 03:47:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

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

void		*ttslist_get_id_content(t_list_head *head, int id)
{
	void	*content;

	head->iterator = head->first;
	while ((content = ttslist_iter_content(head)))
	{
		if (!id)
			return (content);
		id--;
	}
	return (NULL);
}

int			ttslist_get_content_id(t_list_head *head, void *content)
{
	void	*element;
	int		id;

	id = 0;
	head->iterator = head->first;
	while ((element = ttslist_iter_content(head)))
	{
		if (content == element)
			return (id);
		id++;
	}
	return (-1);
}