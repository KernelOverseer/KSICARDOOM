/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:43:56 by abiri             #+#    #+#             */
/*   Updated: 2020/01/06 16:50:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int ft_disable_area(t_tts_gui *gui_env, char *area_id)
{
    t_gui_area  *area;

    area = ft_get_area_by_id(gui_env, area_id);
    if (area)
    {
        DISACTIVATE_PROP(area->props, GUI_ACTIVE);
        return (1);
    }
    return (0);
}

int ft_enable_area(t_tts_gui *gui_env, char *area_id)
{
    t_gui_area  *area;

    area = ft_get_area_by_id(gui_env, area_id);
    if (area)
    {
        ACTIVATE_PROP(area->props, GUI_ACTIVE);
        return (1);
    }
    return (0);
}