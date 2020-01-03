/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 22:19:17 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 22:22:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int ft_init_rendering(t_doom_editor *env)
{
    env->data.render_image = newimage(EDIT_WIDTH, EDIT_HEIGHT);
    if (!env->data.render_image)
        return (0);
    ttslist_init(&(env->data.sectors));
    return (1);
}