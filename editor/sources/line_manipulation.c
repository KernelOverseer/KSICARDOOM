/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:07:39 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 20:23:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sector	*ft_create_new_sector(void)
{
	t_sector	*result;
	static int	id = 0;

	result = ft_memalloc(sizeof(t_sector));
	if (!result)
		return (NULL);
	ttslist_init(&result->portals);
	ttslist_init(&result->walls);
	ttslist_init(&result->sprites);
	result->brightness = 1;
	result->id = ++id;
	return (result);
}

int ft_add_portal(t_doom_editor *env, t_point *p1, t_point *p2)
{
    t_portal    *new_portal;

    if (!env->data.current_sector || !p1 || !p2)
    {
        env->event.selected = NULL;
        return (0);
    }
    else
    {
        if (!(new_portal = ft_memalloc(sizeof(t_portal))))
            return (0);
        new_portal->wall.p1 = (t_vec2){p1->x, p1->y};
        new_portal->wall.p2 = (t_vec2){p2->x, p2->y};
        env->data.current_sector->portals.push(
            &(env->data.current_sector->portals),
            new_portal);
        env->event.selected = NULL;
    }
    return (1);
}

int ft_add_wall(t_doom_editor *env, t_point *p1, t_point *p2)
{
    t_wall  *new_wall;

    if (!env->data.current_sector || !p1 || !p2)
    {
        env->event.selected = NULL;
        return (0);
    }
    else
    {
        if (!(new_wall = ft_memalloc(sizeof(t_wall))))
            return (0);
        new_wall->p1 = (t_vec2){p1->x, p1->y};
        new_wall->p2 = (t_vec2){p2->x, p2->y};
        env->data.current_sector->walls.push(
            &(env->data.current_sector->walls),
            new_wall);
        env->event.selected = NULL;
    }
    return (1);
}