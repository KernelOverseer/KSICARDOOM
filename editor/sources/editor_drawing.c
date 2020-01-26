/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:53:45 by abiri             #+#    #+#             */
/*   Updated: 2020/01/06 16:17:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	ft_draw_mouse_pointer(t_sdl_image *image, int x, int y, int status)
{
	int			i;
	uint32_t	color;

	color = UI_COLOR_WHITE;
	if (status == EDIT_MODE_LINK_WALL || status == EDIT_MODE_LINK_PORTAL)
		color = UI_COLOR_GREEN;
	else if (status == EDIT_MODE_EDIT)
		color = UI_COLOR_RED;
	i = -10;
	while (i < 11)
	{
		ft_sdl_image_pixel(image, x, y + i, CORRECT_COLOR(color));
		ft_sdl_image_pixel(image, x + i, y, CORRECT_COLOR(color));
		i++;
	}
}

/*
**	now we will add a new component that will handle the events
**		like scrolling the list and selecting a sector
*/

int		ft_load_sector_events(t_tts_gui *gui_env, t_doom_editor *env)
{
	t_gui_component	*mouse_area;
	t_gui_area		*area;

	ft_list_sectors(env, &(env->data.sectors));
	if (!(area = ft_get_area_by_id(gui_env, "sector_select_area")))
		return (0);
	if (!(mouse_area = ft_memalloc(sizeof(t_gui_component))))
		return (0);
	mouse_area->x_pos = area->x_pos;
	mouse_area->y_pos = area->y_pos;
	mouse_area->width = area->width;
	mouse_area->height = area->height;
	ACTIVATE_PROP(mouse_area->props, GUI_ACTIVE);
	mouse_area->data = env;
	mouse_area->event.on_mouse_wheel = &ft_sectors_mouse_wheel;
	mouse_area->event.on_click = &ft_select_sector;
	if (ft_gui_add_component(area, mouse_area, "sector_select_mouse_component"))
		return (1);
	return (0);
}

static	void	ft_draw_wall(t_doom_editor *env, t_wall *wall, int color)
{
    if (wall == env->event.selected)
        color = CORRECT_COLOR(UI_COLOR_RED);
	ft_sdl_image_line(env->edit_image,
		ft_map_to_screen((t_point){wall->p1.x, wall->p1.y}, env->event.scale,
		        env->event.offset),
		ft_map_to_screen((t_point){wall->p2.x, wall->p2.y}, env->event.scale,
		        env->event.offset),
		color);
}

void	ft_draw_lines(t_doom_editor	*env)
{
	t_sector	*sector;
	t_wall		*wall;
	t_portal	*portal;
	int			color;

	env->data.sectors.iterator = env->data.sectors.first;
	while ((sector = ttslist_iter_content(&(env->data.sectors))))
	{
		sector->walls.iterator = sector->walls.first;
		sector->portals.iterator = sector->portals.first;
		color = INACTIVE_WALL_COLOR;
		if (sector == env->data.current_sector)
			color = ACTIVE_WALL_COLOR;
		while ((wall = ttslist_iter_content(&(sector->walls))))
	    	ft_draw_wall(env, wall, CORRECT_COLOR(color));
		color = INACTIVE_PORTAL_COLOR;
		if (sector == env->data.current_sector)
			color = ACTIVE_PORTAL_COLOR;
		while ((portal = ttslist_iter_content(&(sector->portals))))
			ft_draw_wall(env, &portal->wall, CORRECT_COLOR(color));
	}
}

void	ft_draw_points(t_doom_editor *env)
{
	t_point	*point;
	t_point position;

	ft_bzero(env->edit_image->pixels, env->edit_image->width *
	env->edit_image->height * sizeof(uint32_t));
	env->event.points.iterator = env->event.points.first;
    while ((point = ttslist_iter_content(&(env->event.points))))
	{
        position = ft_map_to_screen(*point, env->event.scale,
                env->event.offset);
		if (env->event.selected == point)
			ft_sdl_image_disc(env->edit_image, position, 5, CORRECT_COLOR
			(UI_COLOR_RED));
		else
			ft_sdl_image_disc(env->edit_image, position, 5, CORRECT_COLOR
			(UI_COLOR_GREEN));
	}
	ft_draw_mouse_pointer(env->edit_image,
			env->e.button.x - env->editor_canvas->x_pos,
			env->e.button.y - env->editor_canvas->y_pos,
			env->event.edit_mode);
}
