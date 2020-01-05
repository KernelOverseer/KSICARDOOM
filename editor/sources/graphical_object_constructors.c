/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_object_constructors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 06:36:10 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 21:58:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sector	*ft_new_sector(void)
{
	t_sector	*result;
	static int	sector_id;

	if(!(result = ft_memalloc(sizeof(t_sector))))
		return (NULL);
	ttslist_init(&(result->walls));
	ttslist_init(&(result->portals));
	ttslist_init(&(result->sprites));
	result->brightness = 1;
	result->id = sector_id;
	sector_id++;
	return (result);
}

t_wall	*ft_new_wall(void)
{
	t_wall *result;

	if (!(result = ft_memalloc(sizeof(t_wall))))
		return (NULL);
	return (result);
}