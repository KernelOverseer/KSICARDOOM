/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_serializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/08 18:31:51 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_dumper.h"

int texture_serializer(int fd, void *texture)
{
    int err;

    err = 0;
    err = IO_ERROR_WRAPPER(write(fd, &CAST(texture, t_sdl_image)->height, sizeof(TEXTURE_TYPE)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(texture, t_sdl_image)->width, sizeof(TEXTURE_TYPE)));
    err = IO_ERROR_WRAPPER(write(fd, CAST(texture, t_sdl_image)->pixels, sizeof(TEXTURE_TYPE) *
        CAST(texture, t_sdl_image)->height *
        CAST(texture, t_sdl_image)->width));
    return (err);
}

int wall_serializer(int fd, void *wall, void *texture_offset)
{
    int err;
    int texture_index;

    err = 0;
    err = IO_ERROR_WRAPPER(write(fd, &CAST(wall, t_wall)->p1, sizeof(t_vector)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(wall, t_wall)->p1, sizeof(t_vector)));
    texture_index = CAST(wall, t_wall)->texture - (t_sdl_image *)texture_offset;
    err = IO_ERROR_WRAPPER(write(fd, &texture_index, sizeof(int)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(wall, t_wall)->props, sizeof(uint32_t)));
    return (err);
}

int animation_serializer(int fd, void *animation, void *texture_offset)
{
    int         err;
    int         texture_index;
    t_sdl_image **texture;

    err = 0;
    err = IO_ERROR_WRAPPER(write(fd, &CAST(animation, t_animation)->current_frame, sizeof(double)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(animation, t_animation)->speed, sizeof(double)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(animation, t_animation)->frame_count, sizeof(int)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(animation, t_animation)->now_time, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(animation, t_animation)->type, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(animation, t_animation)->type, sizeof(uint32_t)));
    texture = CAST(animation, t_animation)->textures;
    while (*texture)
    {
        texture_index = *texture - (t_sdl_image *)texture_offset;
        err = IO_ERROR_WRAPPER(write(fd, &texture_index, sizeof(int)));
        texture++;
    }
    return (err);
}

int sprite_serializer(int fd, void *sprite, void *texture_offset)
{
    int err;

    err = 0;
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sprite, t_sprite)->position, sizeof(t_vector)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sprite, t_sprite)->radius, sizeof(double)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sprite, t_sprite)->height, sizeof(double)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sprite, t_sprite)->altitude, sizeof(double)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sprite, t_sprite)->angle, sizeof(double)));
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sprite, t_sprite)->props, sizeof(uint32_t)));
    err = IO_ERROR_WRAPPER(animation_serializer(fd, &CAST(sprite, t_sprite)->animation, texture_offset));
    return (err);
}

int portal_serializer(int fd, void *portal, void *texture_offset)
{
    int err;

    err = 0;
    err = IO_ERROR_WRAPPER(wall_serializer(fd, &CAST(portal, t_portal)->wall, texture_offset));
    err = IO_ERROR_WRAPPER(write(fd, &CAST((CAST(portal, t_portal)->sector), t_sector)->id, sizeof(int)));
    return (err);
}

int sector_serializer(int fd, void *sector, void *texture_offset)
{
    int err;
    int texture_index;

    err = 0;
    err = IO_ERROR_WRAPPER(write(fd, &CAST(sector, t_sector)->brightness, sizeof(double)));
    err= IO_ERROR_WRAPPER(write(fd, &CAST(sector, t_sector)->floor_height, sizeof(double)));
    err= IO_ERROR_WRAPPER(write(fd, &CAST(sector, t_sector)->ceil_height, sizeof(double)));
    err= IO_ERROR_WRAPPER(write(fd, &CAST(sector, t_sector)->props, sizeof(uint32_t)));
    texture_index = CAST(sector, t_sector)->floor_texture - (t_sdl_image *)texture_offset;
    err = IO_ERROR_WRAPPER(write(fd, &texture_index, sizeof(int)));
    texture_index = CAST(sector, t_sector)->ceil_texture - (t_sdl_image *)texture_offset;
    err = IO_ERROR_WRAPPER(write(fd, &texture_index, sizeof(int)));
    err = IO_ERROR_WRAPPER(dump_list(fd, &CAST(sector, t_sector)->walls, texture_offset, wall_serializer));
    err = IO_ERROR_WRAPPER(dump_list(fd, &CAST(sector, t_sector)->portals, texture_offset, portal_serializer));
    err = IO_ERROR_WRAPPER(dump_list(fd, &CAST(sector, t_sector)->sprites, texture_offset, sprite_serializer));
    return (err);
}