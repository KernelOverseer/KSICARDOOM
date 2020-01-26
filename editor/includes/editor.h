/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:35:19 by abiri             #+#    #+#             */
/*   Updated: 2020/01/26 21:10:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include "centropy.h"
# include "ft_simplesdl.h"
# include "drawing.h"
# include "libgl.h"
# include "ttsgui.h"
# include "gui_button.h"
# include "gui_checkbox.h"
# include "gui_slider.h"
# include "gui_label.h"
# include "gui_canvas.h"
# include "gui_texture_selector_addon.h"
# include "gui_texture_display_addon.h"
# include "graphics_structs.h"
# include "graphical_engine.h"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define EDIT_WIDTH 1105
# define EDIT_HEIGHT 998
# define UI_COLOR_WHITE 0xffffff
# define UI_COLOR_BLUE 0x000181
# define UI_COLOR_GREEN 0x028081
# define UI_COLOR_GREY 0xbababa
# define UI_COLOR_RED 0xFF3300
# define UI_COLOR_BLACK 0x0
# define UI_COLOR_DARK_GREY 0x6B6B6B
# define SECTOR_LABEL_HEIGHT 39
# define CORRECT_COLOR(c) (c)
# define PREVIEW_EDIT 0
# define PREVIEW_RENDER 1
# define EDIT_MODE_ADD 1 
# define EDIT_MODE_LINK_WALL 2
# define EDIT_MODE_LINK_PORTAL 3
# define EDIT_MODE_EDIT 4
# define SELECT_DISTANCE 5
# define EDIT_SCALE (PROJECTION_DISTANCE / 100)
# define POS_INF 1.0 / 0.0
# define NEG_INF -1.0 / 0.0
# define CREATE_POINT 1
# define SELECTED_WALL 1
# define SELECTED_PORTAL 2
# define SELECTED_POINT 3
# define ACTIVE_WALL_COLOR 0xFFFFFF
# define INACTIVE_WALL_COLOR 0x686868
# define ACTIVE_PORTAL_COLOR 0x0000FF
# define INACTIVE_PORTAL_COLOR 0x000068
# define ACTIVE_SPRITE_COLOR 0x00FF00
# define INACTIVE_SPRITE_COLOR 0x006800

typedef struct	s_editor_event
{
	t_list_head		points;
	int				mouse_down;
	int				edit_mode;
	void			*selected;
	int				selected_type;
	int				sector_scroll_offset;
	int				preview_mode;
	double 			scale;
	t_point         offset;
}				t_editor_event;

typedef struct	s_doom_editor
{
	t_sdl_env			display_env;
	t_sdl_image			*main_image;
	t_sdl_image			*edit_image;
	t_sdl_image 		*render_image;
	t_gui_component		*editor_canvas;
	t_tts_gui			gui;
	t_graphical_scene	data;
	t_editor_event		event;
	SDL_Event			e;
}				t_doom_editor;

# include "gui_int_label_addon.h"

/*
**	GUI LOADING FUNCTIONS
*/

int			ft_main_interface_loading(t_tts_gui *gui_env, t_doom_editor *env);
t_gui_area	*ft_load_sector_settings_gui(t_doom_editor	*env);
t_gui_area  *ft_load_wall_settings_gui(t_doom_editor *env);
t_gui_area	*ft_load_portal_settings_gui(t_doom_editor *env);

/*
**	EDITOR EVENT FUNCTIONS
*/

int			ft_editor_mouse_event(void *arg, SDL_Event e);
void		ft_add_sector(void *arg, t_gui_component *button);
void		ft_sectors_mouse_wheel	(t_tts_gui *gui_env, t_gui_component *component);
int			ft_load_sector_events(t_tts_gui *gui_env, t_doom_editor *env);
void		ft_select_sector(t_tts_gui *gui_env, t_gui_component *component);
t_wall		*ft_select_wall(t_doom_editor *env, int x, int y);
t_portal	*ft_select_portal(t_doom_editor *env, int x, int y);

/*
**	ELEMENT MANIPULATION FUNCTIONS
*/

int		ft_add_wall(t_doom_editor *env, t_point *p1, t_point *p2);
int		ft_add_portal(t_doom_editor *env, t_point *p1, t_point *p2);

/*
**	GRAPHICAL OBJECTS CONSTRUCTORS
*/

t_sector	*ft_create_new_sector(void);
t_wall		*ft_create_new_wall(void);
t_portal	*ft_create_new_portal(void);

/*
**	SETTINGS EDITION FUNCTIONS
*/

void 		ft_reload_sector_settings(t_doom_editor *env);
void 		ft_reload_wall_settings(t_doom_editor *env);
void 		ft_reload_portal_settings(t_doom_editor *env);

/*
**	DRAWING FUNCTIONS
*/

void	ft_list_sectors(t_doom_editor *env, t_list_head *sector_list);
void	ft_draw_points(t_doom_editor *env);
void	ft_draw_lines(t_doom_editor	*env);
void	ft_draw_player(t_doom_editor *env);

/*
**  COORDINATE CONVERSION FUNCTIONS
*/

t_point ft_screen_to_map(t_point point, double scale, t_point offset);
t_point ft_map_to_screen(t_point point, double scale, t_point offset);

/*
**	HELPING FUNCTIONS
*/

int		ft_disable_area(t_tts_gui *gui_env, char *area_id);
int		ft_enable_area(t_tts_gui *gui_env, char *area_id);
double	ft_segment_distance_sq(t_point player_pos, t_point p1, t_point p2);


# endif
