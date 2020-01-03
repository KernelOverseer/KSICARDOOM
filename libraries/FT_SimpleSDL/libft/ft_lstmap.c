/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:59:39 by abiri             #+#    #+#             */
/*   Updated: 2018/10/10 18:42:44 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*first;
	t_list	*final;

	node = lst;
	while (node)
	{
		if (node == lst)
		{
			final = f(node);
			first = final;
		}
		else
		{
			final->next = f(node);
			final = final->next;
		}
		node = node->next;
	}
	return (first);
}
