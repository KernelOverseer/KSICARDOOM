/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_asset_loading.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:27:12 by abiri             #+#    #+#             */
/*   Updated: 2020/05/13 23:40:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#define GAME_ASSET_COUNT 46

char	*g_game_asset_list[] =
{
	ASSETS_DIRECTORY"/random_textures/-42.png.tex",
	ASSETS_DIRECTORY"/random_textures/ammo.tex",
	ASSETS_DIRECTORY"/random_textures/banner.tex",
	ASSETS_DIRECTORY"/random_textures/cannonball.tex",
	ASSETS_DIRECTORY"/random_textures/cell.tex",
	ASSETS_DIRECTORY"/random_textures/download.jpg.tex",
	ASSETS_DIRECTORY"/random_textures/estimable-wood-door-texture-door-wood-texture-seamless-crowdbuild-for-wood-door-texture-l-c4fac1edc863bf2c.jpg.tex",
	ASSETS_DIRECTORY"/random_textures/fence.tex",
	ASSETS_DIRECTORY"/random_textures/floor.tex",
	ASSETS_DIRECTORY"/random_textures/ironwall.tex",
	ASSETS_DIRECTORY"/random_textures/lava.tex",
	ASSETS_DIRECTORY"/random_textures/left_newsoul.png.tex",
	ASSETS_DIRECTORY"/random_textures/neon.tex",
	ASSETS_DIRECTORY"/random_textures/newsoul.png.tex",
	ASSETS_DIRECTORY"/random_textures/pigcop.tex",
	ASSETS_DIRECTORY"/random_textures/rasbiri.tex",
	ASSETS_DIRECTORY"/random_textures/right_newsoul.png.tex",
	ASSETS_DIRECTORY"/random_textures/skull.tex",
	ASSETS_DIRECTORY"/random_textures/stonewall.tex",
	ASSETS_DIRECTORY"/random_textures/t1.tex",
	ASSETS_DIRECTORY"/random_textures/t2.tex",
	ASSETS_DIRECTORY"/random_textures/tekwall.tex",
	ASSETS_DIRECTORY"/render_placeholder.tex",
	ASSETS_DIRECTORY"/random_textures/-42.png.tex",
	ASSETS_DIRECTORY"/random_textures/ammo.tex",
	ASSETS_DIRECTORY"/random_textures/banner.tex",
	ASSETS_DIRECTORY"/random_textures/cannonball.tex",
	ASSETS_DIRECTORY"/random_textures/cell.tex",
	ASSETS_DIRECTORY"/random_textures/download.jpg.tex",
	ASSETS_DIRECTORY"/random_textures/estimable-wood-door-texture-door-wood-texture-seamless-crowdbuild-for-wood-door-texture-l-c4fac1edc863bf2c.jpg.tex",
	ASSETS_DIRECTORY"/random_textures/fence.tex",
	ASSETS_DIRECTORY"/random_textures/floor.tex",
	ASSETS_DIRECTORY"/random_textures/ironwall.tex",
	ASSETS_DIRECTORY"/random_textures/lava.tex",
	ASSETS_DIRECTORY"/random_textures/left_newsoul.png.tex",
	ASSETS_DIRECTORY"/random_textures/neon.tex",
	ASSETS_DIRECTORY"/random_textures/newsoul.png.tex",
	ASSETS_DIRECTORY"/random_textures/pigcop.tex",
	ASSETS_DIRECTORY"/random_textures/rasbiri.tex",
	ASSETS_DIRECTORY"/random_textures/right_newsoul.png.tex",
	ASSETS_DIRECTORY"/random_textures/skull.tex",
	ASSETS_DIRECTORY"/random_textures/stonewall.tex",
	ASSETS_DIRECTORY"/random_textures/t1.tex",
	ASSETS_DIRECTORY"/random_textures/t2.tex",
	ASSETS_DIRECTORY"/random_textures/tekwall.tex",
	ASSETS_DIRECTORY"/render_placeholder.tex",
};

void	ft_load_temp_textures(t_doom_editor *env)
{
	uint32_t	index;
	t_sdl_image	*result;

	index = 0;
	if (!(result = ft_memalloc(sizeof(t_sdl_image) * GUI_ASSET_COUNT)))
		return ;
	while (index < GAME_ASSET_COUNT)
	{
		if (!(ft_sdl_load_image((char *)g_game_asset_list[index],
						&result[index])))
		{
			ft_putstr_fd("ERROR loading texture : ", 2);
			ft_putstr_fd(g_game_asset_list[index], 2);
			ft_putchar_fd('\n', 2);
			return ;
		}
		index++;
	}
	env->data.textures = result;
	env->data.textures_count = GAME_ASSET_COUNT;
}