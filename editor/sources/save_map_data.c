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

void 	ft_save_camera(int fd, t_doom_editor *env)
{
	ft_serialize_camera(fd, &(env->data.camera));
}

void	ft_load_camera(int fd, t_doom_editor *env)
{
	ft_deserialize_camera(fd, &(env->data.camera));
}

void	ft_save_textures(int fd, t_doom_editor *env)
{
	size_t	index;

	index = 0;
	ft_serialize_int(fd, env->data.textures_count);
	while (index < env->data.textures_count)
	{
		ft_serialize_texture(fd, env->data.textures[index]);
		index++;
	}
}

void	ft_load_textures(int fd, t_doom_editor *env)
{
	size_t		index;
	int			texture_count;
	t_sdl_image	texture;

	index = 0;
	ft_deserialize_int(fd, &texture_count);
	if (texture_count == 0)
		return ;
	ft_purge_textures(env->data.textures_count, &(env->data.textures));
	if (!(env->data.textures = ft_memalloc(sizeof(t_sdl_image *) * texture_count)))
		return ;
	while (index < texture_count)
	{
		ft_deserialize_texture(fd, &texture);
		if ((env->data.textures[index] = malloc(sizeof(t_sdl_image))))
			(*env->data.textures[index]) = texture;
		index++;
	}
}

void	ft_save_sectors(int fd, t_doom_editor *env)
{
	t_sector	*sector;

	ft_serialize_int(fd, env->data.sectors.size);
	env->data.sectors.iterator = env->data.sectors.first;
	while (sector = ttslist_iter_content(&(env->data.sectors)))
		ft_serialize_sector(fd, sector);
}

void	ft_load_sectors(int fd, t_doom_editor *env)
{
	t_sector	*sector;
	int			sector_count;
	int			index;
	t_sector	*new_sector;

	ft_deserialize_int(fd, &sector_count);
	ttslist_purge(&(env->data.sectors), &ft_purge_sector);
	index = 0;
	while (index < sector_count)
	{
		new_sector = ft_new_sector();
		ft_deserialize_sector(fd, new_sector);
		env->data.sectors.push(&(env->data.sectors), new_sector);
		index++;
	}
}

void    ft_save_map_data(void *arg, t_gui_component *button)
{
	t_doom_editor *env;
	t_sector	*first_sector;
	t_list_head	*wall_list;
	t_wall		*wall;
	int fd;

	fd = open("save_test_doom_map.map", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	env = arg;
	(void)button;
	ft_save_camera(fd, env);
	ft_save_textures(fd, env);
	ft_save_sectors(fd, env);
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
	ft_load_camera(fd, env);
	ft_load_textures(fd, env);
	ft_load_sectors(fd, env);
	if (env->data.sectors.first)
		env->data.current_sector = env->data.sectors.first->content;
}
