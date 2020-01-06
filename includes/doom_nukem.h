/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:48:17 by abiri             #+#    #+#             */
/*   Updated: 2020/01/06 13:09:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H
# include "centropy.h"
# include "libgl.h"
# include "ttslist.h"
# include "ft_simplesdl.h"
# include "drawing.h"
# include "config.h"
# include "error_management.h"
# include "graphical_engine.h"
# define ERROR 0
# define SUCCESS 1

typedef struct	s_doom_env
{
	t_sdl_env			display;
	t_graphical_scene	main_scene;
	t_sdl_image			*main_image;
	unsigned char		keys[SDL_KEY_COUNT];
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

int	ft_init_game_window(t_doom_env *env);
int	ft_init_graphical_scene(t_doom_env *env);

/*
**	SDL EVENTS FUNCTIONS
*/

int	ft_keyboard_button_on(void *arg, SDL_Event e);
int	ft_keyboard_button_off(void *arg, SDL_Event e);

/*
**	DRAWING FUNCTIONS
*/

void    ft_blit_image(t_rect rect, t_sdl_image *texture,
		t_sdl_image *main_image);

#endif
