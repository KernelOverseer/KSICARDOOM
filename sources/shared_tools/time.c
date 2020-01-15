/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:40:25 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/07 15:40:26 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "doom_nukem.h"

void	ft_update_time(t_timer *timer)
{
	timer->current_time = SDL_GetPerformanceCounter();
	timer->delta_time = (double)(timer->current_time - timer->previous_tick) / SECOND;
}

void	ft_init_timer(t_timer *timer)
{
	timer->previous_tick = SDL_GetPerformanceCounter();
	timer->update_time = &ft_update_time;
}
