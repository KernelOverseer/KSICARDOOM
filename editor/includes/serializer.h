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

#endif
