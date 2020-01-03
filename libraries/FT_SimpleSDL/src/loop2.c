/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:59:07 by azarzor           #+#    #+#             */
/*   Updated: 2019/12/27 16:05:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

/*
**	This function adds a unique handler that gets executed at every frame
*/

int		ft_sdl_loop_hook(t_sdl_loop_function *handler, void *arg)
{
	static	t_sdl_loop_function *stock = NULL;
	static	void				*data = NULL;

	if (handler)
	{
		stock = handler;
		data = arg;
	}
	else
	{
		if (stock)
			return (stock(data));
		else
			return (0);
	}
	return (1);
}

/*
**	This function given an event, looks for it's handler and applies it
*/

int		ft_sdl_apply_event(SDL_Event e)
{
	static	t_linked_list_head	*head = NULL;
	t_linked_list				*temp;
	t_sdl_event_handler			*handler;
	int							result;

	result = 1;
	if (!head)
		head = ft_sdl_get_eventlist();
	temp = head->first;
	while (temp)
	{
		handler = temp->content;
		if (handler->event_type == e.type)
			result &= ft_sdl_apply_handler(temp->content, e);
		temp = temp->next;
	}
	return (result);
}
