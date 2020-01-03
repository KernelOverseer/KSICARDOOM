/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:07:39 by abiri             #+#    #+#             */
/*   Updated: 2019/12/24 17:48:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttsgui.h"
#include "gui_label.h"

t_gui_component	*ft_gui_new_label(t_rect rect, char *text, uint32_t color,
		t_tts_gui *gui_env)
{
	t_gui_component	*component;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
	if (!(component->data = ft_memalloc(sizeof(t_gui_label))))
	{
		free(component);
		return (NULL);
	}
	((t_gui_label*)component->data)->text = ft_get_text_image(text,
		rect, color, gui_env->font);
	component->draw = ft_gui_label_draw;
	return (component);
}
