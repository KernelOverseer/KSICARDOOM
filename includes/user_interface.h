/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:45:27 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 05:35:07 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H
# include "doom_nukem.h"
# define BACKGROUND_IMAGE "./assets/background.tex"
# define SETTINGS_BACKGROUND_IMAGE "./assets/settings_background.tex"
# define MENU_FONT "./assets/font/bankrus.ttf"
# define SELECT_INDICATOR "./assets/select_indicator.tex"
# define SELECT_INDICATOR_OFFSET -50
# define SELECT_INDICATOR_WIDTH 40
# define SELECT_INDICATOR_HEIGHT 80

typedef struct s_menu_button	t_menu_button;

typedef	void t_menu_button_handler(t_menu_button *button,
	void *env);

struct	s_menu_button
{
	t_text			format;
	char			*text;
	TTF_Font		*font;
	t_list_node		*parent_node;
	t_menu_button_handler	*handler;
	void			*arg;
};

typedef struct	s_menu
{
	t_rect			fit_data;
	t_rect			position;
	t_list_head		buttons;
	t_sdl_image		*background;
	t_sdl_image		*select_indicator;
	t_menu_button	*selected_button;
	TTF_Font		*font;
}				t_menu;

typedef struct	s_menu_system
{
	t_list_head	menu_list;
	t_menu		*current;
	TTF_Font	*font;
}				t_menu_system;


/*
**	CONSTRUCTORS AND INIT
*/

int				ft_init_menu_system(t_menu_system *menu_manager, TTF_Font *font);
t_menu			*ft_new_menu(void);
int				ft_add_menu(t_menu_system *menu_manager, t_menu *new_menu);
int				ft_add_button(t_menu *menu, t_menu_button *button);
int				ft_fit_menu_button(t_menu *menu, t_menu_button *button);

/*
**	BUTTON FUNCTIONS
*/

void			ft_draw_menu_buttons(t_menu	*menu, t_sdl_image *image);

/*
**	DRAWING FUNCTIONS
*/

int				ft_draw_menu(t_menu	*menu, t_sdl_image *image);
void			ft_draw_menu_button(t_menu_button *button, t_sdl_image *image,
	t_text format, t_sdl_image *select_indicator);
void			ft_draw_menu_buttons(t_menu	*menu, t_sdl_image *image);
t_menu_button	*ft_new_button(const char *text);
int				ft_draw_menus(t_menu_system *menu_system, t_sdl_image *image);

/*
**	HELPER FUNCTIONS
*/

t_menu_button	*ft_helper_create_menu_button(t_menu *menu, const char *text,
	t_text format, t_menu_button_handler *handler);
#endif
