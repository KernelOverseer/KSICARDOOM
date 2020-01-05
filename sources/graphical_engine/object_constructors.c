/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:11:33 by abiri             #+#    #+#             */
/*   Updated: 2020/01/05 21:23:11 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_wall		*ft_new_wall(t_point p1, t_point p2)
{
	t_wall	*result;

	if (!(result = ft_memalloc(sizeof(t_wall))))
		return (NULL + ft_raise_exception(ERROR_allocation_problem, NULL));
	result->p1 =  (t_vector){p1.x, p1.y};
	result->p2 =  (t_vector){p2.x, p2.y};
	return (result);
}

t_sector	*ft_new_sector(void)
{
	t_sector	*result;

	if (!(result = ft_memalloc(sizeof(t_sector))))
		return (NULL + ft_raise_exception(ERROR_allocation_problem, NULL));
	ttslist_init(&(result->walls));
	ttslist_init(&(result->portals));
	ttslist_init(&(result->sprites));
	result->brightness = 1;
	return (result);
}
