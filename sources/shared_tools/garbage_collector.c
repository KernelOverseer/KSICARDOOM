/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:43:01 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 01:31:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	ft_purge_textures(int texture_count, t_sdl_image **texture_pointer)
{
	t_sdl_image *texture_list;
	int			index;

	index = 0;
	if (!texture_pointer || !(*texture_pointer))
		return ;
	texture_list = *texture_pointer;
	while (index < texture_count)
	{
		free(texture_list[index].pixels);
		index++;
	}
	free(texture_list);
	*texture_pointer = NULL;
}

void	ft_purge_sector(void *data)
{
	t_sector	*sector;

	sector = data;
	ttslist_purge(&(sector->walls), &free);
	ttslist_purge(&(sector->sprites), &free);
	ttslist_purge(&(sector->portals), &free);
	free(sector);
}