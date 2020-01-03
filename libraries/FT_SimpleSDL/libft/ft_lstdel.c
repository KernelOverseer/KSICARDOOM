/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:19:34 by abiri             #+#    #+#             */
/*   Updated: 2018/10/07 10:50:15 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*obj;
	t_list	*next;

	if (alst != NULL)
	{
		obj = *alst;
		while (obj != NULL)
		{
			next = obj->next;
			del(obj->content, obj->content_size);
			free(obj);
			obj = next;
		}
		*alst = NULL;
	}
}
