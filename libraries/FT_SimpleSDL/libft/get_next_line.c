/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:50:29 by abiri             #+#    #+#             */
/*   Updated: 2019/05/03 19:20:05 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*newfile(int fd)
{
	t_list *result;

	if (!(result = malloc(sizeof(t_list))))
		return (NULL);
	result->content = NULL;
	result->content_size = fd;
	result->next = NULL;
	return (result);
}

static t_list	*getfile(t_list **filelist, int fd)
{
	t_list *cursor;

	if (fd < 0)
		return (NULL);
	if (!(*filelist))
		*filelist = newfile(fd);
	cursor = *filelist;
	while (cursor)
	{
		if (cursor->content_size == (size_t)fd)
			return (cursor);
		cursor = cursor->next;
	}
	return (ft_lstpush(*filelist, newfile(fd)));
}

static void		cleanfile(t_list **filelist, int fd)
{
	t_list *iter;
	t_list *temp;

	iter = *filelist;
	if (iter->content_size == (size_t)fd)
	{
		*filelist = iter->next;
		free(iter->content);
		free(iter);
	}
	else
	{
		while (iter->next)
		{
			if (iter->next->content_size == (size_t)fd)
			{
				temp = iter->next->next;
				free(iter->next->content);
				free(iter->next);
				iter->next = temp;
			}
			iter = iter->next;
		}
	}
}

static int		getline(t_list *stock, char **line, int *r)
{
	char	*temp;
	size_t	c;
	int		flag;

	c = 0;
	temp = stock->content;
	if (!temp)
	{
		*line = NULL;
		return (0);
	}
	while (temp[c] && temp[c] != '\n')
		c++;
	flag = (temp[c] == '\n');
	*line = ft_strsub(temp, 0, c);
	if (flag)
		stock->content = ft_strsub(temp, c + flag, ft_strlen(temp) - flag);
	else
		stock->content = NULL;
	free(temp);
	*r = (c != 0);
	return (flag);
}

int				get_next_line(int fd, char **line)
{
	static	t_list	*stock = NULL;
	t_list			*node;
	char			buffer[BUFF_SIZE + 1];
	char			*copy;
	int				r;

	node = getfile(&stock, fd);
	while ((r = read(fd, buffer, BUFF_SIZE)))
	{
		if (r < 0 || fd < 0 || line == NULL)
			return (-1);
		buffer[r] = '\0';
		copy = node->content;
		node->content = ft_strjoin(copy, buffer);
		free(copy);
		if (ft_ischarin(buffer, '\n'))
			break ;
	}
	if (!getline(node, line, &r) && fd != 0)
		cleanfile(&stock, fd);
	return (r);
}
