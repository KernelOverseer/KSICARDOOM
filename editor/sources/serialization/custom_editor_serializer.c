#include "serializer.h"
#include "graphics_structs.h"

int	ft_serialize_vec2(int fd, t_vec2 object)
{
	write(1, "saved vec2\n", 12);
	return (ft_serialize_data(fd, &object, sizeof(t_vec2)));
}

int	ft_deserialize_vec2(int fd, t_vec2 *object)
{
	write(1, "Parsed vec2\n", 13);
	return (ft_deserialize_data(fd, object, sizeof(t_vec2)));
}

int	ft_serialize_wall(int fd, t_wall *wall)
{
	size_t	result;

	if (!wall)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_vec2(fd, wall->p1);
	result += ft_serialize_vec2(fd, wall->p2);
	result += ft_serialize_int(fd, 0);
	result += ft_serialize_int(fd, 0);
	result += ft_serialize_int(fd, wall->props);
	write(1, "saved wall\n", 12);
	return (result);
}

int	ft_deserialize_wall(int fd, t_wall *wall)
{
	size_t	result;
	int	temp;

	if (!wall)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_vec2(fd, &(wall->p1));
	result += ft_deserialize_vec2(fd, &(wall->p2));
	result += ft_deserialize_int(fd, &temp);
	result += ft_deserialize_int(fd, &temp);
	wall->texture = NULL;
	result += ft_deserialize_int(fd, &(wall->props));
	write(1, "Parsed wall\n", 13);
	return (result);
}

int	ft_serialize_portal(int fd, t_portal *portal)
{
	int	result;
	long	temp;

	if (!portal)
		return (SERIALIZE_ERROR);
	result = 0;
	temp = 0;
	result += ft_serialize_wall(fd, &(portal->wall));
	result += ft_serialize_data(fd, &temp, sizeof(temp));
	write(1, "saved portal\n", 14);
	return (result);
}

int	ft_deserialize_portal(int fd, t_portal *portal)
{
	int	result;
	
	if (!portal)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_wall(fd, &(portal->wall));
	result += ft_deserialize_data(fd, &(portal->sector), sizeof(portal->sector));
	write(1, "Parsed portal\n", 15);
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
	write(1, "saved camera\n", 14);
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
	write(1, "Parsed camera\n", 15);
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
	write(1, "saved texture\n", 15);
	return (result);
}

int	ft_deserialize_texture(int fd, t_sdl_image *texture)
{
	int		result;
	size_t	texture_size;

	write(1, "started parsing texture\n", 16);
	if (!texture)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_int(fd, &(texture->width));
	result += ft_deserialize_int(fd, &(texture->height));
	texture_size = texture->width * texture->height * sizeof(uint32_t);
	if (!(texture->pixels = malloc(texture_size)))
		return (ALLOCATION_ERROR);
	result += ft_deserialize_data(fd, &(texture->pixels), texture_size);
	write(1, "Parsed texture\n", 16);
	return (result);
}

int ft_serialize_sector(int fd, t_sector *sector)
{
	int result;
	
	if (!sector)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_serialize_int(fd, sector->id);
	result += ft_serialize_int(fd, (int)sector->walls.size);
	result += ft_serialize_int(fd, (int)sector->portals.size);
	result += ft_serialize_int(fd, (int)sector->sprites.size);
	result += ft_serialize_double(fd, sector->brightness);
	result += ft_serialize_double(fd, sector->floor_height);
	result += ft_serialize_double(fd, sector->ceil_height);
	result += ft_serialize_int(fd, (int)sector->props);
	write(1, "saved sector\n", 14);
	return (result);
}

int ft_deserialize_sector(int fd, t_sector *sector)
{
	int result;
	int temp;
	
	if (!sector)
		return (SERIALIZE_ERROR);
	result = 0;
	result += ft_deserialize_int(fd, &(sector->id));
	result += ft_deserialize_int(fd, &temp);
	result += ft_deserialize_int(fd, &temp);
	result += ft_deserialize_int(fd, &temp);
	result += ft_deserialize_double(fd, &(sector->brightness));
	result += ft_deserialize_double(fd, &(sector->floor_height));
	result += ft_deserialize_double(fd, &(sector->ceil_height));
	result += ft_deserialize_int(fd, &(sector->props));
	write(1, "Parsed sector\n", 15);
	return (result);
}