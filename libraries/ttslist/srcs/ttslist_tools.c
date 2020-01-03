/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:40:12 by abiri             #+#    #+#             */
/*   Updated: 2019/12/19 02:53:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"

void	*tts_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = malloc(size);
	if (!mem)
		return (NULL);
	while (i < size)
		mem[i++] = 0;
	return (mem);
}

void	tts_bzero(void *mem, size_t size)
{
	unsigned char	*bytes;
	size_t			i;

	i = 0;
	bytes = mem;
	while (i < size)
	{
		bytes[i] = 0;
		i++;
	}
}
