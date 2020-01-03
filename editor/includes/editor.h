/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:35:19 by abiri             #+#    #+#             */
/*   Updated: 2019/12/26 15:52:49 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include "centropy.h"
# include "ft_simplesdl.h"
# include "drawing.h"
# include "ttsgui.h"
# include "gui_button.h"
# include "gui_checkbox.h"
# include "gui_slider.h"
# include "gui_label.h"
# include "gui_canvas.h"
# include "gui_texture_selector_addon.h"
# include "gui_texture_display_addon.h"
# include "graphical_objects.h"
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
# define CORRECT_COLOR(c) (0xFF000000 | c)
# define PREVIEW_EDIT 0
# define PREVIEW_RENDER 1
# define EDIT_MODE_ADD 1 
# define EDIT_MODE_EDIT 2
# define EDIT_MODE_DELETE 3 
# define EDIT_SCALE (PROJECTION_DISTANCE / 100)

/*typedef struct	s_game_data
{
	t_list_head	sectors;
	t_list_head points;
	t_sdl_image	*textures;
}				t_game_data;*/

typedef struct	s_editor_event
{
	t_list_head		points;
	int				mouse_down;
	int				edit_mode;
	t_point			*selected;
	int				sector_scroll_offset;
	int				preview_mode;
	double 			scale;
}				t_editor_event;

typedef struct	s_doom_editor
{
	t_sdl_env			*display_env;
	t_sdl_image			*main_image;
	t_sdl_image			*edit_image;
	t_sdl_image 		*render_image;
	t_gui_component		*editor_canvas;
	t_tts_gui			gui;
	t_graphical_scene	data;
	t_editor_event		event;
	SDL_Event			e;
	//t_game_data		data;
}				t_doom_editor;

/*
**	GUI LOADING FUNCTIONS
*/

int			ft_main_interface_loading(t_tts_gui *gui_env, t_doom_editor *env);
t_gui_area	*ft_load_sector_settings_gui(t_doom_editor	*env);

/*
**	EDITOR EVENT FUNCTIONS
*/

int		ft_editor_mouse_event(void *arg, SDL_Event e);
void	ft_add_sector(void *arg, t_gui_component *button);
void	ft_sectors_mouse_wheel(t_tts_gui *gui_env, t_gui_component *component);
int		ft_load_sector_events(t_tts_gui *gui_env, t_doom_editor *env);
void	ft_select_sector(t_tts_gui *gui_env, t_gui_component *component);

/*
**	ELEMENT MANIPULATION FUNCTIONS
*/

int		ft_add_wall(t_doom_editor *env, t_point *p1, t_point *p2);

/*
**	GRAPHICAL OBJECTS CONSTRUCTORS
*/

t_sector	*ft_new_sector(void);
t_wall		*ft_new_wall(void);

/*
**	SETTINGS EDITION FUNCTIONS
*/

void 		ft_reload_sector_settings(t_doom_editor *env);

/*
**	DRAWING FUNCTIONS
*/

void	ft_list_sectors(t_doom_editor *env, t_list_head *sector_list);
void	ft_draw_points(t_doom_editor *env);
void	ft_draw_lines(t_doom_editor	*env);
void	ft_draw_player(t_doom_editor *env);

# endif