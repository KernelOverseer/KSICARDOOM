/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:58:51 by abiri             #+#    #+#             */
/*   Updated: 2020/05/13 02:04:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void	ft_load_camera(int fd, t_graphical_scene *env)
{
	ft_deserialize_camera(fd, &(env->camera));
}

void	ft_load_textures(int fd, t_graphical_scene *env)
{
	size_t		index;
	int			texture_count;
	t_sdl_image	texture;

	
	ft_deserialize_int(fd, &texture_count);
	ft_purge_textures(env->textures_count, &(env->textures));
	env->textures = NULL;
	if (texture_count == 0)
		return ;
	env->textures = malloc(sizeof(t_sdl_image) * texture_count);
	if (!env->textures)
		return ;
	env->textures_count = texture_count;
	index = 0;
	while (index < texture_count)
	{
		ft_deserialize_texture(fd, &texture);
		env->textures[index] = texture;
		index++;
	}
}

void	ft_load_portals(int fd, t_graphical_scene *env)
{
	t_sector	*sector;
	
	env->sectors.iterator = env->sectors.first;
	while ((sector = ttslist_iter_content(&env->sectors)))
		ft_deserialize_sector_portals(fd, sector);
}

t_sector	*ft_create_sector(void)
{
	t_sector	*result;

	if (!(result = ft_memalloc(sizeof(t_sector))))
		return (NULL);
	ttslist_init(&(result->walls));
	ttslist_init(&(result->portals));
	ttslist_init(&(result->sprites));
	result->brightness = 1;
	return (result);
}


void	ft_load_sectors(int fd, t_graphical_scene *env)
{
	t_sector	*sector;
	int			sector_count;
	int			index;
	t_sector	*new_sector;

	ft_deserialize_int(fd, &sector_count);
	ttslist_purge(&(env->sectors), &ft_purge_sector);
	index = 0;
	while (index < sector_count)
	{
		new_sector = ft_create_sector();
		ft_deserialize_sector(fd, new_sector);
		env->sectors.push(&(env->sectors), new_sector);
		index++;
	}
}