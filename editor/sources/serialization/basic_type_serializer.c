/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_type_serializer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:12:13 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 18:24:29 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

int	ft_serialize_data(int fd, void *data, size_t size)
{
	int serialized_size;

	serialized_size = write(fd, data, size);
	return (serialized_size);
}

int	ft_serialize_with_padding(int fd, void *data, size_t size, size_t max_size)
{
	size_t	padding;
	size_t	iter;
	int 	serialized_size;

	if (size > max_size)
		size = max_size;
	padding = max_size - size;
	iter = 0;
	serialized_size = ft_serialize_data(fd, data, size);
	while (iter < padding)
	{
		write(fd, "\0", 1);
		iter++;
	}
	return ((serialized_size != size) ? serialized_size : max_size);
}

int	ft_deserialize_data(int fd, void *buffer, size_t size)
{
	int deserialized_size;

	deserialized_size = read(fd, buffer, size);
	return (deserialized_size);
}

int	ft_serialize_int(int fd, int object)
{
	return (ft_serialize_data(fd, &object, sizeof(int)));
}

int	ft_deserialize_int(int fd, int *object)
{
	return (ft_deserialize_data(fd, object, sizeof(int)));
}

int	ft_serialize_double(int fd, double object)
{
	return (ft_serialize_data(fd, &object, sizeof(double)));
}

int	ft_deserialize_double(int fd, double *object)
{
	return (ft_deserialize_data(fd, object, sizeof(double)));
}

int	ft_serialize_string(int fd, char *string, size_t max_size)
{
	// change this with ft_strlen libft function
	int result;
	size_t length;

	if (string == NULL)
		return (SERIALIZE_ERROR);
	length = strlen(string);
	if (length > max_size - 1)
		length = max_size - 1;
	result = ft_serialize_with_padding(fd, string, length, max_size);
	return (result);
}

int	ft_deserialize_string(int fd, char **string, size_t max_size)
{
	if (*string == NULL)
	{
		if (!(*string = malloc(max_size)))
			return (ALLOCATION_ERROR);
	}
	(*string)[max_size - 1] = '\0';
	return (ft_deserialize_data(fd, *string, max_size));
}
