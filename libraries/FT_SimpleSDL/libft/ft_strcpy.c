/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:25:17 by abiri             #+#    #+#             */
/*   Updated: 2018/10/04 13:57:05 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int counter;
	int ended;

	counter = 0;
	ended = 0;
	while (!ended)
	{
		if (src[counter] == '\0')
			ended = 1;
		dst[counter] = src[counter];
		counter++;
	}
	return (dst);
}
