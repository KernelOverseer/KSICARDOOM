/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 01:33:42 by abiri             #+#    #+#             */
/*   Updated: 2020/05/14 02:10:11 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sprite	*ft_select_sprite(t_doom_editor *env, int x, int y)
{
	t_sector	*sector;
	t_sprite	*sprite;
	t_point		sprite_pos;

	printf("GONNA SELECT SPRITE\n");
	sector = env->data.current_sector;
	sector->sprites.iterator = sector->sprites.first;
	while ((sprite = ttslist_iter_content(&(sector->sprites))))
	{
		sprite_pos = (t_point){sprite->position.x, sprite->position.y};
		if (ft_point_in_radius(sprite_pos, ft_screen_to_map((t_point){x, y},
	env->event.scale, env->event.offset), SELECT_DISTANCE * env->event.scale))
		{
			env->event.selected = sprite;
			env->event.selected_type = SELECTED_SPRITE;
			ft_reload_sprite_settings(env);
			return (sprite);
		}
	}
	return (NULL);
}