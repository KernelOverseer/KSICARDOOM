/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:38:54 by abiri             #+#    #+#             */
/*   Updated: 2019/12/19 02:58:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

t_list_node		*ttslist_new_node(void *content, size_t content_size)
{
	t_list_node	*new_node;

	if (!(new_node = tts_memalloc(sizeof(t_list_node))))
		return (NULL);
	new_node->content = content;
	new_node->content_size = content_size;
	return (new_node);
}

void			ttslist_init(t_list_head	*head)
{
	tts_bzero(head, sizeof(t_list_head));
	head->push = &ttslist_push_new;
	head->push_front = &ttslist_push_front_new;
	head->pop = &ttslist_pop_content;
	head->pop_front = &ttslist_pop_front_content;
}
