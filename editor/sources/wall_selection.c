/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:19:00 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 19:15:44 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_wall  *ft_select_wall(t_doom_editor *env, int x, int y)
{
    t_wall      *result;
    t_wall      *current;
    t_sector    *sector;
    double      min_dist;
    double      distance;

    min_dist = POS_INF;
    sector = env->data.current_sector;
    sector->walls.iterator = sector->walls.first;
    while ((current = ttslist_iter_content(&sector->walls)))
    {
        distance = ft_segment_distance_sq(ft_screen_to_map((t_point){x, y},
                env->event.scale, env->event.offset),
                        (t_point){current->p1.x, current->p1.y},
                        (t_point){current->p2.x, current->p2.y});
        if (distance < min_dist)
        {
            min_dist = distance;
            result = current;
        }
    }
    if (min_dist < (SELECT_DISTANCE * env->event.scale) * (SELECT_DISTANCE *
        env->event.scale))
    {
        env->event.selected = result;
        env->event.selected_type = SELECTED_WALL;
        ft_reload_wall_settings(env);
        return (result);
    }
    env->event.selected = NULL;
    ft_reload_sector_settings(env);
    return (NULL);
}