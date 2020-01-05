/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_serializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/05 21:08:11 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_dumper.h"

int texture_serializer(int fd, void *texture)
{
    int err;

    err = write(fd, &CAST(texture, t_sdl_image)->height, sizeof(TEXTURE_TYPE));
    err = write(fd, &CAST(texture, t_sdl_image)->width, sizeof(TEXTURE_TYPE));
    err = write(fd, CAST(texture, t_sdl_image)->pixels, sizeof(TEXTURE_TYPE) *
        CAST(texture, t_sdl_image)->height *
        CAST(texture, t_sdl_image)->width);
    return (err);
}

int wall_serializer(int fd, void *wall, void *texture_offset)
{
    int err;
    int texture_index;

    err = 0;
    err = write(fd, &CAST(wall, t_wall)->p1, sizeof(t_vector));
    err = write(fd, &CAST(wall, t_wall)->p1, sizeof(t_vector));
    texture_index = CAST(wall, t_wall)->texture - (t_sdl_image *)texture_offset;
    err = write(fd, &texture_index, sizeof(int));
    err = write(fd, &CAST(wall, t_wall)->props, sizeof(uint32_t));
    
    return (err);
}

int animation_serializer(int fd, void *animation, void *texture_offset)
{
    int         err;
    int         texture_index;
    t_sdl_image **texture;

    err = 0;
    err = write(fd, &CAST(animation, t_animation)->current_frame, sizeof(double));
    err = write(fd, &CAST(animation, t_animation)->speed, sizeof(double));
    err = write(fd, &CAST(animation, t_animation)->frame_count, sizeof(int));
    err = write(fd, &CAST(animation, t_animation)->now_time, sizeof(uint32_t));
    err = write(fd, &CAST(animation, t_animation)->type, sizeof(uint32_t));
    err = write(fd, &CAST(animation, t_animation)->type, sizeof(uint32_t));
    texture = CAST(animation, t_animation)->textures;
    while (*texture)
    {
        texture_index = *texture - (t_sdl_image *)texture_offset;
        err = write(fd, &texture_index, sizeof(int));
        texture++;
    }
    return (err);
}

int sprite_serializer(int fd, void *sprite, void *texture_offset)
{
    int err;

    err = 0;
    err = write(fd, &CAST(sprite, t_sprite)->position, sizeof(t_vector));
    err = write(fd, &CAST(sprite, t_sprite)->radius, sizeof(double));
    err = write(fd, &CAST(sprite, t_sprite)->height, sizeof(double));
    err = write(fd, &CAST(sprite, t_sprite)->altitude, sizeof(double));
    err = write(fd, &CAST(sprite, t_sprite)->angle, sizeof(double));
    err = write(fd, &CAST(sprite, t_sprite)->props, sizeof(uint32_t));
    err = animation_serializer(fd, &CAST(sprite, t_sprite)->animation, texture_offset);
    return (err);
}

int sector_serializer(int fd, void *sector, void *texture_offset)
{
    int err;
    int texture_index;

    err = 0;
    err = write(fd, &CAST(sector, t_sector)->brightness, sizeof(double));
    err = write(fd, &CAST(sector, t_sector)->floor_height, sizeof(double));
    err = write(fd, &CAST(sector, t_sector)->ceil_height, sizeof(double));
    err = write(fd, &CAST(sector, t_sector)->props, sizeof(uint32_t));
    texture_index = CAST(sector, t_sector)->floor_texture - (t_sdl_image *)texture_offset;
    err = write(fd, &texture_index, sizeof(int));
    texture_index = CAST(sector, t_sector)->ceil_texture - (t_sdl_image *)texture_offset;
    err = write(fd, &texture_index, sizeof(int));
    return (err);
}