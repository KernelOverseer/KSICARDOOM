/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_editor_serializer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 00:45:06 by abiri             #+#    #+#             */
/*   Updated: 2020/05/14 03:04:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "graphics_structs.h"

int	ft_serialize_vec2(int fd, t_vec2 object)
{
	return (ft_serialize_data(fd, &object, sizeof(t_vec2)));
}

int	ft_deserialize_vec2(int fd, t_vec2 *object)
{
	return (ft_deserialize_data(fd, object, sizeof(t_vec2)));
}

int	ft_get_array_index(void *array, void *entry, size_t size, size_t max_size)
{
	int				diff;
	int				dist;

	if (!entry)
		return (-1);
	dist = ((unsigned long)array - (unsigned long)entry);
	dist = (dist < 0) ? -dist : dist;
	diff = dist / size;
	if (diff >= max_size || diff < 0)
		return (-1);
	return (diff);
}

int	ft_get_texture_index(t_sdl_image *texture)
{
	if (!texture)
		return (-1);
	return (ft_get_array_index(g_parsed_scene->textures, texture,
		sizeof(t_sdl_image), g_parsed_scene->textures_count));
}

t_sdl_image	*ft_get_texture_from_index(int index)
{
	t_sdl_image	*result;

	if (index < 0 || index >= g_parsed_scene->textures_count)
		return (NULL);
	result = &(g_parsed_scene->textures[index]);
	return (result);
}

int	ft_serialize_wall(int fd, t_wall *wall)
{
	size_t	result;
	int		texture_index;

	if (!wall)
		return (SERIALIZE_ERROR);
	printf("Serializing wall\n");
	result = 0;
	result += ft_serialize_vec2(fd, wall->p1);
	result += ft_serialize_vec2(fd, wall->p2);
	texture_index = ft_get_texture_index(wall->texture);
	result += ft_serialize_int(fd, texture_index);
	result += ft_serialize_int(fd, wall->props);
	return (result);
}

int	ft_deserialize_wall(int fd, t_wall *wall)
{
	size_t		result;
	t_sdl_image	*texture;
	int			texture_index;

	if (!wall)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_vec2(fd, &(wall->p1));
	result += ft_deserialize_vec2(fd, &(wall->p2));
	result += ft_deserialize_int(fd, &texture_index);
	wall->texture = ft_get_texture_from_index(texture_index);
	result += ft_deserialize_int(fd, &(wall->props));
	return (result);
}

int	ft_serialize_portal(int fd, t_portal *portal)
{
	int	result;
	int	sector_id;

	if (!portal)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_wall(fd, &(portal->wall));
	sector_id = -1;
	if (portal->sector)
		sector_id = ttslist_get_content_id(&g_parsed_scene->sectors,
			portal->sector);
	result += ft_serialize_int(fd, sector_id);
	return (result);
}

int	ft_deserialize_portal(int fd, t_portal *portal)
{
	int	result;
	int	sector_id;
	
	if (!portal)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_wall(fd, &(portal->wall));
	result += ft_deserialize_int(fd, &sector_id);
	portal->sector = NULL;
	if (sector_id != -1)
		portal->sector = ttslist_get_id_content(&g_parsed_scene->sectors,
			sector_id);
	return (result);
}

int	ft_serialize_camera(int fd, t_camera *camera)
{
	int result;

	if (!camera)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_vec2(fd, camera->position);
	result += ft_serialize_double(fd, camera->angle);
	result += ft_serialize_int(fd, camera->height);
	result += ft_serialize_int(fd, camera->tilt);
	return (result);
}

int ft_deserialize_camera(int fd, t_camera *camera)
{
	int result;

	if (!camera)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_vec2(fd, &(camera->position));
	result += ft_deserialize_double(fd, &(camera->angle));
	result += ft_deserialize_int(fd, &(camera->height));
	result += ft_deserialize_int(fd, &(camera->tilt));
	return (result);
}

int ft_serialize_texture(int fd, t_sdl_image *texture)
{
	int result;
	
	if (!texture)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_int(fd, texture->width);
	result += ft_serialize_int(fd, texture->height);
	result += ft_serialize_data(fd, texture->pixels,
		texture->width * texture->height * sizeof(uint32_t));
	return (result);
}

int	ft_deserialize_texture(int fd, t_sdl_image *texture)
{
	int		result;
	int		texture_size;

	if (!texture)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_int(fd, &(texture->width));
	result += ft_deserialize_int(fd, &(texture->height));
	texture_size = texture->width * texture->height * sizeof(uint32_t);
	if (!(texture->pixels = malloc(texture_size)))
		return (ALLOCATION_ERROR);
	result += ft_deserialize_data(fd, texture->pixels, texture_size);
	return (result);
}

int	ft_serialize_sector_walls(int fd, t_sector *sector)
{
	int		result;
	t_wall	*wall;

	if (!sector)
		return (SERIALIZE_ERROR);
	result = ft_serialize_int(fd, (int)sector->walls.size);
	sector->walls.iterator = sector->walls.first;
	while ((wall = ttslist_iter_content(&(sector->walls))))
		result += ft_serialize_wall(fd, wall);
	return result;
}

int	ft_deserialize_sector_walls(int fd, t_sector *sector)
{
	int		result;
	int		iter;
	int 	wall_count;
	t_wall	*wall;

	if (!sector)
		return (SERIALIZE_ERROR);
	result = ft_deserialize_int(fd, &wall_count);
	iter = 0;
	while (iter < wall_count)
	{
		if (!(wall = ft_memalloc(sizeof(t_wall))))
			return (ALLOCATION_ERROR);
		result += ft_deserialize_wall(fd, wall);
		sector->walls.push(&(sector->walls), wall);
		iter++;
	}
	return result;
}

int	ft_serialize_sector_portals(int fd, t_sector *sector)
{
	int			result;
	t_portal	*portal;

	if (!sector)
		return (SERIALIZE_ERROR);
	result = ft_serialize_int(fd, (int)sector->portals.size);
	sector->portals.iterator = sector->portals.first;
	while ((portal = ttslist_iter_content(&(sector->portals))))
		result += ft_serialize_portal(fd, portal);
	return result;
}

int	ft_deserialize_sector_portals(int fd, t_sector *sector)
{
	int			result;
	int			iter;
	int 		portal_count;
	t_portal	*portal;

	if (!sector)
		return (SERIALIZE_ERROR);
	result = ft_deserialize_int(fd, &portal_count);
	iter = 0;
	while (iter < portal_count)
	{
		if (!(portal = ft_memalloc(sizeof(t_portal))))
			return (ALLOCATION_ERROR);
		result += ft_deserialize_portal(fd, portal);
		sector->portals.push(&(sector->portals), portal);
		iter++;
	}
	return result;
}

int ft_serialize_sector(int fd, t_sector *sector)
{
	int result;
	
	if (!sector)
		return (SERIALIZE_ERROR);
	result = 0;
	printf("serializing a sector %d %p:%d %p:%d \n", sector->id, sector->ceil_texture, ft_get_texture_index(sector->ceil_texture), sector->floor_texture, ft_get_texture_index(sector->floor_texture));
	result += ft_serialize_int(fd, sector->id);
	result += ft_serialize_double(fd, sector->brightness);
	result += ft_serialize_double(fd, sector->floor_height);
	result += ft_serialize_double(fd, sector->ceil_height);
	result += ft_serialize_int(fd, (int)sector->props);
	result += ft_serialize_int(fd, ft_get_texture_index(sector->floor_texture));
	result += ft_serialize_int(fd, ft_get_texture_index(sector->ceil_texture));
	result += ft_serialize_sector_walls(fd, sector);
	return (result);
}

int ft_deserialize_sector(int fd, t_sector *sector)
{
	int result;
	int	texture_index;
	
	texture_index = -1;
	if (!sector)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_int(fd, &(sector->id));
	printf("sector deserialization\n");
	printf("sector id : %f\n", sector->brightness);
	result += ft_deserialize_double(fd, &(sector->brightness));
	result += ft_deserialize_double(fd, &(sector->floor_height));
	result += ft_deserialize_double(fd, &(sector->ceil_height));
	result += ft_deserialize_int(fd, &(sector->props));
	result += ft_deserialize_int(fd, &texture_index);
	printf("texture_index : %d\n", texture_index);
	sector->floor_texture = ft_get_texture_from_index(texture_index);
	result += ft_deserialize_int(fd, &texture_index);
	sector->ceil_texture = ft_get_texture_from_index(texture_index);
	result += ft_deserialize_sector_walls(fd, sector);
	return (result);
}