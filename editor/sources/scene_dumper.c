/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_dumper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/05 21:09:49 by merras           ###   ########.fr       */
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
        err = type_serializer(fd, node, textures);
    return (err);
}

int     scene_dumper(t_graphical_scene scene)
{
    int         fd;
    int         err;
    t_sdl_image *textures;

    err = 0;
    if ((fd = open("doom_nukem.world", O_CREAT | O_EXCL | O_WRONLY)) == -1)
        return (OPEN_ERROR);
    textures = scene.textures;
    while (textures)
    {
        err = texture_serializer(fd, textures);
        textures++;
    }
    err = write(fd, &scene.camera, sizeof(t_camera));
    err = dump_list(fd, &scene.sectors, scene.textures, sector_serializer);
    return (err);
}