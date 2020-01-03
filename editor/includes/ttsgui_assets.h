/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttsgui_asset.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:47:20 by abiri             #+#    #+#             */
/*   Updated: 2020/01/03 19:50:14 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTSGUI_asset_H
# define TTSGUI_asset_H
# include "ttsgui.h"
# define GUI_ASSET_COUNT 45
# define ASSETS_DIRECTORY "assets"
# define BACKGROUND_COLOR 0xd3d0c7

extern char	*g_gui_assets_list[];

enum	e_gui_asset_index
{
	asset_button_active,
	asset_button_hover,
	asset_button_hover2,
	asset_button_insensitive,
	asset_button,
	asset_checkbox_checked_insensitive,
	asset_checkbox_checked,
	asset_checkbox_mixed_insensitive,
	asset_checkbox_mixed,
	asset_checkbox_unchecked_insensitive,
	asset_checkbox_unchecked,
	asset_radio_checked_insensitive,
	asset_radio_checked,
	asset_radio_mixed_insensitive,
	asset_radio_mixed,
	asset_radio_unchecked_insensitive,
	asset_radio_unchecked,
	asset_slider_horiz,
	asset_slider_vert,
	asset_trough_horiz,
	asset_trough_vert,
	asset_slider,
	asset_render_placeholder
};

#endif
