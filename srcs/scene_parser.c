/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/28 12:59:46 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void    scene_parser(int fd, t_scene *scene)
{
    int read_return;

    while ((read_return = read(fd, NULL, 1)) > 0)
    {

    }
    if (read_return < 0)
		exit(0) ; // read error: do something!
	if (!read_return)
		exit(0) ; // is the file content complete?
}