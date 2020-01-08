/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:50:42 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 21:11:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "graphics_structs.h"
# include "graphical_engine.h"
# define SUCCESS 1
# define ERROR 0

/*
**  RAYCASTING FUNCTIONS
*/

void	    ft_init_raycasting(t_raycast *raygen, t_graphical_scene *env);
void	    ft_iter_ray(t_raycast *raygen, t_graphical_scene *env);
void        ft_raycast(t_graphical_scene *scene);
t_intersect ft_init_intersect(t_sector *sector, t_raycast *raycast, int screen_x);

/*
**  INTERSECTION FUNCTIONS
*/

#endif
