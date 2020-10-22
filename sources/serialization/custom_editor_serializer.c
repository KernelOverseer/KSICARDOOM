/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_editor_serializer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 00:45:06 by abiri             #+#    #+#             */
/*   Updated: 2020/10/22 09:58:25 by abiri            ###   ########.fr       */
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
	printf("deserializing a portal with sector id : %d\n", sector_id);
	if (sector_id != -1)
		portal->sector = ttslist_get_id_content(&g_parsed_scene->sectors,
			sector_id);
	return (result);
}

int	ft_serialize_texture_reference_array(int fd,
	t_sdl_image **texture_list, int size)
{
	int	result;
	int	index;
	int	texture_index;

	if (!texture_list)
		return (SERIALIZE_ERROR);
	index = 0;
	result = 0;
	result += ft_serialize_int(fd, size);
	while (index < size)
	{
		texture_index = ft_get_texture_index(texture_list[index]);
		result += ft_serialize_int(fd, texture_index);
		index++;
	}
	return (result);
}

int	ft_deserialize_texture_reference_index(int fd,
	t_sdl_image ***texture_list_pointer, int *texture_count)
{
	int	result;
	int	size;
	int	texture_index;
	int	index;

	index = 0;
	result = 0;
	result += ft_deserialize_int(fd, &size);
	if (size < 0)
		return (SERIALIZE_ERROR);
	*texture_count = size;
	if (!(*texture_list_pointer =
		ft_memalloc(sizeof(t_sdl_image *) * size)))
		return (SERIALIZE_ERROR);
	while (index < size)
	{
		result += ft_deserialize_int(fd, &texture_index);
		(*texture_list_pointer)[index] =
			ft_get_texture_from_index(texture_index);
		index++;
	}
	return (result);
}


int	ft_serialize_animation(int fd, t_animation *animation)
{
	int	result;

	if (!animation)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_texture_reference_array(fd,
		animation->textures, animation->frame_count);
	result += ft_serialize_double(fd, animation->speed);
	result += ft_serialize_int(fd, (int)animation->type);
	result += ft_serialize_int(fd, (int)animation->props);
	return (result);
}

int	ft_deserialize_animation(int fd, t_animation *animation)
{
	int result;

	if (!animation)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_texture_reference_index(fd,
		&animation->textures, &animation->frame_count);
	result += ft_deserialize_double(fd, &animation->speed);
	result += ft_deserialize_int(fd, (int *)(&animation->type));
	result += ft_deserialize_int(fd, (int *)(&animation->props));
	return (result);
}

int	ft_serialize_sprite(int fd, t_sprite *sprite)
{
	int	result;

	if (!sprite)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_vec2(fd, sprite->position);
	result += ft_serialize_double(fd, sprite->radius);
	result += ft_serialize_double(fd, sprite->height);
	result += ft_serialize_double(fd, sprite->altitude);
	result += ft_serialize_double(fd, sprite->angle);
	result += ft_serialize_int(fd, (int)(sprite->props));
	result += ft_serialize_animation(fd, &sprite->animation);
	return (result);
}

int	ft_deserialize_sprite(int fd, t_sprite *sprite)
{
	int	result;
	
	if (!sprite)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_vec2(fd, &sprite->position);
	result += ft_deserialize_double(fd, &sprite->radius);
	result += ft_deserialize_double(fd, &sprite->height);
	result += ft_deserialize_double(fd, &sprite->altitude);
	result += ft_deserialize_double(fd, &sprite->angle);
	result += ft_deserialize_int(fd, (int *)(&sprite->props));
	result += ft_deserialize_animation(fd, &sprite->animation);
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
	{
		printf("\t PORTAL FOR SECTOR %d\n", sector->id);
		result += ft_serialize_portal(fd, portal);
	}
	return (result);
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
	return (result);
}

int	ft_serialize_sector_sprites(int fd, t_sector *sector)
{
	int		result;
	t_sprite	*sprite;

	result = 0;
	if (!sector)
		return (SERIALIZE_ERROR);
	result = ft_serialize_int(fd, (int)sector->sprites.size);
	sector->sprites.iterator = sector->sprites.first;
	while ((sprite = ttslist_iter_content(&sector->sprites)))
		result += ft_serialize_sprite(fd, sprite);
	return (result);
}

int	ft_deserialize_sector_sprites(int fd, t_sector *sector)
{
	int		result;
	int		index;
	int		sprite_count;
	t_sprite	*sprite;

	if (!sector)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_int(fd, &sprite_count);
	index = 0;
	while (index < sprite_count)
	{
		if (!(sprite = ft_memalloc(sizeof(t_sprite))))
			return (SERIALIZE_ERROR);
		result += ft_deserialize_sprite(fd, sprite);
		sector->sprites.push(&(sector->sprites), sprite);
		index++;
	}
	return (result);
}

int ft_serialize_sector(int fd, t_sector *sector)
{
	int result;
	
	if (!sector)
		return (SERIALIZE_ERROR);
	result = 0;
	printf("serializing a sector %d\n", sector->id);
	result += ft_serialize_int(fd, sector->id);
	result += ft_serialize_double(fd, sector->brightness);
	result += ft_serialize_double(fd, sector->floor_height);
	result += ft_serialize_double(fd, sector->ceil_height);
	result += ft_serialize_int(fd, (int)sector->props);
	result += ft_serialize_int(fd, ft_get_texture_index(sector->floor_texture));
	result += ft_serialize_int(fd, ft_get_texture_index(sector->ceil_texture));
	result += ft_serialize_sector_walls(fd, sector);
	// result += ft_serialize_sector_portals(fd, sector);
	result += ft_serialize_sector_sprites(fd, sector);
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
	// result += ft_deserialize_sector_portals(fd, sector);
	result += ft_deserialize_sector_sprites(fd, sector);
	return (result);
}
