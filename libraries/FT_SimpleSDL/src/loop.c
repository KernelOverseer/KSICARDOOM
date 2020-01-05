/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:38:50 by abiri             #+#    #+#             */
/*   Updated: 2019/12/27 16:04:05 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

/*
**	This function stores a static list of event handlers
**	- returns the head of the actual list
*/

t_linked_list_head	*ft_sdl_get_eventlist(void)
{
	static t_linked_list_head *head = NULL;

	if (!head)
		head = ft_simplesdl_memalloc(sizeof(t_linked_list_head));
	return (head);
}

/*
**	This function calls the handler for the specific event and gives it's
**		specific argument
*/

int					ft_sdl_apply_handler(t_sdl_event_handler *handler_info,
		SDL_Event e)
{
	if (handler_info->handler)
		return (handler_info->handler(handler_info->arg, e));
	ft_sdl_error("FT_SDL: Event handler function is null");
	return (1);
}

/*
**	This functions adds a new event handler, with it's argument and event type
*/

int					ft_sdl_hook(t_sdl_event_function *handler,
		void *arg, Uint32 event_type)
{
	t_sdl_event_handler *handler_info;
	t_linked_list_head	*head;

	head = ft_sdl_get_eventlist();
	if (!(handler_info = malloc(sizeof(t_sdl_event_handler))))
	{
		ft_sdl_error("FT_SDL: Cannot allocate enough memory for new event");
		return (0);
	}
	handler_info->handler = handler;
	handler_info->arg = arg;
	handler_info->event_type = event_type;
	ft_list_push(head, ft_list_newnode(handler_info));
	return (1);
}

/*
**	This function destroys Window and exits
*/

int					ft_sdl_quit(t_sdl_env *env)
{
	SDL_DestroyWindow(env->window);
	SDL_Quit();
	return (0);
}

/*
**	Main loop that is executed at each frame, and calls all events handlers
**		For each occuring event
*/

int					ft_sdl_loop(t_sdl_env *env)
{
	int			quit;
	SDL_Event	e;

	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (!ft_sdl_apply_event(e))
				quit = 1;
			if (e.type == SDL_QUIT)
				quit = 1;
		}
		ft_sdl_loop_hook(NULL, NULL);
	}
	ft_sdl_quit(env);
	return (0);
}
