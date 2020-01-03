/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 02:04:55 by abiri             #+#    #+#             */
/*   Updated: 2019/06/10 14:22:49 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"
#include "drawing.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdio.h>

typedef	struct	s_game
{
	t_point pos;
	t_SDL_env *env;
	t_SDL_image *image;
}				t_game;

int		ft_SDL_text(const char *font_name, int font_size, int x, int y, const char *text, t_SDL_env *env)
{
	int texW;
	int texH;

	TTF_Init();
	TTF_Font *font = TTF_OpenFont(font_name, font_size);
	printf("Font is : %p\n", font);
	SDL_Color color = {255, 255, 255};
	SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
	printf("Surface is : %p\n", surface);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(env->renderer, surface);
	printf("Texture is : %p\n", texture);
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {x, y, texW, texH};
	SDL_RenderCopy(env->renderer, texture, NULL, &dstrect);
	SDL_RenderPresent(env->renderer);
	TTF_CloseFont(font);
	TTF_Quit();
	return (0);
}

int	key_press_handler(void	*arg, SDL_Event e)
{
	t_game *env;

	env = arg;
	switch (KEY(e))
	{
		case SDLK_UP:
			env->pos.y -= 5;
			break;
		case SDLK_DOWN:
			env->pos.y += 5;
			break;
		case SDLK_LEFT:
			env->pos.x -= 5;
			break;
		case SDLK_RIGHT:
			env->pos.x += 5;
			break;
	}

	ft_SDL_clear_image(env->image, 0x0);
	ft_SDL_image_pixel(env->image, env->pos.x, env->pos.y, 0xffffff);
	ft_SDL_image_line(env->image, (t_point){0,0}, (t_point){200,200}, 0xffffff);
	ft_SDL_put_image(env->image, env->env);
	ft_SDL_render_texture(env->env);
	ft_SDL_text("arial.ttf", 25, env->pos.x, env->pos.y, "Hello", env->env);
//	ft_SDL_line(env->env, (t_point){0,0}, env->pos, 0xffffff);
//	ft_SDL_render(env->env);
//	ft_SDL_clear_window(env->env, 0x0);
	return (1);
}

int main(void)
{
	t_SDL_env *env;
	t_SDL_init_config *conf;
	t_SDL_image *image;
	t_game game;

	conf = ft_SDL_new_config();
	env = ft_SDL_init(conf);
	image = newimage(conf->screen_width, conf->screen_height);
	game.pos.x = 100;
	game.pos.y = 100;
	game.env = env;
	game.image = image;
	ft_SDL_clear_window(env, 0x0);
	if (!env)
		printf("%s\n", ft_SDL_error(NULL));
	ft_SDL_hook(&key_press_handler, &game, SDL_KEYDOWN);
	ft_SDL_loop(env);
	return (0);
}
