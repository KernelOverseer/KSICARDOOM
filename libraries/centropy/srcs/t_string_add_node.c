/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_add_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 04:43:19 by merras            #+#    #+#             */
/*   Updated: 2019/08/03 16:16:16 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"
#include <stdio.h>

t_string	*t_string_create_node(t_string node_value)
{
	t_string *node;

	node = (t_string *)malloc(sizeof(t_string));
	*node = node_value;
	return (node);
}

void		t_string_push(t_string **head, char *string)
{
	t_string *i;

	if (!head)
		return ;
	if (!*head)
		*head = t_string_create_node((t_string){string, NULL, NULL});
	else
	{
		i = *head;
		while (i->next)
			i = i->next;
		i->next = t_string_create_node((t_string) {string, NULL, i});
	}
}

void		t_string_pop(t_string **head)
{
	t_string *i;

	if (!head || !*head)
		return ;
	i = *head;
	if (!i->next)
	{
		free(i);
		i = NULL;
	}
	while (i->next->next)
		i = i->next;
	free(i->next);
	i->next = NULL;
}

void		t_string_free_node(t_string *node)
{
	ft_strdel(&node->string);
	free(node);
}

void		t_string_del_node(t_string **head, t_string *node)
{
	t_string *i;
	t_string *temp;

	if (!node || !head)
		return ;
	i = *head;
	if (node == *head)
	{
		t_string_free_node(node);
		*head = (*head)->next;
	}
	temp = i;
	i = i->next;
	while (i)
	{
		if (i == node)
		{
			temp->next = i->next;
			t_string_free_node(node);
		}
		temp = i;
		i = i->next;
	}
}
