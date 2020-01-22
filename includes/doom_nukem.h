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
# include "physics_engine.h"
# define ERROR 0
# define SUCCESS 1
# define SECOND 1000000000

typedef void				t_controller_function(void *env, void *body);

typedef struct				s_controller
{
	t_controller_function	*function;
	void					*env;
	void					*body;
}							t_controller;

typedef struct				s_timer
{
	double					delta_time;
	Uint64          		previous_tick;
	Uint64          		current_time;
	void            		(*update_time)(struct	s_timer *);
}							t_timer;

typedef struct				s_doom_env
{
	t_sdl_env				display;
	t_graphical_scene		main_scene;
	t_sdl_image				*main_image;
	unsigned char			keys[SDL_KEY_COUNT];
	t_list_head				controllers;
	t_list_head				bodies;
	t_vec2int				mouse_rel;
	t_vec2int				mouse_pos;
	t_physics_engine		phi;
	t_timer					timer;
}							t_doom_env;

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

int							ft_init_game_window(t_doom_env *env);
int							ft_init_graphical_scene(t_doom_env *env);

/*
**	SDL EVENTS FUNCTIONS
*/

int							ft_keyboard_button_on(void *arg, SDL_Event e);
int							ft_keyboard_button_off(void *arg, SDL_Event e);
int							ft_mouse_data(void *arg, SDL_Event e);

/*
**	DRAWING FUNCTIONS
*/

void						ft_blit_image(t_rect rect, t_sdl_image *texture,
		t_sdl_image *main_image);

/*
**	TIMER FUNCTIONS
*/

void						ft_init_timer(t_timer *timer);
void						ft_update_time(t_timer *timer);

/*
**	PHYSICS FUNCTIONS
*/

void						ft_physics_controllers(void *env);

/*
**	ENTITIES/BODIES FUNCTIONS
*/

int							ft_init_bodies(t_doom_env *env);

/*
** CONTROLLERS FUNCTIONS
*/

void						ft_local_player_input(void *env, void *body);
void						ft_bot_input(void *env, void *body);

#endif
