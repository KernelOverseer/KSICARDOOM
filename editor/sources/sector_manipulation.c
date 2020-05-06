/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:12:13 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 18:24:29 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    ft_add_sector(void *arg, t_gui_component *button)
{
    t_doom_editor   *env;
    t_sector        *new_sector;

    (void)button;
    env = arg;
    if (!(new_sector = ft_create_new_sector()))
        return ;
    env->data.sectors.push(&(env->data.sectors), new_sector);
	ft_list_sectors(env, &(env->data.sectors));
}
