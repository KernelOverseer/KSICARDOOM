/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_objects.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:10:54 by abiri             #+#    #+#             */
/*   Updated: 2020/01/07 18:06:07 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICAL_OBJECTS_H
# define GRAPHICAL_OBJECTS_H
# include "graphics_structs.h"

/*
**	CONSTRUCTORS FOR GRAPHICAL OBJECTS
*/

t_wall		*ft_new_wall(t_point p1, t_point p2);
t_sector	*ft_new_sector(void);
t_portal	*ft_new_portal(t_point p1, t_point p2, t_sector *sector);
#endif
