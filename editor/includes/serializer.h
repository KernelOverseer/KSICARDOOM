#ifndef SERIALIZER_H
# define SERIALIZER_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "graphics_structs.h"
# include "libgl.h"
# define SERIALIZE_ERROR -1
# define ALLOCATION_ERROR -2

int	ft_serialize_data(int fd, void *data, size_t size);
int	ft_deserialize_data(int fd, void *buffer, size_t size);
int	ft_serialize_int(int fd, int object);
int	ft_deserialize_int(int fd, int *object);
int	ft_serialize_double(int fd, double object);
int	ft_deserialize_double(int fd, double *object);
int	ft_serialize_string(int fd, char *string, size_t max_size);
int	ft_serialize_with_padding(int fd, void *data, size_t size, size_t max_size);
int	ft_deserialize_string(int fd, char **string, size_t max_size);
int	ft_serialize_wall(int fd, t_wall *wall);
int	ft_deserialize_wall(int fd, t_wall *wall);
int	ft_serialize_portal(int fd, t_portal *portal);
int	ft_deserialize_portal(int fd, t_portal *portal);
int	ft_serialize_sector(int fd, t_sector *sector);
int	ft_serialize_camera(int fd, t_camera *camera);
int ft_deserialize_camera(int fd, t_camera *camera);
int ft_serialize_texture(int fd, t_sdl_image *texture);
int	ft_deserialize_texture(int fd, t_sdl_image *texture);
int ft_serialize_sector(int fd, t_sector *sector);
int ft_deserialize_sector(int fd, t_sector *sector);

#endif
