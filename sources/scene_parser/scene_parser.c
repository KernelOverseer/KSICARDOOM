/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/06 20:46:58 by merras           ###   ########.fr       */
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

int read_list(int fd, t_list_head *list, )

int read_sectors()
{

}

int scene_parser(char *world_filename, t_graphical_scene *scene)
{
    int fd;
    int err;

    if ((fd = open(world_filename, O_RDONLY)) == -1)
        return (ft_perror("scene_parser", NULL, OPEN_ERROR));
    err = IO_ERROR_WRAPPER(read_textures(&scene->textures, &scene->textures_count));
    err = IO_ERROR_WRAPPER(read(fd, &scene->camera, sizeof(t_camera)));
    err = IO_ERROR_WRAPPER(read_sectors());
    return (err);
}