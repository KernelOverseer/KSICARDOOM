/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 01:41:05 by abiri             #+#    #+#             */
/*   Updated: 2019/12/19 03:16:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttslist.h"
#include <stdio.h>

int main(void)
{
	t_list_head head;
	t_list_head head2;

	ttslist_init(&head2);
	ttslist_init(&head);
	printf("count : %zu\n", head.size);
	head.push(&head, "Hello");
	printf("count : %zu\n", head.size);
	head.push(&head, "There");
	printf("count : %zu\n", head.size);
	head.push(&head2, "There1");
	head.push(&head2, "There2");
	head.push(&head2, "There3");
	head.push(&head2, "There4");

	char *content;
	while ((content = ttslist_iter_content(&head)))
		printf(":=> %s\n", content);
	ttslist_iter_content(NULL);
	printf("Re iterating\n");
	while ((content = ttslist_iter_content(&head)))
		printf(":=> %s\n", content);
	printf("iterating another list\n");
	while ((content = ttslist_iter_content(&head2)))
		printf(":=> %s\n", content);
	return (0);
}
