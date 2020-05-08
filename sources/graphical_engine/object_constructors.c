/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:11:33 by abiri             #+#    #+#             */
/*   Updated: 2020/05/07 21:29:33 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_portal	*ft_new_portal(t_point p1, t_point p2, t_sector *sector)
{
	t_portal	*result;

	if (!(result = ft_memalloc(sizeof(t_portal))))
		return (result);
	result->wall.p1 = (t_vec2){p1.x, p1.y};
	result->wall.p2 = (t_vec2){p2.x, p2.y};
	result->sector = sector;
	return (result);
}

t_wall		*ft_new_wall(t_point p1, t_point p2)
{
	t_wall	*result;

	if (!(result = ft_memalloc(sizeof(t_wall))))
		return (NULL + ft_raise_exception(ERROR_allocation_problem, NULL));
	result->p1 =  (t_vec2){p1.x, p1.y};
	result->p2 =  (t_vec2){p2.x, p2.y};
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
