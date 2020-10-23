/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:32:35 by msidqi            #+#    #+#             */
/*   Updated: 2020/10/23 19:36:44 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_ENGINE_H
# define PHYSICS_ENGINE_H
// # include "ray_casting.h"
# include "libgl.h"
# include "ft_simplesdl.h"
# include "graphics_structs.h"
#include "ray_calculations.h"
// # include "doom_nukem.h"
# define DEFAULT_BODY_N ((t_body){(t_vec2){0, 0}, (t_vec2){0, 0, 0}, 0, 1, 3, 5, 1, 0.5, 0, true, true})
# define DEFAULT_BODY(pos) (t_body){pos, (t_vec2){0, 0}, (t_vec2){0, 1}, (t_vec2){1, 0}, 0, 1, 3, 5, 1, 0.5, 0, true, true, true, NULL}
# define HEIGHT {4, 0}
# define P_SPEED 200
# define P_RUN_SPEED 1000
# define MASS 10
# define DRAG 2
# define FRICTION 0.8
# define BOUNCE 0
# define JUMP_POWER 5000
# define GLOBAL_GRAVITY -9
# define GLOBAL_GRAVITY_VECTOR (t_vec3) {0, 0, -400}
# define ZERO_VEC3 (t_vec3){0, 0, 0}
# define UP (t_vec3){0, 0, 1}
# define DOWN (t_vec3){0, 0, -1}
# define RIGHT (t_vec3){1, 0, 0}
# define FORW (t_vec3){0, 1, 0}
# define HAS_GRAVITY 1
# define HAS_COLLISION 2
# define IS_CONTROLLED 4
# define ANGLE 0.0672665

typedef enum		e_player_controller_buttons
{
	PLAYER_FORWARD,
	PLAYER_BACKWARDS,
	PLAYER_TURN_LEFT,
	PLAYER_TURN_RIGHT,
	PLAYER_STRAFE_RIGHT,
	PLAYER_STRAFE_LEFT,
	PLAYER_TURN_BACK,
	PLAYER_LOOK_UP,
	PLAYER_LOOK_DOWN,
	PLAYER_JUMP,
	PLAYER_RUN,
	PLAYER_CROUCH,
	EMPTY3,
	EMPTY4,
	EMPTY5,
	EMPTY6,
	EMPTY7,
	EMPTY8,
	EMPTY9,
	EMPTY10,
}					t_e_player_controller_buttons;

typedef struct	s_physics_engine
{
	double			global_gravity;
	t_vec3			gravity_vec; // (t_vec2) {0, 0, -9}
}					t_physics_engine;

typedef struct		s_player
{
	Uint64			id;
	t_vec3			input_velocity;
	Uint8			is_grounded;
	double			jump_power;
	double			height[2];
	unsigned char	input[20];
	t_sprite		*sprite;
	t_sector		*sector;
}					t_player;

typedef struct		s_body
{
	t_vec3			pos;
	t_vec3			velocity;
	t_vec3			force;
	t_vec3			gravity;
	t_vec3			forw;
	t_vec3			right;
	t_vec3			up;
	double			speed;
	double			mass; // the bigger the value the more it can apply force on collision
	double			drag; // the bigger the value the less it is affected by gravity (i.e falls faster when small val)
	double			friction; // the lesser the value the less the velocity decreases after a colission
	double			bounce; // bigger the value the more an object rejects after collision
	double			force_duration;
	Uint8			flags; // HAS_GRAVITY | HAS_COLLISION | IS_CONTROLLED
	t_player		*player;
	void			(*update_velocity)(struct s_body *body, double delta_time);
	void			(*collision)(t_graphical_scene *scene, struct s_body *body, double delta_time);
	void			(*update_position)(struct s_body *body, double delta_time);
	void			(*update_force)(struct s_body *body, double delta_time);
	void			(*update_gravity)(struct s_body *body, t_vec3 gravity, double delta_time);
	void			(*force_add)(struct s_body *body,  t_vec3 force,double force_duration);
	void			(*force_change)(struct s_body *body,  t_vec3 force,double force_duration);
}					t_body;

t_body				ft_default_body(t_vec3 pos);
t_body				*ft_new_bot(t_sector *sector, t_vec3 pos);
t_player			*ft_player_construct(Uint64 id);
t_body				*ft_body_construct(t_vec3 pos, void *player);


void				ft_init_physics(t_physics_engine *phi);
void				ft_new_input_changes(t_body *body);
void				ft_update_velocity(t_body *body, double delta_time);
void				ft_force_add(t_body *body, t_vec3 force, double force_duration);
void				ft_force_change(t_body *body, t_vec3 force, double force_duration);
void				ft_update_gravity(t_body *body, t_vec3 gravity, double delta_time);
void				ft_update_force(t_body *body, double delta_time);
void				ft_body_collision(t_graphical_scene *scene, t_body *body, double delta_time);
void				ft_body_move(t_body *body, double delta_time);
void				ft_body_rotate(t_body *body, double delta_time);


#endif
