/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:48:37 by abiri             #+#    #+#             */
/*   Updated: 2019/12/23 18:32:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_checkbox.h"

static int	ft_check_checkbox_status(uint32_t value, uint32_t mask)
{
	return (value & mask);
}

void	ft_gui_checkbox_draw(t_tts_gui *gui_env, t_gui_component *component)
{
	t_gui_checkbox *checkbox;

	checkbox = component->data;
	if (!checkbox || !checkbox->value)
	{
        ft_blit_image((t_rect) {component->x_pos, component->y_pos,
                                component->height, component->height},
                      &gui_env->assets[asset_checkbox_unchecked],
                      gui_env->image);
    }
	else if (ft_check_checkbox_status(*checkbox->value,checkbox->mask))
	{
		if (checkbox->state == STATE_ACTIVE)
			ft_blit_image((t_rect){component->x_pos, component->y_pos,
					component->height, component->height},
				&gui_env->assets[asset_checkbox_checked_insensitive],
				gui_env->image);
		else
			ft_blit_image((t_rect){component->x_pos, component->y_pos,
					component->height, component->height},
				&gui_env->assets[asset_checkbox_checked],
				gui_env->image);
	}
	else
	{
		if (checkbox->state == STATE_ACTIVE)
			ft_blit_image((t_rect){component->x_pos, component->y_pos,
					component->height, component->height},
				&gui_env->assets[asset_checkbox_unchecked_insensitive],
				gui_env->image);
		else
			ft_blit_image((t_rect){component->x_pos, component->y_pos,
					component->height, component->height},
				&gui_env->assets[asset_checkbox_unchecked],
				gui_env->image);
	}
}
