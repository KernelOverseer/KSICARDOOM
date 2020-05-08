/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 09:03:32 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 00:27:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_button.h"
# define BUTTON_BORDER_SIZE 2
# define BUTTON_BORDER_SCALE 1

void	ft_button_vertical_texture_stretch(t_rect pos, t_sdl_image *texture,
	t_sdl_image *target)
{
	double	scale;
	int		itery;
	int		image_y;
	int		iterx;
	int		texture_x;

	itery = 0;
	scale = ((double)texture->height) / ((double)pos.h);
	while (itery < pos.h)
	{
		iterx = 0;
		while (iterx < (BUTTON_BORDER_SIZE * BUTTON_BORDER_SCALE))
		{
			image_y = itery * scale;
			texture_x = iterx / BUTTON_BORDER_SCALE;
			ft_sdl_set_image_pixel(target, pos.x + iterx, pos.y + itery,
				ft_sdl_get_image_pixel(texture, texture_x, image_y));
			ft_sdl_set_image_pixel(target, pos.x + pos.w + iterx -
				BUTTON_BORDER_SIZE, pos.y + itery,
				ft_sdl_get_image_pixel(texture, texture_x + texture->width -
				BUTTON_BORDER_SIZE, image_y));
			iterx++;
		}
		itery++;
	}
}

void	ft_button_horizontal_texture_stretch(t_rect pos, t_sdl_image *texture,
	t_sdl_image *target)
{
	double	scale;
	int		itery;
	int		texture_y;
	int		iterx;
	int		texture_x;

	iterx = 0;
	scale = ((double)texture->width) / ((double)pos.w);
	while (iterx < pos.w)
	{
		itery = 0;
		while (itery < (BUTTON_BORDER_SIZE * BUTTON_BORDER_SCALE))
		{
			texture_y = itery / BUTTON_BORDER_SCALE;
			texture_x = iterx * scale;
			ft_sdl_set_image_pixel(target, pos.x + iterx, pos.y + itery,
				ft_sdl_get_image_pixel(texture, texture_x, texture_y));
			ft_sdl_set_image_pixel(target, pos.x + iterx , pos.y + itery +
				pos.h - BUTTON_BORDER_SIZE,
				ft_sdl_get_image_pixel(texture, texture_x, texture_y +
				texture->height - BUTTON_BORDER_SIZE));
			itery++;
		}
		iterx++;
	}
}

static void	draw(t_rect pos, t_sdl_image *texture,
	t_sdl_image *target)
{
	if (!texture || !target)
		return ;
	ft_button_vertical_texture_stretch(pos, texture, target);
	ft_button_horizontal_texture_stretch(pos, texture, target);
}

void	ft_gui_button_draw(t_tts_gui *gui_env, t_gui_component *button)
{
	t_gui_button	*button_data;
	t_rect			pos;
	t_sdl_image		*text_image;

	button_data = button->data;
	if (!button_data)
		return ;
	text_image = button_data->text;
	pos = (t_rect){button->x_pos, button->y_pos, button->width, button->height};
	if (button_data->state == STATE_ACTIVE || button_data->always_on)
		draw(pos, &(gui_env->assets[asset_button_active]), gui_env->image);
	else if (gui_env->hovered == button)
		draw(pos, &(gui_env->assets[asset_button_hover]), gui_env->image);
	else
		draw(pos, &(gui_env->assets[asset_button]), gui_env->image);
	pos = (t_rect){button->x_pos + button->width / 2 - text_image->width / 2,
		button->y_pos + button->height / 2 - text_image->height / 2 ,
		text_image->width, text_image->height};
	ft_blit_image(pos, text_image, gui_env->image);
}
