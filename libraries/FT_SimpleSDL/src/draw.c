/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:46:39 by abiri             #+#    #+#             */
/*   Updated: 2019/07/27 15:49:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"
#include "drawing.h"

static void		get_d_s(int s[2], int d[2], t_point *p0, t_point *p1)
{
	d[0] = abs(p1->x - p0->x);
	s[0] = p0->x < p1->x ? 1 : -1;
	d[1] = abs(p1->y - p0->y);
	s[1] = p0->y < p1->y ? 1 : -1;
}

void			ft_sdl_render(t_sdl_env *env)
{
	SDL_RenderPresent(env->renderer);
}

/*
 **	This function draws a line in the given image
 */

void			ft_sdl_image_line(t_sdl_image *image, t_point p0,
		t_point p1, int color)
{
	int	s[2];
	int d[2];
	int err;
	int e2;

	get_d_s(s, d, &p0, &p1);
	err = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		ft_sdl_image_pixel(image, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e2 = err;
		if (e2 > -d[0])
		{
			err -= d[1];
			p0.x += s[0];
		}
		if (e2 < d[1])
		{
			err += d[0];
			p0.y += s[1];
		}
	}
}
/*
 * This function draws, a disc of center co, radius r
 *
 */

void		ft_sdl_image_disc(t_sdl_image *img, t_point co, int radius, Uint32 col)
{
	int		d;
	int		x;
	int		y;

	y = radius;
	d = 3 - (radius << 1);
	x = -1;
	while (y >= ++x)
	{
		ft_sdl_image_line(img, (t_point){co.x - x, co.y - y}, (t_point){co.x + 1
					+ x, co.y - y}, col);
		ft_sdl_image_line(img, (t_point){co.x - x, co.y + y}, (t_point){co.x
					+ 1 + x, co.y + y}, col);
		ft_sdl_image_line(img, (t_point){co.x - y, co.y - x}, (t_point){co.x + 1
					+ y, co.y - x}, col);
		ft_sdl_image_line(img, (t_point){co.x - y, co.y + x}, (t_point){co.x + 1
					+ y, co.y + x}, col);
		if (d < 0)
			d = d + (x << 2) + 6;
		else
		{
			d = d + ((x - y) << 2) + 10;
			--y;
		}
	}
}
/*
 * This function draws a rectangle 
 * */
void		ft_sdl_image_rect(t_sdl_image *img, t_rect rect, Uint32 c)
{
	int		i;
	int		j;

	i = rect.y - 1;
	while (++i < rect.y + rect.h)
	{
		j = rect.x - 1;
		while (++j < rect.x + rect.w)
			ft_sdl_image_pixel(img, j, i, c);
	}
}
