/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_segment_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:48:55 by merras            #+#    #+#             */
/*   Updated: 2019/07/18 22:51:42 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	current_segment_size(char *raw, char delimiter, int index)
{
	int temp;

	temp = index;
	while (raw[--index] != delimiter && index)
		continue;
	return (temp - index - 1);
}
