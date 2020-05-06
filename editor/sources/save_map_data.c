/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:12:13 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 18:24:29 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    ft_save_map_data(void *arg, t_gui_component *button)
{
	t_doom_editor *env;
	t_sector	*first_sector;
	t_list_head	*wall_list;
	t_wall		*wall;
	int fd;

	fd = open("save_test_doom_map.map", O_WRONLY | O_TRUNC | O_CREAT, 0644);

	(void)button;
	env = arg;

	first_sector = env->data.sectors.first->content;
	wall_list = &(first_sector->walls);
	wall_list->iterator = wall_list->first;
	while ((wall = ttslist_iter_content(wall_list)))
	{
		ft_serialize_wall(fd, wall);
	}
}

void	ft_load_map_data(void *arg, t_gui_component *button)
{
	t_doom_editor *env;
	t_sector	*first_sector;
	t_list_head	*wall_list;
	t_wall		wall;
	t_wall		*new_wall;
	int fd;

	fd = open("save_test_doom_map.map", O_RDONLY);
	(void)button;
	env = arg;
	first_sector = env->data.sectors.first->content;
	wall_list = &(first_sector->walls);
	while (ft_deserialize_wall(fd, &wall))
	{
		new_wall = ft_memalloc(sizeof(t_wall));
		*new_wall = wall;
		wall_list->push(wall_list, new_wall);
	}
}
