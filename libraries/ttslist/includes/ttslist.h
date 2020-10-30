/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttslist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:39:14 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 03:48:04 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTSLIST_H
# define TTSLIST_H
# include <stdlib.h>

typedef struct	s_list_node
{
	void				*content;
	size_t				content_size;
	struct s_list_node	*prev;
	struct s_list_node	*next;
}				t_list_node;

typedef struct	s_list_head	t_list_head;

typedef		t_list_node *t_list_add_function(t_list_head *head, void *content);
typedef		void		*t_list_pop_function(t_list_head *head);

struct	s_list_head
{
	t_list_node			*first;
	t_list_node			*last;
	t_list_node			*iterator;
	size_t				size;
	t_list_add_function	*push;
	t_list_add_function	*push_front;
	t_list_pop_function	*pop;
	t_list_pop_function	*pop_front;
};

void		ttslist_init(t_list_head *head);
t_list_node	*ttslist_push(t_list_head *head, t_list_node *newnode);
t_list_node	*ttslist_push_front(t_list_head *head, t_list_node *newnode);
t_list_node *ttslist_push_front_new(t_list_head *head, void *content);
t_list_node	*ttslist_push_new(t_list_head *head, void *content);
t_list_node	*ttslist_new_node(void *content, size_t content_size);
t_list_node	*ttslist_pop(t_list_head *head);
t_list_node	*ttslist_pop_front(t_list_head *head);
void		*ttslist_pop_front_content(t_list_head *head);
void		*ttslist_pop_content(t_list_head *head);
void		*ttslist_splice(t_list_head *head, t_list_node *node);
void		*tts_memalloc(size_t size);
void		*ttslist_iter_content(t_list_head	*head);
t_list_node	*ttslist_iter(t_list_head *head);
void		tts_bzero(void *mem, size_t size);
void		*ttslist_get_id_content(t_list_head *head, int id);
void		ttslist_purge(t_list_head *list, void (*purge)(void *));
int			ttslist_get_content_id(t_list_head *head, void *content);
int			ttslist_remove_node_with_content(t_list_head *list, void *content);

#endif
