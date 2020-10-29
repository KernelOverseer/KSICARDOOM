/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_engine.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:30:39 by abiri             #+#    #+#             */
/*   Updated: 2020/10/22 12:18:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_ENGINE_H
# define SOUND_ENGINE_H
# include <SDL_mixer.h>
# include "doom_nukem.h"
# include "ttslist.h"
# define SOUND_EFFECTS_COUNT 7
# define MAX_SOUND_DISTANCE 5000.0

extern	Mix_Chunk *g_sound_list[SOUND_EFFECTS_COUNT];
extern	char *g_sound_file_names[SOUND_EFFECTS_COUNT];
enum	e_sound_names
{
	sound_main_theme,
	sound_menu_move,
	sound_gun_shoot,
	sound_projectile_explosion,
	sound_empty_gun,
	sound_menu_return,
	sound_menu_error
};

int	ft_sound_play_track(uint32_t sound_index, double distance, int loop);
int	ft_init_sound(void);
int	ft_get_sound_body_distance(t_body *body);

#endif