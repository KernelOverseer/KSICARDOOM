/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   doom_nukem.h									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: abiri <abiri@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/04 11:48:17 by abiri			 #+#	#+#			 */
/*   Updated: 2020/01/22 17:50:58 by abiri			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H
# include "centropy.h"
# include "libgl.h"
# include "ttslist.h"
# include "ft_simplesdl.h"
# include "drawing.h"
# include "config.h"
# include "serializer.h"
# include "error_management.h"
# include "graphical_engine.h"
# include "physics_engine.h"
# include "user_interface.h"
# include "bots.h"
# include <SDL_mixer.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include "sound_engine.h"
# define ERROR 0
# define SUCCESS 1
# define SECOND 1000000000


typedef int					t_controller_function(void *env, void *body);

typedef struct				s_controller
{
	t_controller_function	*function;
	void					*env;
	void					*body;
}							t_controller;

typedef struct				s_timer
{
	double					delta_time;
	Uint64					previous_tick;
	Uint64					current_time;
	void					(*update_time)(struct	s_timer *);
}							t_timer;

typedef struct				s_doom_multiplayer
{
	int	sockfd;
	struct	sockaddr_in	serv_addr;
	struct	hostent		*server;
}					t_doom_multiplayer;

typedef struct				s_doom_env
{
	t_sdl_env				display;
	t_graphical_scene		main_scene;
	t_sdl_image				*main_image;
	unsigned char			keys[SDL_KEY_COUNT];
	unsigned char			mouse_buttons[2];
	t_list_head				controllers;
	t_list_head				bodies;
	t_vec2int				mouse_rel;
	t_vec2int				mouse_pos;
	t_physics_engine		phi;
	t_timer					timer;
	t_menu_system			*menu_manager;
	t_inventory			main_inventory;
	t_doom_multiplayer		network;
}							t_doom_env;

extern	t_doom_env			*g_doom_env;

/*
** ERROR HANDLING
*/

int				ft_perror(char *command, char *arg, int err);

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

void						ft_physics_controllers(void *env, t_body *body);

/*
**	ENTITIES/BODIES FUNCTIONS
*/

int							ft_init_bodies(t_doom_env *env);

/*
** CONTROLLERS FUNCTIONS
*/

int							ft_local_player_input(void *env, void *body);
void						sync_sprite(t_doom_env *env, t_body *body);
int							ft_bot_input(void *env, void *body);
t_body						*ft_default_bot_setup(t_doom_env *env, t_sector *sector, t_vec3 pos);
int							ft_default_bot_iter(void *env, void *body);
int							ft_create_player_sprite(t_player *player);
int							ft_fill_player_sprite_textures(t_graphical_scene *scene, t_player *player,
	int texture_index, int texture_count);
void						ft_controller_construct(t_doom_env *env,
							int f(void *, void *), t_body *b);
int							ft_on_animation_end(t_animation animation,
	uint64_t expiration);
t_body	*ft_collectible_setup(t_doom_env *env, t_sector *sector, t_vec3 pos,
	t_inventory data);
int		ft_collectible_iter(void *e, void *b);

/*
**	SERIALIZATION FUNCTIONS
*/

int							ft_load_map(t_graphical_scene *scene,
	char *filename);

/*
**	GAME LOOP FUNCTION
*/

int							ft_main_loop(void *arg);

/*
**	GAME UI FUNCTIONS
*/

int							ft_menu_loop(void *arg);
int							ft_main_menu_init(t_doom_env *env);
void						ft_catch_button_input(t_menu *menu, t_doom_env *env);
void						ft_button_switch_menu(t_menu_button *button, void *arg);
int						ft_load_settings_menu(t_menu_system *menu_manager,
			t_doom_env *env, t_sdl_image *select_indicator);
int			ft_render_hud(t_doom_env *env);
int			ft_draw_notifications(t_doom_env *env);
int			ft_push_notification(t_menu_system *menu_manager,
	char *content, double duration, int color);

/*
**	ASSET LOADING FUNCTIONS
*/

t_sdl_image	*ft_load_new_image(char *filename);

/*
**	BOT CONSTRUCTORS AND ITER FUNCTIONS
*/

t_body	*ft_projectile_setup(t_doom_env *env, t_sector *sector,
	t_projectile_data data);
int		ft_projectile_iter(void *e, void *b);


#endif
