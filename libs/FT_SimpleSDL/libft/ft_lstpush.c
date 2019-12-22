/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:09:04 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 15:52:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *head, t_list *new)
{
	if (!head)
		return (new);
	while (head->next)
		head = head->next;
	head->next = new;
	return (new);
}
