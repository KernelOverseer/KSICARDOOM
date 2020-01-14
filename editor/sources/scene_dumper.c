/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_dumper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/14 21:24:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_dumper.h"

/*
    [DEPRECATED]
    dumper-based conventions:
        - indexes are 0 based;
        - following elements listing is conventioned:
            - first CSECTOR bytes: current sector index;
            - sector lists brightness, floor_height, ceil_height, props are listed according to thier sizeof;
            - walls, portals, sprites nodes content is list respectively;
        - scene_dumper() returns a value != 0 if an error occured during dumping that should be used to exit after
			calling perror to print correspandant error message.
*/

int     dump_list(int fd, t_list_head *list, void *textures,
            int (* type_serializer)(int, void *, void *))
{
    void    *node;
    int     err;

    err = 0;
    while ((node = (t_sector *)ttslist_iter_content(list)))
        err = IO_ERROR_WRAPPER(type_serializer(fd, node, textures));
    return (err);
}

int     scene_dumper(t_graphical_scene scene)
{
    int         fd;
    int         err;
	int			index;
    t_sdl_image **textures;

    err = 0;
    if ((fd = open("doom_nukem.world", O_CREAT | O_WRONLY)) == -1)
        return (IO_ERROR);
    ft_putendl("dunmping textures..");
    err = IO_ERROR_WRAPPER(write(fd, &scene.textures_count, sizeof(int)));
	index = 0;
	textures = scene.textures;
    while (index < scene.textures_count)
        err = IO_ERROR_WRAPPER(texture_serializer(fd, textures[index++]));
    ft_putendl("dunmping camera..");
    err = IO_ERROR_WRAPPER(write(fd, &scene.camera, sizeof(t_camera)));
    ft_putendl("dunmping sectors..");
    err = IO_ERROR_WRAPPER(dump_list(fd, &scene.sectors, scene.textures, sector_serializer));
    return (err);
}
