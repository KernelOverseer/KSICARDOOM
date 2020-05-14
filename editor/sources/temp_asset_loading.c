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
#define GAME_ASSET_COUNT 156

char	*g_game_asset_list[] =
{
	ASSETS_DIRECTORY"/textures/t2.tex",
	ASSETS_DIRECTORY"/textures/wood-door.tex",
	ASSETS_DIRECTORY"/textures/banner.tex",
	ASSETS_DIRECTORY"/textures/warmsky.tex",
	ASSETS_DIRECTORY"/textures/rasbiri.tex",
	ASSETS_DIRECTORY"/textures/download.jpg.tex",
	ASSETS_DIRECTORY"/textures/fence.tex",
	ASSETS_DIRECTORY"/textures/cannonball.tex",
	ASSETS_DIRECTORY"/textures/newsoul.png.tex",
	ASSETS_DIRECTORY"/textures/skull.tex",
	ASSETS_DIRECTORY"/textures/render_placeholder.tex",
	ASSETS_DIRECTORY"/textures/-42.png.tex",
	ASSETS_DIRECTORY"/textures/floor.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_1.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_2.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_3.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_4.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_5.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_6.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_7.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_8.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_9.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_10.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_11.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_12.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_13.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_14.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_15.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_16.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_17.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_18.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_19.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_20.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_21.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_22.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_23.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_24.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_25.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_26.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_27.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_28.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_29.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_30.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_31.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_32.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_33.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_34.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_35.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_36.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_37.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_38.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_39.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_40.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_41.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_42.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_43.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_44.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_45.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_46.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_47.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_48.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_49.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_50.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_51.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_52.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_53.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_54.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_55.tex",
ASSETS_DIRECTORY"/textures/animation/ricardo_56.tex",
	ASSETS_DIRECTORY"/textures/daysky.tex",
	ASSETS_DIRECTORY"/textures/pigcop.tex",
	ASSETS_DIRECTORY"/textures/ammo.tex",
	ASSETS_DIRECTORY"/textures/lava.tex",
	ASSETS_DIRECTORY"/textures/background.tex",
	ASSETS_DIRECTORY"/textures/left_newsoul.png.tex",
	ASSETS_DIRECTORY"/textures/fire_texture/fire_texture1.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture2.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture3.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture4.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture5.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture6.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture7.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture8.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture9.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture10.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture11.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture12.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture13.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture14.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture15.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture16.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture17.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture18.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture19.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture20.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture21.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture22.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture23.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture24.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture25.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture26.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture27.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture28.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture29.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture30.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture31.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture32.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture33.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture34.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture35.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture36.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture37.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture38.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture39.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture40.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture41.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture42.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture43.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture44.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture45.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture46.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture47.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture48.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture49.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture50.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture51.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture52.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture53.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture54.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture55.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture56.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture57.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture58.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture59.tex",
ASSETS_DIRECTORY"/textures/fire_texture/fire_texture60.tex",
	ASSETS_DIRECTORY"/textures/tekwall.tex",
	ASSETS_DIRECTORY"/textures/neon.tex",
	ASSETS_DIRECTORY"/textures/sky.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_1.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_2.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_3.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_4.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_5.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_6.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_7.tex",
	ASSETS_DIRECTORY"/textures/player_animation/doomguy_8.tex",
	ASSETS_DIRECTORY"/textures/nightsky.tex",
	ASSETS_DIRECTORY"/textures/right_newsoul.png.tex",
	ASSETS_DIRECTORY"/textures/ironwall.tex",
	ASSETS_DIRECTORY"/textures/cell.tex",
	ASSETS_DIRECTORY"/textures/stonewall.tex",
	ASSETS_DIRECTORY"/textures/t1.tex",
	ASSETS_DIRECTORY"/Range/trough-horiz.tex",
	ASSETS_DIRECTORY"/Range/slider-horiz.tex",
	ASSETS_DIRECTORY"/Range/slider-vert.tex",
	ASSETS_DIRECTORY"/Range/trough-vert.tex"
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