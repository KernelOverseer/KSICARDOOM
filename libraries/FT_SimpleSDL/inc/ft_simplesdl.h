/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesdl.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 00:15:45 by abiri             #+#    #+#             */
/*   Updated: 2019/12/23 11:59:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLESDL_H
# define FT_SIMPLESDL_H
# include <unistd.h>
# include <SDL.h>
# include <SDL_ttf.h>
# define MAX_IMAGE_SIZE 8294400
# define RGB_B(c) (c & 255)
# define RGB_G(c) ((c >> 8) & 255)
# define RGB_R(c) ((c >> 16) & 255)
# define RGB_A(c) ((c >> 24) & 255)
# define KEY(e) e.key.keysym.sym
# define DEBUG 1

typedef	struct		s_sdl_image
{
	Uint32		*pixels;
	int			width;
	int			height;
}					t_sdl_image;

typedef struct		s_sdl_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	int				width;
	int				height;
}					t_sdl_env;

typedef	struct		s_sdl_init_config
{
	char	*window_title;
	int		window_posx;
	int		window_posy;
	int		screen_width;
	int		screen_height;
	Uint32	window_flag;
}					t_sdl_init_config;

typedef	int			t_sdl_event_function(void *arg, SDL_Event e);
typedef	int			t_sdl_loop_function(void *arg);

typedef	struct		s_sdl_event_handler
{
	t_sdl_event_function	*handler;
	void					*arg;
	Uint32					event_type;
}					t_sdl_event_handler;

typedef	struct		s_linked_list
{
	void					*content;
	struct s_linked_list	*next;
	struct s_linked_list	*prev;
}					t_linked_list;

typedef	struct		s_linked_list_head
{
	t_linked_list	*first;
	t_linked_list	*last;
}					t_linked_list_head;

t_sdl_env			*ft_sdl_init(t_sdl_init_config conf);
t_sdl_init_config	ft_sdl_new_config(void);
void				ft_sdl_free_config(t_sdl_init_config *conf);
t_linked_list		*ft_list_push(t_linked_list_head *head,
		t_linked_list *newnode);
void				ft_list_delete(t_linked_list_head *head,
		t_linked_list *element);
t_linked_list		*ft_list_newnode(void *content);
void				*ft_list_queue_pop(t_linked_list_head *head);
void				ft_list_extract(t_linked_list_head *head,
		t_linked_list *element);
char				*ft_sdl_error(const char *newerror);
t_linked_list_head	*ft_sdl_get_eventlist(void);
int					ft_sdl_apply_handler(t_sdl_event_handler *handler_info,
		SDL_Event e);
int					ft_sdl_hook(t_sdl_event_function *handler, void *arg,
		Uint32 event_type);
int					ft_sdl_apply_event(SDL_Event e);
int					ft_sdl_loop(t_sdl_env *env);
void				ft_sdl_render_texture(t_sdl_env *env);
void				ft_sdl_put_image(t_sdl_image *image, t_sdl_env *env);
void				ft_sdl_image_pixel(t_sdl_image *image, int x,
		int y, Uint32 color);
t_sdl_image			*newimage(int width, int height);
void				ft_sdl_clear_image(t_sdl_image *image, Uint32 color);
int					ft_sdl_loop_hook(t_sdl_loop_function *handler, void *arg);
void				*ft_simplesdl_memalloc(size_t size);
char				*ft_simplesdl_strdup(const char *src);
int					ft_sdl_load_image(char *filename, t_sdl_image *result);

#endif
