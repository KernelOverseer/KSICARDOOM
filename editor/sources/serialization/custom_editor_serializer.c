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
	return (result);
}
