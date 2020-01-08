/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_area_constructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:23:01 by abiri             #+#    #+#             */
/*   Updated: 2020/01/09 00:11:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "ttsgui.h"
#include "ttsgui_assets.h"

static int	ft_int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_gui_area	*ft_new_gui_area(t_rect pos, char *id)
{
	t_gui_area	*result;

	if (!(result = ft_memalloc(sizeof(t_gui_area))))
		return (NULL);
	result->x_pos = pos.x;
	result->y_pos = pos.y;
	result->width = pos.w;
	result->height = pos.h;
	result->id = ft_strdup(id);
	result->last_elemx = pos.x;
	result->last_elemy = pos.y;
	ttslist_init(&(result->children));
	ACTIVATE_PROP(result->props, GUI_ACTIVE);
	return (result);
}

t_gui_component	*ft_new_gui_component(t_rect pos)
{
	t_gui_component	*result;

	if (!(result = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	result->x_pos = pos.x;
	result->y_pos = pos.y;
	result->width = pos.w;
	result->height = pos.h;
	ACTIVATE_PROP(result->props, GUI_ACTIVE);
	return (result);
}

int				ft_gui_add_component(t_gui_area *parent, t_gui_component *child, char *id)
{
	if (!child || !parent)
		return (0);
	if (id)
		child->id = ft_strdup(id);
	child->parent = parent;
	parent->children.push(&(parent->children), child);
	return (1);
}

int				ft_gui_fit_component(t_gui_area *parent, t_gui_component *child, char *id)
{
	if (!child || !parent)
		return (0);
	if (parent->last_elemx + child->width < parent->x_pos + parent->width)
	{
		child->x_pos = parent->last_elemx;
		child->y_pos = parent->last_elemy;
		parent->last_elemx += AREA_FIT_X_MARGIN + child->width;
		parent->last_element_height = ft_int_max(parent->last_element_height,
				child->height);
	}
	else
	{
		child->x_pos = parent->x_pos;
		child->y_pos = parent->last_elemy + parent->last_element_height +
				AREA_FIT_Y_MARGIN;
		parent->last_elemy = child->y_pos;
		parent->last_elemx = child->x_pos + child->width + AREA_FIT_X_MARGIN;
		parent->last_element_height = child->height;
	}
	ft_gui_add_component(parent, child, id);
	return (1);
}
