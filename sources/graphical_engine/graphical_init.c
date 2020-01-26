/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:55:20 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 20:22:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	ft_init_graphical_scene(t_doom_env *env)
{
	ttslist_init(&(env->main_scene.sectors));
	if (!(env->main_scene.render_image =
				newimage(CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT)))
		return (ERROR);
	env->main_scene.camera.tilt = - CONF_WINDOW_HEIGHT / 2;
	env->main_scene.camera.height = CONF_CAMERA_HEIGHT;
	return (SUCCESS);
}
