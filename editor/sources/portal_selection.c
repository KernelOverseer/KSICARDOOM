/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:00:20 by abiri             #+#    #+#             */
/*   Updated: 2020/01/06 19:49:37 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_portal *ft_select_portal(t_doom_editor *env, int x, int y)
{
    t_portal    *result;
    t_portal    *current;
    t_sector    *sector;
    double      min_dist;
    double      distance;

    min_dist = POS_INF;
    sector = env->data.current_sector;
    sector->portals.iterator = sector->portals.first;
    while ((current = ttslist_iter_content(&sector->portals)))
    {
        distance = ft_segment_distance_sq(ft_screen_to_map((t_point){x, y},
                env->event.scale, env->event.offset),
                        (t_point){current->wall.p1.x, current->wall.p1.y},
                        (t_point){current->wall.p2.x, current->wall.p2.y});
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
        env->event.selected_type = SELECTED_PORTAL;
        ft_reload_portal_settings(env);
        return (result);
    }
    env->event.selected = NULL;
    ft_reload_sector_settings(env);
    return (NULL);
}