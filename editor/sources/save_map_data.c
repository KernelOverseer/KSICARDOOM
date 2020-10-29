/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 21:26:50 by abiri             #+#    #+#             */
/*   Updated: 2020/10/22 10:08:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_graphical_scene	*g_parsed_scene;

void 	ft_save_camera(int fd, t_graphical_scene *env)
{
	ft_serialize_camera(fd, &(env->camera));
}

void	ft_save_textures(int fd, t_graphical_scene *env)
{
	size_t	index;

	index = 0;
	ft_serialize_int(fd, env->textures_count);
	while (index < env->textures_count)
	{
		ft_serialize_texture(fd, &(env->textures[index]));
		index++;
	}
}

void	ft_save_sectors(int fd, t_graphical_scene *env)
{
	t_sector	*sector;

	ft_serialize_int(fd, env->sectors.size);
	env->sectors.iterator = env->sectors.first;
	while ((sector = ttslist_iter_content(&(env->sectors))))
		ft_serialize_sector(fd, sector);
}

void	ft_load_portal_list_dots(t_doom_editor *env, t_list_head *portals)
{
	t_portal	*portal;
	t_point 	*new_p1;
	t_point		*new_p2;

	portals->iterator = portals->first;
	while ((portal = ttslist_iter_content(portals)))
	{
		if (!(new_p1 = malloc(sizeof(t_point))) ||
			!(new_p2 = malloc(sizeof(t_point))))
			continue ;
		*new_p1 = (t_point){portal->wall.p1.x, portal->wall.p1.y};
		*new_p2 = (t_point){portal->wall.p2.x, portal->wall.p2.y};
		env->event.points.push(&(env->event.points), new_p1);
		env->event.points.push(&(env->event.points), new_p2);
	}
}

void	ft_load_wall_list_dots(t_doom_editor *env, t_list_head *walls)
{
	t_wall	*wall;
	t_point *new_p1;
	t_point *new_p2;

	walls->iterator = walls->first;
	while ((wall = ttslist_iter_content(walls)))
	{
		if (!(new_p1 = malloc(sizeof(t_point))) ||
			!(new_p2 = malloc(sizeof(t_point))))
			continue ;
		*new_p1 = (t_point){wall->p1.x, wall->p1.y};
		*new_p2 = (t_point){wall->p2.x, wall->p2.y};
		env->event.points.push(&(env->event.points), new_p1);
		env->event.points.push(&(env->event.points), new_p2);
	}
}

void	ft_load_list_dots(t_doom_editor *env)
{
	t_sector	*sector;

	env->data.sectors.iterator = env->data.sectors.first;
	while ((sector = ttslist_iter_content(&(env->data.sectors))))
	{
		ft_load_portal_list_dots(env, &sector->walls);
		ft_load_wall_list_dots(env, &sector->portals);
	}
}

void	ft_save_portals(int fd, t_graphical_scene *env)
{
	t_sector	*sector;
	t_list_node *node;
	
	env->sectors.iterator = env->sectors.first;
	while ((sector = ttslist_iter_content(&(env->sectors))))
		ft_serialize_sector_portals(fd, sector);
}

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
	g_parsed_scene = &(env->data);
	ft_save_camera(fd, &env->data);
	ft_save_textures(fd, &env->data);
	ft_save_sectors(fd, &env->data);
	ft_save_portals(fd, &env->data);
	close(fd);
}

void	ft_load_map_data(void *arg, t_gui_component *button)
{
	t_doom_editor	*env;
	t_sector		*first_sector;
	t_list_head		*wall_list;
	t_wall			*new_wall;
	t_wall			wall;
	int fd;

	fd = open("save_test_doom_map.map", O_RDONLY);
	(void)button;
	env = arg;
	g_parsed_scene = &(env->data);
	ttslist_purge(&(env->event.points), &free);
	ft_load_camera(fd, &env->data);
	ft_load_textures(fd, &env->data);
	ft_load_sectors(fd, &env->data);
	ft_load_portals(fd, &env->data);
	ft_load_list_dots(env);
	env->data.current_sector = NULL;
	env->event.selected = NULL;
	if (env->data.sectors.first)
		env->data.current_sector = env->data.sectors.first->content;
	// relisting the sectors into the sector list field
	ft_list_sectors(env, &(env->data.sectors));
	// reload the sector settings menu
	ft_reload_sprite_settings(env);
	ft_reload_wall_settings(env);
	ft_reload_portal_settings(env);
	ft_reload_sector_settings(env);
	close(fd);
}
