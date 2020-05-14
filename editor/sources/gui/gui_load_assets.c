/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_load_assets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:45:47 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 13:46:44 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "ttsgui_assets.h"

char *g_gui_assets_list[] =
{
	ASSETS_DIRECTORY"/Button/entry-button-active.tex",
	ASSETS_DIRECTORY"/Button/entry-button-hover.tex",
	ASSETS_DIRECTORY"/Button/entry-button-hover2.tex",
	ASSETS_DIRECTORY"/Button/entry-button-insensitive.tex",
	ASSETS_DIRECTORY"/Button/entry-button.tex",
	ASSETS_DIRECTORY"/Check-Radio/checkbox-checked-insensitive.tex",
	ASSETS_DIRECTORY"/Check-Radio/checkbox-checked.tex",
	ASSETS_DIRECTORY"/Check-Radio/checkbox-mixed-insensitive.tex",
	ASSETS_DIRECTORY"/Check-Radio/checkbox-mixed.tex",
	ASSETS_DIRECTORY"/Check-Radio/checkbox-unchecked-insensitive.tex",
	ASSETS_DIRECTORY"/Check-Radio/checkbox-unchecked.tex",
	ASSETS_DIRECTORY"/Check-Radio/radio-checked-insensitive.tex",
	ASSETS_DIRECTORY"/Check-Radio/radio-checked.tex",
	ASSETS_DIRECTORY"/Check-Radio/radio-mixed-insensitive.tex",
	ASSETS_DIRECTORY"/Check-Radio/radio-mixed.tex",
	ASSETS_DIRECTORY"/Check-Radio/radio-unchecked-insensitive.tex",
	ASSETS_DIRECTORY"/Check-Radio/radio-unchecked.tex",
	ASSETS_DIRECTORY"/Range/slider-horiz.tex",
	ASSETS_DIRECTORY"/Range/slider-vert.tex",
	ASSETS_DIRECTORY"/Range/trough-horiz.tex",
	ASSETS_DIRECTORY"/Range/trough-vert.tex",
	ASSETS_DIRECTORY"/Scrollbars/slider.tex",
	ASSETS_DIRECTORY"/textures/render_placeholder.tex",
	ASSETS_DIRECTORY"/textures/-42.png.tex",
	ASSETS_DIRECTORY"/textures/ammo.tex",
	ASSETS_DIRECTORY"/textures/banner.tex",
	ASSETS_DIRECTORY"/textures/cannonball.tex",
	ASSETS_DIRECTORY"/textures/cell.tex",
	ASSETS_DIRECTORY"/textures/download.jpg.tex",
	ASSETS_DIRECTORY"/textures/wood-door.tex",
	ASSETS_DIRECTORY"/textures/fence.tex",
	ASSETS_DIRECTORY"/textures/floor.tex",
	ASSETS_DIRECTORY"/textures/ironwall.tex",
	ASSETS_DIRECTORY"/textures/lava.tex",
	ASSETS_DIRECTORY"/textures/left_newsoul.png.tex",
	ASSETS_DIRECTORY"/textures/neon.tex",
	ASSETS_DIRECTORY"/textures/newsoul.png.tex",
	ASSETS_DIRECTORY"/textures/pigcop.tex",
	ASSETS_DIRECTORY"/textures/rasbiri.tex",
	ASSETS_DIRECTORY"/textures/right_newsoul.png.tex",
	ASSETS_DIRECTORY"/textures/skull.tex",
	ASSETS_DIRECTORY"/textures/stonewall.tex",
	ASSETS_DIRECTORY"/textures/t1.tex",
	ASSETS_DIRECTORY"/textures/t2.tex",
	ASSETS_DIRECTORY"/textures/tekwall.tex"
};

t_sdl_image	*ft_gui_load_assets(void)
{
	uint32_t	index;
	t_sdl_image	*result;

	index = 0;
	if (!(result = ft_memalloc(sizeof(t_sdl_image) * GUI_ASSET_COUNT)))
		return (NULL);
	while (index < GUI_ASSET_COUNT)
	{
		if (!(ft_sdl_load_image((char *)g_gui_assets_list[index],
						&result[index])))
		{
			ft_putstr_fd("ERROR loading texture : ", 2);
			ft_putstr_fd(g_gui_assets_list[index], 2);
			ft_putchar_fd('\n', 2);
			return (NULL);
		}
		index++;
	}
	return (result);
}
