/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_list_draw.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 08:29:52 by abiri             #+#    #+#             */
/*   Updated: 2019/12/25 22:13:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void ft_clear_sector_labels(t_gui_area   *area)
{
    t_list_node     *node;
    t_gui_component *label;

    area->children.iterator = area->children.first;
    while ((node = ttslist_iter(&(area->children))))
    {
        label = node->content;
        if (label->draw != ft_gui_label_draw)
            continue ;
        label = ttslist_splice(&(area->children), node);
        if (label->data)
            free(((t_sdl_image *)label->data)->pixels);
        free(label->id);
        free(label->data);
    }
}

static char *ft_format_sector_name(t_sector *sector, int selected)
{
    char    *name;
    char    *number;
    int     count;

    count = 12;
    if (selected)
        count += 6;
    number = ft_itoa(sector->id);
    if (!number)
        return (NULL);
    count += ft_strlen(number);
    if (!(name = ft_memalloc(count + 1)))
    {
        free(number);
        return (NULL);
    }
    if (selected)
    {
        ft_strcpy(name, "  -> SECTOR ");
        ft_strcpy(name + 12, number);
        ft_strcpy(name + 12 + ft_strlen(number), " <-  ");
    }
    else
    {
        ft_strcpy(name, "  SECTOR ");
        ft_strcpy(name + 9, number);
        ft_strcpy(name + 9 + ft_strlen(number), "  ");
    }
    free(number);
    return (name);
}

static int  ft_add_sector_label(t_doom_editor *env, t_gui_area *area,
    t_sector *sector, int y)
{
    t_gui_component *sector_label;
    t_rect          rect;
    char            *text;

    rect = (t_rect){area->x_pos, y, area->width, SECTOR_LABEL_HEIGHT};
    if ((unsigned)(rect.y + rect.h) > (unsigned)(area->y_pos + area->height))
        return (0);
    text = ft_format_sector_name(sector, sector == env->data.current_sector);
    if (!text)
        return (0);
    sector_label = ft_gui_new_label(rect, text, UI_COLOR_BLACK, &(env->gui));
    ft_gui_add_component(area, sector_label, text);
    return (1);
}

void	ft_list_sectors(t_doom_editor *env, t_list_head *sector_list)
{
	t_gui_area  *area;
    t_sector    *sector;
    int         y;
    int         offset;

	area = ft_get_area_by_id(&(env->gui), "sector_select_area");
	if (!area)
		return ;
    y = area->y_pos;
    offset = env->event.sector_scroll_offset;
    ft_clear_sector_labels(area);
    sector_list->iterator = sector_list->first;
    while ((sector = ttslist_iter_content(sector_list)))
    {
        if (offset > 0)
        {
            offset--;
            continue ;
        }
        if (!ft_add_sector_label(env, area, sector, y))
          break ;
        y += SECTOR_LABEL_HEIGHT;
    }
}