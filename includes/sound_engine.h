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
# include <SDL.h>
# include "ttslist.h"

typedef struct s_sound_track
{
	Uint32 length;
	Uint8 	*buffer;
	SDL_AudioSpec spec;
	Uint8 *audio_pos;
	Uint32 audio_len;
} t_sound_track;

typedef struct s_sound_engine
{
	t_list_head		sound_tracks;
} t_sound_engine;

t_sound_track	*ft_new_track(char *path);
int				ft_sound_play_track(t_sound_track *track);
#endif