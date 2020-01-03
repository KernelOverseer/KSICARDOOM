/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olddraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:50:24 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/24 17:28:34 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"
#include "drawing.h"

void		ft_sdl_draw_color(t_sdl_env *env, Uint32 color)
{
	SDL_SetRenderDrawColor(env->renderer, RGB_R(color), RGB_G(color),
			RGB_B(color), RGB_A(color));
}

void		ft_sdl_pixel_put(t_sdl_env *env, int x, int y)
{
	SDL_RenderDrawPoint(env->renderer, x, y);
}

void		ft_sdl_clear_window(t_sdl_env *env, Uint32 color)
{
	ft_sdl_draw_color(env, color);
	SDL_RenderClear(env->renderer);
	SDL_RenderPresent(env->renderer);
}

static void	get_d_s(int s[2], int d[2], t_point *p0, t_point *p1)
{
	d[0] = abs(p1->x - p0->x);
	s[0] = p0->x < p1->x ? 1 : -1;
	d[1] = abs(p1->y - p0->y);
	s[1] = p0->y < p1->y ? 1 : -1;
}

void		ft_sdl_line(t_sdl_env *env, t_point p0, t_point p1, int color)
{
	int	s[2];
	int d[2];
	int err;
	int e2;

	ft_sdl_draw_color(env, color);
	get_d_s(s, d, &p0, &p1);
	err = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		ft_sdl_pixel_put(env, p0.x, p0.y);
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
