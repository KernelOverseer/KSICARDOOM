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
        - scene_dumper() returns != 0 if an error occured during dumping
*/

int     dump_sprites(int fd, t_list_node *sprites)
{
    int err;

    err = 0;
    while (sprites)
    {
        err = write(fd, CAST(sprites, t_sprite), sizeof(t_sprite));
        sprites = sprites->next;
    }
    return(err);
}

int     dump_portals(int fd, t_list_node *portals)
{
    int err;

    err = 0;
    while (portals)
    {
        err = write(fd, CAST(portals, t_portal), sizeof(t_portal));
        portals = portals->next;
    }
    return (err);
}

int     dump_walls(int fd, t_list_node *walls)
{
    int err;

    err = 0;
    while (walls)
    {
        err = write(fd, CAST(walls, t_wall), sizeof(t_wall));
        walls = walls->next;
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
        dump_walls(fd, CAST(sectors, t_sector)->walls.first);
        dump_portals(fd, CAST(sectors, t_sector)->walls.first);
        dump_sprites(fd, CAST(sectors, t_sector)->walls.first);
        sectors = sectors->next;
    }
    return (err);
}

int     scene_dumper(t_graphical_scene scene)
{
    int         fd;
    int         err;

    err = 0;
    if (fd = open("doom_nukem_world", O_CREAT | O_EXCL) == -1)
        return (OPEN_ERROR);
    err = write(fd, &scene.current_sector->index, CSECTOR);
    err = dump_sectors(fd, scene.sectors.first);
    return (err);
}