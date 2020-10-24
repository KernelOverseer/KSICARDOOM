/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bots.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:12:37 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 14:10:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTS_H
# define BOTS_H
# include "doom_nukem.h"

typedef struct	s_projectile_data
{
	t_body		*owner;
	t_vec3		source;
	t_vec3		direction;
	double		distance;
	int			damage;
}				t_projectile_data;

#endif