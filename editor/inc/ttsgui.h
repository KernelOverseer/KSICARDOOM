/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttsgui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:53:25 by abiri             #+#    #+#             */
/*   Updated: 2019/12/22 14:41:20 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTSGUI_H
# define TTSGUI_H
# include "centropy.h"
# include "ft_simplesdl.h"
# include "ttslist.h"
# define STATE_INACTIVE 0
# define STATE_HOVERED 1
# define STATE_ACTIVE 2
# define GUI_ACTIVE 1
# define GET_PROP(x, p) ((x) & p)
# define ACTIVATE_PROP(x, p) x |= p
# define DISACTIVATE_PROP(x, p) x &= ~p
# define TOGGLE_PROP(x, p) x ^= p

typedef struct	s_gui_component	t_gui_component;

typedef struct	s_tts_gui
{
	t_sdl_image		*image;
	SDL_Event		event;
	t_list_head		gui_areas;
	t_gui_component	*focused;
	t_gui_component	*hovered;
	uint32_t		background_color;
}				t_tts_gui;

typedef struct	s_rect
{
	int 		x;
	int 		y;
	int 		width;
	int 		height;
}				t_rect;

typedef struct  s_gui_area
{
	int			x_pos;
	int			y_pos;
	uint32_t	width;
	uint32_t	height;
	uint32_t	props;
	t_list_head	children;
	uint32_t	background_color;
}               t_gui_area;

typedef void	t_gui_component_function(t_tts_gui *gui_env, t_gui_component *component);

typedef struct	s_gui_event_handlers
{
	t_gui_component_function	*on_click;
	t_gui_component_function	*on_release;
	t_gui_component_function	*on_focus;
	t_gui_component_function	*on_lose_focus;
	t_gui_component_function	*on_hover;
	t_gui_component_function	*on_mouse_wheel;
	t_gui_component_function	*on_key_press;
	SDL_Event					e;
}				t_gui_event_handlers;

struct			s_gui_component
{
	int							x_pos;
	int							y_pos;
	uint32_t					width;
	uint32_t					height;
	uint32_t					props;
	void						*data;
	t_gui_area					*parent;
	t_gui_component_function	*draw;
	t_gui_event_handlers		event;
};

/*
**	GENERAL GUI EVENTS FUNCTIONS
*/

void	ft_draw_gui_areas(t_tts_gui	*gui_env);
int		ft_gui_mouse_event(void *arg, SDL_Event e);
void	ft_apply_component_handler(t_tts_gui *gui_env,
		t_gui_component *component, t_gui_component_function *handler,
		SDL_Event e);

/*
**	CONSTRUCTOR FUNCTIONS
*/

t_gui_area	*ft_new_gui_area(int x_pos, int y_pos, int width, int height);
t_gui_component	*ft_new_gui_component(t_gui_area *parent, int x, int y,
		int width, int height, t_gui_component_function *handle);

/*
**	COMPONENT DRAWING FUNCTIONS
*/

void	ft_draw_dumb_component(t_tts_gui *gui_env, t_gui_component *component);
void	ft_draw_rect(t_sdl_image *image, t_rect rect, uint32_t color);

/*
**	PLAIN OLD DEBUG FUNCTIONS
*/
void	ft_load_debug_gui(t_tts_gui *gui_env);

/*
**	OTHER TOOLS NEEDED BY THE GUI
*/

int		ft_is_mouse_in(t_rect rect, int x, int y);
int		ft_is_mouse_in_component(t_gui_component *component, int x, int y);
int		ft_is_mouse_in_area(t_gui_area *area, int x, int y);

#endif
