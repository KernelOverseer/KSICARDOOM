/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:07:39 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 22:15:09 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

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
        if (!(new_wall = ft_new_wall()))
            return (0);
        new_wall->p1 = (t_vector){p1->x, p1->y};
        new_wall->p2 = (t_vector){p2->x, p2->y};
        env->data.current_sector->walls.push(
            &(env->data.current_sector->walls),
            new_wall);
        env->event.selected = NULL;
    }
    return (1);
}