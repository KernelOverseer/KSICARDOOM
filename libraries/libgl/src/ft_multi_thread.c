/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:06:15 by msidqi            #+#    #+#             */
/*   Updated: 2019/10/05 14:07:50 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

/*
** modular multithread functions
** ft_multi_thread parameters : struct with winwidth and range points to
** split image buffer.
** f function is the one handeling calculations.
*/

static void		ft_handle_threads(t_data *multi, int step, void *(*f)(void *))
{
	pthread_t	thread_ids[N_THREADS];
	int			i;

	i = -1;
	while (++i < N_THREADS)
	{
		multi[i].thread_range.start.x = 0;
		multi[i].thread_range.start.y = step * i;
		multi[i].thread_range.end.x = multi[i].winwidth;
		multi[i].thread_range.end.y = step * (i + 1);
	}
	i = -1;
	while (++i < N_THREADS)
		pthread_create(&thread_ids[i], NULL, f, (void *)&multi[i]);
	i = -1;
	while (++i < N_THREADS)
		pthread_join(thread_ids[i], NULL);
}

void			ft_multi_thread(t_data *data, void *(*f)(void *))
{
	t_data	*multi;
	int		i;
	int		step;

	multi = (t_data *)malloc(sizeof(t_data) * N_THREADS);
	step = data->winheight / N_THREADS;
	i = -1;
	while (++i < N_THREADS)
		multi[i] = *data;
	ft_handle_threads(multi, step, f);
	free(multi);
}
