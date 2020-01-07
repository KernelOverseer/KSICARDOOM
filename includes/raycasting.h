/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:50:42 by abiri             #+#    #+#             */
/*   Updated: 2020/01/07 21:00:30 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "graphics_structs.h"
# include "graphical_engine.h"
# define SUCCESS 1
# define ERROR 0

void	ft_init_raycasting(t_raycast *raygen, double angle);
void	ft_iter_ray(t_raycast *raygen, int render_max);
void	ft_raycast(t_graphical_scene *scene);
void	ft_intersect_ray(t_graphical_scene *scene, t_intersect *inter,
	t_sector *sector, int screen_x);

#endif
