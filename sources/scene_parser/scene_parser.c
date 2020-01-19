/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   scene_parser.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: merras <merras@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/07/30 20:39:07 by merras			#+#	#+#			 */
/*   Updated: 2020/01/14 22:08:04 by merras		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "scene_parser.h"

int read_list(int fd, t_list_head *list, t_sdl_image **textures, int content_size, int (* type_reader)(int, void *, t_sdl_image **))
{
	int err;
	void	*content;
	int	i;

	err = 0;
	err = IO_ERROR_WRAPPER(read(fd, &list->size, sizeof(size_t)));
	i = -1;
	while (NO_ERROR(err) && (size_t)++i < list->size)
	{
		if (!(content = malloc(content_size)))
			err = MALLOC_ERROR;
		err = IO_ERROR_WRAPPER(type_reader(fd, content, textures));
		// here content should be pushed to `list`
	}
	return (err);
}

int read_textures(int fd, t_sdl_image ***textures, int *textures_count)
{
	int err;
	int i;
	int count;
	t_sdl_image texture;

	(void)count;
	(void)texture;
	err = 0;
	err = IO_ERROR_WRAPPER(read(fd, textures_count, sizeof(int)));
	if (NO_ERROR(err) && !(*textures = malloc(*textures_count * sizeof(t_sdl_image))))
		err = MALLOC_ERROR;
	i = -1;
	while (NO_ERROR(err) && ++i < *textures_count)
	{
		err = IO_ERROR_WRAPPER(read(fd, &((*textures)[i])->height, sizeof(TEXTURE_TYPE)));
		err = IO_ERROR_WRAPPER(read(fd, &((*textures)[i])->width, sizeof(TEXTURE_TYPE)));
		if (NO_ERROR(err) &&
			!(((*textures)[i])->pixels = malloc(sizeof(TEXTURE_TYPE) * ((*textures)[i])->height *
				((*textures)[i])->width)))
			err = MALLOC_ERROR;
		err = IO_ERROR_WRAPPER(read(fd, (*textures)[i]->pixels,
			sizeof(TEXTURE_TYPE) * (*textures)[i]->height *
				(*textures)[i]->width));
	}
	return (err);
}


int portal_reader(int fd, void *portal, t_sdl_image **textures)
{
	int err;

	(void)textures;
	err = 0;
	err = IO_ERROR_WRAPPER(read(fd, &CAST(portal, t_portal*)->wall, sizeof(t_wall)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(portal, t_portal*)->sector->id, sizeof(int)));
	return (err);
}

int animation_reader(int fd, void *animation, t_sdl_image **textures)
{
	int err;
	int texture_index;
	int i;

	err = 0;
	err = IO_ERROR_WRAPPER(read(fd, &CAST(animation, t_animation*)->current_frame, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(animation, t_animation*)->speed, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(animation, t_animation*)->frame_count, sizeof(int)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(animation, t_animation*)->now_time, sizeof(uint32_t)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(animation, t_animation*)->type, sizeof(uint32_t)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(animation, t_animation*)->type, sizeof(uint32_t)));
	i = -1;
	CAST(animation, t_animation*)->textures = NULL;
	if (NO_ERROR(err) && !(CAST(animation, t_animation*)->textures = malloc(sizeof(t_sdl_image) * CAST(animation, t_animation*)->frame_count)))
		err = MALLOC_ERROR;
	while (NO_ERROR(err) && ++i < CAST(animation, t_animation*)->frame_count)
	{
		err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
		CAST(animation, t_animation*)->textures[i] = textures[i];
	}
	if (!NO_ERROR(err))
		free(CAST(animation, t_animation*)->textures);
	return (err);
}

int sprite_reader(int fd, void *sprite, t_sdl_image **textures)
{
	int err;

	err = 0;
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sprite, t_sprite*)->position, sizeof(t_vector)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sprite, t_sprite*)->radius, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sprite, t_sprite*)->height, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sprite, t_sprite*)->altitude, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sprite, t_sprite*)->angle, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sprite, t_sprite*)->props, sizeof(uint32_t)));
	err = IO_ERROR_WRAPPER(animation_reader(fd, &CAST(sprite, t_sprite *)->animation, textures));
	return (err);
}

int wall_reader(int fd, void *wall, t_sdl_image **textures)
{
	int err;
	int texture_index;

	err = 0;
	texture_index = 0;
	err = IO_ERROR_WRAPPER(read(fd, &CAST(wall, t_wall *)->p1, sizeof(t_vector)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(wall, t_wall *)->p2, sizeof(t_vector)));
	err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
	CAST(wall, t_wall *)->texture = textures[texture_index];
	err = IO_ERROR_WRAPPER(read(fd, &CAST(wall, t_wall *)->props, sizeof(uint32_t)));
	return (err);
}

int sector_reader(int fd, void *sector, t_sdl_image **textures)
{
	int err;
	int texture_index;

	err = 0;
	texture_index = 0;
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sector, t_sector*)->brightness, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sector, t_sector*)->floor_height, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sector, t_sector*)->ceil_height, sizeof(double)));
	err = IO_ERROR_WRAPPER(read(fd, &CAST(sector, t_sector*)->props, sizeof(uint32_t)));
	err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
	CAST(sector, t_sector*)->floor_texture = textures[texture_index];
	err = IO_ERROR_WRAPPER(read(fd, &texture_index, sizeof(int)));
	CAST(sector, t_sector*)->ceil_texture = textures[texture_index];
	err = IO_ERROR_WRAPPER(read_list(fd, &CAST(sector, t_sector*)->walls, textures, sizeof(t_wall), wall_reader));
	err = IO_ERROR_WRAPPER(read_list(fd, &CAST(sector, t_sector*)->portals, textures, sizeof(t_portal), portal_reader));
	err = IO_ERROR_WRAPPER(read_list(fd, &CAST(sector, t_sector*)->sprites, textures, sizeof(t_sprite), sprite_reader));
	return (err);
}

int scene_parser(char *world_filename, t_graphical_scene *scene)
{
	int fd;
	int err;

	err = 0;
	if ((fd = open(world_filename, O_RDONLY)) == -1)
		return (OPEN_ERROR);
	err = IO_ERROR_WRAPPER(read_textures(fd, &scene->textures, &scene->textures_count));
	err = IO_ERROR_WRAPPER(read(fd, &scene->camera, sizeof(t_camera)));
	err = IO_ERROR_WRAPPER(read_list(fd, &scene->sectors, scene->textures, sizeof(t_sector), sector_reader));
	return (err);
}
