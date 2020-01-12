/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/10 15:29:57 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_parser.h"

int read_textures(int fd, t_sdl_image ***textures, int *textures_count)
{
    int err;
    int i;
    int count;
    t_sdl_image texture;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, textures_count), sizeof(int));
    if (NO_ERROR(err) && !(*textures = malloc(*textures_count * sizeof(t_sdl_image)))
        err = MALLOC_ERROR;
    i = -1;
    while (NO_ERROR(err) && ++i < *textures_count)
    {
        err = IO_ERROR_WRAPPER(read(fd, &(*textures)[i].texture.height, sizeof(TEXTURE_TYPE)));
        err = IO_ERROR_WRAPPER(read(fd, &(*textures)[i].texture.width, sizeof(TEXTURE_TYPE)));
        if (NO_ERROR(err) &&
            !((*texture)[i] = malloc(sizeof(TEXTURE_TYPE) * (*textures)[i].texture.height *
                (*textures)[i].texture.width)))
            err = MALLOC_ERROR;
        err = IO_ERROR_WRAPPER(read(fd, (*textures)[i].texture.pixels,
            sizeof(TEXTURE_TYPE) * *textures)[i].texture.height *
                (*textures)[i].texture.width));
    }
    return (err);
}


int portal_reader(int fd, t_portal *portal, t_sdl_image **textures)
{
    int err;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, &portal->wall, sizeof(t_wall)));
    err = IO_ERROR_WRAPPER(read(fd, &portal->sector_id, sizeof(int)));
    return (err);
}

int animation_reader(int fd, t_animation *animation, t_sdl_image **textures)
{
    int err;
    int texture_index;
    int i;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, &animation->current_frame, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &animation->speed, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &animation->frame_count, sizeof(int)));
    err = IO_ERROR_WRAPPER(read(fd, &animation->now_time, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(read(fd, &animation->type, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(read(fd, &animation->type, sizeof(uint32_t)));
    i = -1;
    animation->textures = NULL;
    if (NO_ERROR(err) && !(animation->textures = malloc(sizeof(t_sdl_image) * animation->frame_count)))
        err = MALLOC_ERROR;
    while (NO_ERROR(err) && ++i < animation->frame_count)
    {
        err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
        animation->textures[i] = textures[i];
    }
    if (!NO_ERROR(err))
        free(animation->textures);
    return (err);
}

int sprite_reader(int fd, t_sprite *sprite, t_sdl_image **textures)
{
    int err;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, &sprite->position, sizeof(t_vector)));
    err = IO_ERROR_WRAPPER(read(fd, &sprite->radius, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sprite->height, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sprite->altitude, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sprite->angle, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sprite->props, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(animation_reader(fd, &sprite->animation, textures));
    return (err);
}

int wall_reader(int fd, t_wall *wall, t_sdl_image **textures)
{
    int err;
    int texture_index;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, &wall->p1, sizeof(t_vector)));
    err = IO_ERROR_WRAPPER(read(fd, &wall->p2, sizeof(t_vector)));
    err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
    wall->texture = textures[texture_index];
    err = IO_ERROR_WRAPPER(read(fd, &wall->props, sizeof(uint32_t)));
    return (err);
}

int sector_reader(int fd, t_sector *sector, t_sdl_image **textures)
{
    int err;
    int texture_index;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, &sector->brightness, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sector->floor_height, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sector->ceil_height, sizeof(double)));
    err = IO_ERROR_WRAPPER(read(fd, &sector->props, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
    sector->floor_texture = textures[texture_index];
    err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
    sector->ceil_texture = textures[texture_index];
    err = IO_ERROR_WRAPPER(read_list(fd, &sector->walls, textures, sizeof(t_wall), wall_reader));
    err = IO_ERROR_WRAPPER(read_list(fd, &sector->portals, textures, sizeof(t_portal), portal_reader));
    err = IO_ERROR_WRAPPER(read_list(fd, &sector->sprites, textures, sizeof(t_sprite), sprite_reader));
}

int read_list(int fd, t_list_head *list, t_sdl_image **textures, int content_size, int (* type_reader)(int, void **, t_sdl_image **))
{
    int err;
    void    *content;

    err = 0;
    err = IO_ERROR_WRAPPER(read(fd, &list->size, sizeof(size_t)));
    i = -1;
    while (NO_ERROR(err) && ++i < list->size)
    {
        if (!(content = malloc(content_size))
            err = MALLOC_ERROR;
        err = IO_ERROR_WRAPPER(type_reader(fd, content, textures));
        // here content should be pushed to `list`
    }
    return (err);
}

int scene_parser(char *world_filename, t_graphical_scene *scene)
{
    int fd;
    int err;

    if ((fd = open(world_filename, O_RDONLY)) == -1)
        return (ft_perror("scene_parser", NULL, OPEN_ERROR));
    err = IO_ERROR_WRAPPER(read_textures(&scene->textures, &scene->textures_count));
    err = IO_ERROR_WRAPPER(read(fd, &scene->camera, sizeof(t_camera)));
    err = IO_ERROR_WRAPPER(read_list(fd, &scene->sectors, scene->textures, sizeof(t_sector), sector_reader));
    return (err);
}