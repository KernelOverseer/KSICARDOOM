/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:29:08 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 16:29:09 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_point ft_screen_to_map(t_point point, double scale, t_point offset)
{
    t_point result;

    result.x = (double)(point.x - offset.x) * scale;
    result.y = (double)(point.y - offset.y) * scale;
    return (result);
}

t_point ft_map_to_screen(t_point point, double scale, t_point offset)
{
    t_point result;

    result.x = (point.x / scale) + offset.x;
    result.y = (point.y / scale) + offset.y;
    return (result);
}