/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_dumper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/28 12:59:46 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumper_parser.h"

/*
    dumper-based conventions:
        - indexes are 0 based;
        - following elements listing is conventioned:
            - first CSECTOR bytes: current sector index;
            - sector lists brightness, floor_height, ceil_height, props are listed according to thier sizeof;
            - walls, portals, sprites nodes content is list respectively;
        - scene_dumper() returns a value != 0 if an error occured during dumping that should be used to exit after
			calling perror to print correspandant error message.
*/

int     list_dumper(int fd, t_list_node *nodes, int content_size)
{
    int err;

    err = 0;
    while (nodes)
    {
        err = write(fd, nodes->content, content_size);
        nodes = nodes->next;
    }
    return (err);
}

int    dump_sectors(int fd, t_list_node *sectors)
{
    int err;

    while(sectors)
    {
        err = write(fd, &CAST(sectors, t_sector)->brightness, sizeof(double));
        err = write(fd, &CAST(sectors, t_sector)->floor_height, sizeof(double));
        err = write(fd, &CAST(sectors, t_sector)->ceil_height, sizeof(double));
        err = write(fd, &CAST(sectors, t_sector)->props, sizeof(uint32_t));
        err = write(fd, &CAST(sectors, t_sector)->floor_texture, sizeof(uint32_t));
        err = write(fd, &CAST(sectors, t_sector)->ceil_texture, sizeof(uint32_t));
        list_dumper(fd, CAST(sectors, t_sector)->walls.first, sizeof(t_wall));
        list_dumper(fd, CAST(sectors, t_sector)->walls.first, sizeof(t_portal));
        list_dumper(fd, CAST(sectors, t_sector)->walls.first, sizeof(t_sprite));
        sectors = sectors->next;
    }
    return (err);
}

int     scene_dumper(t_graphical_scene scene, t_graphical_settings settings)
{
    int         fd;
    int         err;

    err = 0;
    if (fd = open("doom_nukem_world", O_CREAT | O_EXCL) == -1)
        return (OPEN_ERROR);
    err = write(fd, &scene.current_sector->index, CSECTOR);
    err = dump_sectors(fd, scene.sectors.first);
    err = dump_textures(fd, settings.textures);
    return (err);
}