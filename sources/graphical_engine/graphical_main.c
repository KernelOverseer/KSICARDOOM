/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:58:09 by abiri             #+#    #+#             */
/*   Updated: 2020/01/16 14:05:41 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical_engine.h"

void	ft_render_scene(t_graphical_scene *scene)
{
	ft_draw_skybox(scene);
	ft_raycast(scene);
}
