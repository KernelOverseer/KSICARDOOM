/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:23:22 by abiri             #+#    #+#             */
/*   Updated: 2018/11/06 15:22:07 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;
	size_t	counter;

	counter = 0;
	if (!(result = malloc(size)))
		return (NULL);
	while (counter < size)
		((unsigned char*)result)[counter++] = 0;
	return (result);
}
