/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:37:58 by merras            #+#    #+#             */
/*   Updated: 2019/08/01 17:33:51 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

void	t_string_del(t_string *list)
{
	t_string *temp;
	t_string *next;

	temp = list;
	while (temp)
	{
		next = temp->next;
		ft_strdel(&(temp->string));
		free(temp);
		temp = next;
	}
}
