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