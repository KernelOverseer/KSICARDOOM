/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_dumper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/05 21:02:32 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_DUMPER_H
# define SCENE_DUMPER_H

# include "editor.h"

# define TEXTURE_TYPE uint32_t
# define CAST(pointer, type) ((type *)pointer)

int scene_dumper(t_graphical_scene scene);
int dump_list(int fd, t_list_head *list, void *textures,
        int (* type_serializer)(int, void *, void *));

int texture_serializer(int fd, void *texture);
int wall_serializer(int fd, void *wall, void *texture_offset);
int animation_serializer(int fd, void *animation, void *texture_offset);
int sprite_serializer(int fd, void *sprite, void *texture_offset);
int sector_serializer(int fd, void *sector, void *texture_offset);

# define OPEN_ERROR 1

#endif