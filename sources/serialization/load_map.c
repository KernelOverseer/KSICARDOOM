/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:46:28 by abiri             #+#    #+#             */
/*   Updated: 2020/05/13 02:15:59 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_load_map(t_graphical_scene *scene, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	g_parsed_scene = scene;
	ft_load_camera(fd, scene);
	ft_load_textures(fd, scene);
	ft_load_sectors(fd, scene);
	ft_load_portals(fd, scene);
	if (scene->sectors.first)
		scene->current_sector = scene->sectors.first->content;
	close(fd);
	return(true);
}