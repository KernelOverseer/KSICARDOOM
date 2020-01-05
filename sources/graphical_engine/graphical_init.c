/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:55:20 by abiri             #+#    #+#             */
/*   Updated: 2020/01/05 21:49:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_init_graphical_scene(t_doom_env *env)
{
	ttslist_init(&(env->main_scene.sectors));
	if (!(env->main_scene.render_image =
				newimage(CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT)))
		return (ERROR);
	return (SUCCESS);
}
