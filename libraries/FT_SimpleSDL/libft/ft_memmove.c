/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:29:56 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 16:44:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	void	*tmp;

	i = 0;
	if (!(tmp = malloc(len)))
		return (NULL);
	tmp = ft_memcpy(tmp, src, len);
	while (i < len)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(tmp + i));
		i++;
	}
	free(tmp);
	return (dst);
}
