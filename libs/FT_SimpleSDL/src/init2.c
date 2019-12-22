/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:25:53 by azarzor           #+#    #+#             */
/*   Updated: 2019/12/20 09:06:15 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

static void			ft_sdl_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void			ft_sdl_putstr_fd(const char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_sdl_putchar_fd(str[i], fd);
		i++;
	}
}

/*
**	Function that stores error message from ft_SDL functions
**	-	Specify newerror to update the error
**	-	Pass NULL to the function to get the current error
*/

char				*ft_sdl_error(const char *newerror)
{
	static char	*error = NULL;

	if (newerror)
	{
		free(error);
		error = ft_simplesdl_strdup(newerror);
		if (DEBUG)
		{
			ft_sdl_putstr_fd(newerror, 2);
			ft_sdl_putchar_fd('\n', 2);
		}
		return (NULL);
	}
	else
		return (error);
}

/*
**	Allocates a new config struct for ft_SDL_init()
**	-	modify the structure elements to modify window settings
*/

t_sdl_init_config	ft_sdl_new_config(void)
{
	t_sdl_init_config conf;

	conf.window_title = NULL;
	conf.window_posx = SDL_WINDOWPOS_UNDEFINED;
	conf.window_posy = SDL_WINDOWPOS_UNDEFINED;
	conf.screen_width = 800;
	conf.screen_height = 600;
	conf.window_flag = SDL_WINDOW_SHOWN;
	return (conf);
}
