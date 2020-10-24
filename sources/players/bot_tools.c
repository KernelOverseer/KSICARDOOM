/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:13:49 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 19:40:05 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ft_create_player_sprite(t_player *player)
{
	t_sprite	*result;

	if (!(result = ft_memalloc(sizeof(t_sprite))))
		return (0);
	player->sprite = result;
	player->sector->sprites.push(&player->sector->sprites, result);
	return (1);
}

int		ft_fill_player_sprite_textures(t_graphical_scene *scene, t_player *player,
	int texture_index, int texture_count)
{
	t_sprite	*sprite;
	size_t		i;

	sprite = player->sprite;
	i = 0;
	if (!(sprite->animation.textures =
		ft_memalloc(sizeof(t_sdl_image *) * texture_count)))
		return (0);
	sprite->props = PROP_FOLLOW_ANGLE;
	sprite->animation.props = PROP_FOLLOW_ANGLE;
	sprite->animation.type = ANIMATION_TYPE_DIRECTION;
	while (i < texture_count && texture_index + i < scene->textures_count)
	{
		sprite->animation.textures[i] = &scene->textures[texture_index + i];
		i++;
	}
	sprite->animation.frame_count = i;
	sprite->animation.speed = 1;
	return (1);
}

int		ft_on_animation_end(t_animation animation, uint64_t expiration)
{
	if (g_doom_env->timer.current_time > expiration)
		return (1);
	if (animation.reps > 0)
		return (1);
	return (0);
}