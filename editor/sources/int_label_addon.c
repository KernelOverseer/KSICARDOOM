/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_label_addon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:20:53 by abiri             #+#    #+#             */
/*   Updated: 2020/05/08 04:17:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_int_label_addon.h"

static char *ft_pad_spaces(char *str)
{
    char    *result;
    size_t  size;

    size = ft_strlen(str);
    if (!(result = ft_memalloc(size + 3)))
        return (str);
    result[0] = ' ';
    ft_strcpy(result + 1, str);
    result[size + 1] = ' ';
    result[size + 2] = ' ';
    free(str);
    return (result);
}

void    ft_gui_int_label_scroll(t_tts_gui *env, t_gui_component *field)
{
    t_gui_int_label *data;
    t_list_node     *current_node;

    (void)env;
    current_node = NULL;
    data = field->data;
    if (!(*data->sector))
        *(data->sector) = data->env->data.sectors.first->content;
    else
    {
        data->env->data.sectors.iterator = data->env->data.sectors.first;
        while ((current_node = ttslist_iter(&(data->env->data.sectors))))
        {
            if (current_node->content == *(data->sector))
                break;
        }
        if (current_node)
        {
            if (field->event.e.wheel.y > 0)
            {
                current_node = current_node->next;
                if (!current_node)
                    current_node = data->env->data.sectors.first;
            }
            else
            {
                current_node = current_node->prev;
                if (!current_node)
                    current_node = data->env->data.sectors.last;
            }
            if (current_node)
                *(data->sector) = current_node->content;
        }
    }
}

void ft_gui_draw_int_label(t_tts_gui *gui_env, t_gui_component *component)
{
    char            *text;
    t_gui_int_label *data;
    t_sector        *sector;
    t_rect          rect;

    data = component->data;
    rect = (t_rect){component->x_pos, component->y_pos,
        component->width, component->height};
    ft_sdl_image_rect(gui_env->image, rect, CORRECT_COLOR(UI_COLOR_WHITE));
    if (!data || !data->sector)
        return ;
    sector = *data->sector;
    rect.x += rect.w / 4;
    rect.w /= 2;
    if (data->last_value != sector->id || !data->text_image)
    {
        free(data->text_image);
        if (!(text = ft_itoa(sector->id)))
            return ;
        text = ft_pad_spaces(text);
        data->text_image = ft_get_text_image(text, rect,
            UI_COLOR_BLACK, gui_env->font);
        data->last_value = sector->id;
        free(text);
    }
    if (data->text_image)
        ft_blit_image(rect, data->text_image, gui_env->image);
}

t_gui_component *ft_gui_new_int_label(t_rect rect, t_sector **sector, t_doom_editor *env)
{
    t_gui_component	*component;

	if (!(component = ft_memalloc(sizeof(t_gui_component))))
		return (NULL);
	component->x_pos = rect.x;
	component->y_pos = rect.y;
	component->width = rect.w;
	component->height = rect.h;
	ACTIVATE_PROP(component->props, GUI_ACTIVE);
    if (!(component->data = ft_memalloc(sizeof(t_gui_int_label))))
        return (NULL);
    ((t_gui_int_label *)component->data)->sector = sector;
    ((t_gui_int_label *)component->data)->env = env;
	component->draw = &ft_gui_draw_int_label;
	component->event.on_mouse_wheel = &ft_gui_int_label_scroll;
    return (component);
}