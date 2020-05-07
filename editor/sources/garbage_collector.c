/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:43:01 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 18:40:37 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	ft_purge_textures(int texture_count, t_sdl_image ***texture_pointer)
{
	t_sdl_image **texture_list;
	int			index;

	index = 0;
	if (!texture_pointer || !(*texture_pointer))
		return ;
	texture_list = *texture_pointer;
	while (index < texture_count)
	{
		free(texture_list[index]->pixels);
		free(texture_list[index]);
		index++;
	}
	free(texture_list);
	*texture_pointer = NULL;
}

void	ft_purge_wall(void *wall)
{
	free(wall);
}

void	ft_purge_sprite(void *sprite)
{
	free(sprite);
}

void	ft_purge_portal(void *portal)
{
	free(portal);
}

void	ft_purge_sector(void *data)
{
	t_sector	*sector;

	sector = data;
	ttslist_purge(&(sector->walls), &ft_purge_wall);
	ttslist_purge(&(sector->sprites), &ft_purge_sprite);
	ttslist_purge(&(sector->portals), &ft_purge_portal);
	free(sector);
}