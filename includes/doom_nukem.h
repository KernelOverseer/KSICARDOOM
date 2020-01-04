/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:48:17 by abiri             #+#    #+#             */
/*   Updated: 2020/01/04 12:21:24 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H
# include "centropy.h"
# include "ttslist.h"
# include "ft_simplesdl.h"
# include "config.h"
# define ERROR 0
# define SUCCESS 1

typedef struct	s_doom_env
{
	t_sdl_env		display;
	unsigned char	keys[SDL_KEY_COUNT];
}				t_doom_env;

/*
** ERROR HANDLING
*/

int		        ft_perror(char *command, char *arg, int err);

# define N_SCENE 0
# define F_OPEN 1

# define N_SCENE_T ": no passed scene file."
# define F_OPEN_T ": cannot open game map: "

/*
**	INITIALISATION FUNCTIONS
*/

int	ft_init_game_window(t_sdl_env *sdl_env);

/*
**	SDL EVENTS FUNCTIONS
*/

int	ft_keyboard_button_on(void *arg, SDL_Event e);
int	ft_keyboard_button_off(void *arg, SDL_Event e);

#endif
