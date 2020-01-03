/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:06:37 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 17:44:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H
# include "ft_simplesdl.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_rect
{
	int x;
	int y;
	int	w;
	int	h;
}				t_rect;

void			ft_sdl_image_line(t_sdl_image *image,
		t_point p0, t_point p1, int color);
void		ft_sdl_image_disc(t_sdl_image *img, t_point co, int radius, Uint32 col);
void		ft_sdl_image_rect(t_sdl_image *img, t_rect rect, Uint32 c);
void			ft_sdl_line(t_sdl_env *env, t_point p0, t_point p1, int color);
void			ft_sdl_pixel_put(t_sdl_env *env, int x, int y);
void			ft_sdl_draw_color(t_sdl_env *env, Uint32 color);
void			ft_sdl_clear_window(t_sdl_env *env, Uint32 color);
void			ft_sdl_render(t_sdl_env *env);
#endif
