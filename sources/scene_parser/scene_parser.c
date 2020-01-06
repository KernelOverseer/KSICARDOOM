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

int read_textures(int fd, t_sdl_image **textures)
{
    int i;
    int count;
    t_sdl_image texture;

    err = read(fd, &texture.height, sizeof(TEXTURE_TYPE));
    err = read(fd, &texture.width, sizeof(TEXTURE_TYPE));
    if (err)
        malloc(sizeof(TEXTURE_TYPE) * texture.height * texture.width);
    err = read(fd, texture.pixels, sizeof(TEXTURE_TYPE) * texture.height * texture.width);
    
}

int scene_parser(char *world_filename, t_graphical_scene *scene)
{
    int fd;
    int err;

    if ((fd = open()) == -1)
        return (ft_perror("scene_parser", NULL, OPEN_ERROR));
    err = read_textures(&(scene->textures));
}