/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 00:20:38 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 17:14:07 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

/*
** Frees the config struct (Automatically after ft_SDL_init())
*/

void				ft_sdl_free_config(t_sdl_init_config *conf)
{
	free(conf->window_title);
	free(conf);
}

/*
**	allocates new env to be filled by ft_SDL_init()
*/

t_sdl_env			*ft_sdl_new_env(void)
{
	t_sdl_env *env;

	env = ft_simplesdl_memalloc(sizeof(t_sdl_env));
	if (!env)
	{
		ft_sdl_error("FT_SDL: Cannot allocate new env");
		return (NULL);
	}
	return (env);
}

/*
**	Takes the config struct and returns a new window
**	-	this function is used inside of ft_SDL_init()
**	-	this function can also be used for getting multiple windows
*/

SDL_Window			*ft_sdl_new_window(t_sdl_init_config conf)
{
	SDL_Window *win;

	win = SDL_CreateWindow(conf.window_title, conf.window_posx,
			conf.window_posy, conf.screen_width, conf.screen_height,
			conf.window_flag);
	if (!win)
	{
		ft_sdl_error("FT_SDL: Cannot create window");
		return (NULL);
	}
	return (win);
}

/*
**	This function allocates the renderer and the texture,
**		returns 0 if an error occurs
*/

static int			alloc_window_and_renderer(t_sdl_env *env,
		t_sdl_init_config conf)
{
	if (!(env->window = ft_sdl_new_window(conf)))
	{
		free(env);
		return (0);
	}
	else if (!(env->renderer = SDL_CreateRenderer(env->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		ft_sdl_error("FT_SDL: Cannot create renderer");
		free(env);
		return (0);
	}
	return (1);
}

/*
**	Can only be called once, returns a truct containing the window,
**		renderer, and texture
*/

t_sdl_env			*ft_sdl_init(t_sdl_init_config conf)
{
	t_sdl_env *env;

	env = ft_sdl_new_env();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_sdl_error("FT_SDL: Cannot initialise SDL");
		return (NULL);
	}
	if (!alloc_window_and_renderer(env, conf))
		return (NULL);
	else if (!(env->texture = SDL_CreateTexture(env->renderer,
					SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC,
					conf.screen_width, conf.screen_height)))
	{
		ft_sdl_error("FT_SDL: Cannot create texture");
		free(env);
		return (NULL);
	}
	env->width = conf.screen_width;
	env->height = conf.screen_height;
	return (env);
}
