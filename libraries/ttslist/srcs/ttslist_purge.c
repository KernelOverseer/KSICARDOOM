/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_purge.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:43:01 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 18:40:37 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

void	ttslist_purge(t_list_head *list, void (*purge)(void *))
{
	void	*content;

	while (list->first && (content = ttslist_splice(list, list->first)))
		purge(content);
}

int		ttslist_remove_node_with_content(t_list_head *list, void *content)
{
	t_list_node	*node;

	if (!list)
		return (0);
	node = list->first;
	while (node)
	{
		if (node->content == content)
		{
			ttslist_splice(list, node);
			return (1);
		}
		node = node->next;
	}
	return (0);
}