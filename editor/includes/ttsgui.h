/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttsgui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:53:25 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 18:23:45 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTSGUI_H
# define TTSGUI_H
# include "centropy.h"
# include "ft_simplesdl.h"
# include "ttslist.h"
# include "ttsgui_assets.h"
# include "drawing.h"
# define STATE_INACTIVE 0
# define STATE_HOVERED 1
# define STATE_ACTIVE 2
# define GUI_ACTIVE 1
# define GUI_NEVER_FOCUS 2
# define FONT_SIZE 19
# define FONT_FILE "./assets/fonts/RobotoCondensed-Regular.ttf"
# define GET_PROP(x, p) ((x) & p)
# define ACTIVATE_PROP(x, p) x |= p
# define DISACTIVATE_PROP(x, p) x &= ~p
# define AREA_FIT_X_MARGIN 5
# define AREA_FIT_Y_MARGIN 30
# define TOGGLE_PROP(x, p) x ^= p

typedef struct	s_gui_component	t_gui_component;

typedef struct	s_tts_gui
{
	t_sdl_env		*display_env;
	t_sdl_image		*image;
	TTF_Font		*font;
	SDL_Event		event;
	t_point			mouse_position;
	t_list_head		gui_areas;
	t_gui_component	*focused;
	t_gui_component	*hovered;
	t_sdl_image		*assets;
	uint32_t		background_color;
}				t_tts_gui;

typedef struct  s_gui_area
{
	char		*id;
	int			x_pos;
	int			y_pos;
	int			last_elemx;
	int 		last_elemy;
	int 		last_element_height;
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
	char						*id;
	void						*data;
	t_gui_area					*parent;
	t_gui_component_function	*draw;
	t_gui_event_handlers		event;
};

/*
**	LOADING ASSETS AND STUFF
*/

t_sdl_image		*ft_gui_load_assets(void);
int				ft_gui_init(t_tts_gui *env, t_sdl_env *sdl, t_sdl_image *image);

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

t_gui_area		*ft_new_gui_area(t_rect pos, char *id);
t_gui_component	*ft_new_gui_component(t_rect pos);
int				ft_gui_add_component(t_gui_area *parent,
		t_gui_component *child, char *id);
int				ft_gui_fit_component(t_gui_area *parent,
		t_gui_component *child, char *id);

/*
**	COMPONENT DRAWING FUNCTIONS
*/

void	ft_draw_dumb_component(t_tts_gui *gui_env, t_gui_component *component);
void	ft_draw_rect(t_sdl_image *image, t_rect rect, uint32_t color);

/*
**	SEARCHING FUNCTIONS
*/

t_gui_component	*ft_get_component_by_id(t_tts_gui *gui_env, char *id);
t_gui_area		*ft_get_area_by_id(t_tts_gui *gui_env, char *id);

/*
**	PLAIN OLD DEBUG FUNCTIONS
*/
void	ft_load_debug_gui(t_tts_gui *gui_env);

/*
**	OTHER TOOLS NEEDED BY THE GUI
*/

int			ft_is_mouse_in(t_rect rect, int x, int y);
int			ft_is_mouse_in_component(t_gui_component *component, int x, int y);
int			ft_is_mouse_in_area(t_gui_area *area, int x, int y);
void		ft_blit_image(t_rect rect, t_sdl_image *texture,
		t_sdl_image *main_image);
t_sdl_image	*ft_get_text_image(char *text, t_rect rect, uint32_t color,
		TTF_Font *font);
int			ft_int_max(int a, int b);

#endif
