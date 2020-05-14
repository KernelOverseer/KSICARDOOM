/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mouse_events.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: abiri <abiri@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/12/24 14:04:39 by abiri			 #+#	#+#			 */
/*   Updated: 2020/01/06 17:00:01 by abiri			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "editor.h"

int		ft_point_in_radius(t_point p1, t_point p2, int radius)
{
	double dist;

	dist = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	if (dist < (radius * radius))
		return (1);
	return (0);
}

void	ft_select_sector(t_tts_gui *gui_env, t_gui_component *component)
{
	t_doom_editor	*env;
	int				index;
	t_sector		*new_sector;

	(void)gui_env;
	env = component->data;
	index = (env->e.button.y - component->y_pos) / SECTOR_LABEL_HEIGHT +
		env->event.sector_scroll_offset;
	new_sector = ttslist_get_id_content(&(env->data.sectors), index);
	if (new_sector)
		env->data.current_sector = new_sector;
	ft_list_sectors(env, &(env->data.sectors));
	ft_reload_sector_settings(env);
}

void	ft_sectors_mouse_wheel(t_tts_gui *gui_env, t_gui_component *component)
{
	t_doom_editor *env;

	(void)gui_env;
	env = component->data;
	if (component->event.e.wheel.y > 0 &&
	env->event.sector_scroll_offset < (((int)env->data.sectors.size) -
		((int)component->parent->height / SECTOR_LABEL_HEIGHT)))
		env->event.sector_scroll_offset++;
	else if(component->event.e.wheel.y < 0 &&
		env->event.sector_scroll_offset > 0)
		env->event.sector_scroll_offset--;
	else
		return ;
	ft_list_sectors(env, &(env->data.sectors));
}

int	ft_add_point(t_doom_editor *env, int x, int y)
{
	t_point	*new_point;

	if (!(new_point = malloc(sizeof(t_point))))
		return (0);
	new_point->x = (x - env->editor_canvas->x_pos);
	new_point->y = (y - env->editor_canvas->y_pos);
	*new_point = ft_screen_to_map(*new_point, env->event.scale,
			env->event.offset);
	env->event.points.push(&(env->event.points), new_point);
	return (1);
}

int	ft_add_sprite(t_doom_editor	*env, int x, int y)
{
	t_sprite	*new_sprite;
	t_point		new_point;

	if (!(new_sprite = ft_memalloc(sizeof(t_sprite))))
		return(0);
	new_point.x = (x - env->editor_canvas->x_pos);
	new_point.y = (y - env->editor_canvas->y_pos);
	new_point = ft_screen_to_map(new_point, env->event.scale,
			env->event.offset);
	new_sprite->position.x = new_point.x;
	new_sprite->position.y = new_point.y;
	new_sprite->animation.textures = ft_memalloc(sizeof(t_sdl_image *));
	new_sprite->animation.speed = 1;
	new_sprite->animation.frame_count = 1;
	new_sprite->animation.type = ANIMATION_TYPE_TIME;
	ttslist_push_new(&env->data.current_sector->sprites, new_sprite);
	return (1);
}

t_point	*ft_select_point(t_doom_editor *env, int x, int y)
{
	t_point	*point;

	env->event.points.iterator = env->event.points.first;
	while ((point = ttslist_iter_content(&(env->event.points))))
	{
		if (ft_point_in_radius(*point, ft_screen_to_map((t_point){x -
		env->editor_canvas->x_pos, y - env->editor_canvas->y_pos},
				env->event.scale, env->event.offset),
						SELECT_DISTANCE * env->event.scale))
			return (point);
	}
	return (NULL);
}

static	void	ft_editor_mouse_zoom(t_doom_editor *env, SDL_Event e)
{
	double add;

	if (env->gui.hovered != env->editor_canvas)
		return ;
	add = ((double)e.wheel.y / 10) * env->event.scale;
	env->event.scale += add;
	if (env->event.scale < 1)
		env->event.scale = 1;
}

static void		ft_editor_mouse_offset(t_doom_editor *env, SDL_Event e)
{
	if (!(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)))
		return ;
	env->event.offset.x += e.motion.xrel;
	env->event.offset.y += e.motion.yrel;
}

int	ft_editor_mouse_event(void *arg, SDL_Event e)
{
	t_doom_editor	*env;

	env = arg;
	env->e = e;
	if (env->gui.focused != env->editor_canvas ||
		env->event.preview_mode != PREVIEW_EDIT)
		return (1);
	if (e.type == SDL_MOUSEWHEEL)
		ft_editor_mouse_zoom(env, e);
	else if (e.type == SDL_MOUSEMOTION)
		ft_editor_mouse_offset(env, e);
	else if (e.type == SDL_MOUSEBUTTONDOWN &&
		e.button.button == SDL_BUTTON_LEFT)
	{
		if (env->event.edit_mode == EDIT_MODE_ADD)
		{
			env->event.selected = NULL;
			ft_add_point(env, e.button.x, e.button.y);
		}
		else if (env->event.edit_mode == EDIT_MODE_LINK_WALL)
		{
			if (env->event.selected && env->event.selected_type == SELECTED_POINT)
				ft_add_wall(env, env->event.selected,
					ft_select_point(env, e.button.x, e.button.y));
			else
			{
				env->event.selected =
					ft_select_point(env, e.button.x, e.button.y);
				env->event.selected_type = SELECTED_POINT;
			}
		}
		else if (env->event.edit_mode == EDIT_MODE_LINK_PORTAL)
		{
			if (env->event.selected && env->event.selected_type == SELECTED_POINT)
				ft_add_portal(env, env->event.selected,
					ft_select_point(env, e.button.x, e.button.y));
			else
			{
				env->event.selected =
					ft_select_point(env, e.button.x, e.button.y);
				env->event.selected_type = SELECTED_POINT;
			}
		}
		else if (env->event.edit_mode == EDIT_MODE_SPRITE)
		{
			env->event.selected = NULL;
			ft_add_sprite(env, e.button.x, e.button.y);
		}
		else if (env->event.edit_mode == EDIT_MODE_EDIT)
		{
			if (ft_select_sprite(env, e.button.x -
			env->editor_canvas->x_pos, e.button.y - env->editor_canvas->y_pos))
				;
			else if (ft_select_wall(env, e.button.x -
			env->editor_canvas->x_pos, e.button.y - env->editor_canvas->y_pos))
				;
			else if (ft_select_portal(env, e.button.x -
			env->editor_canvas->x_pos, e.button.y - env->editor_canvas->y_pos))
				;
		}
	}
	return (1);
}
