/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_textures.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:20:59 by abiri             #+#    #+#             */
/*   Updated: 2019/12/17 22:28:06 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_TEXTURES_H
# define ANIMATION_TEXTURES_H

/*
**	This struct is the texture struct
**		- pixels : 1D array of pixels defining the texture
**		- width : the width of the texture
**		- height : the height of the texture
*/

typedef struct	s_texture
{
	uint32_t	*pixels;
	uint32_t	width;
	uint32_t	height;
}				t_texture;

/*
**	The animation struct for animating objects and sprites
**
*/

typedef struct	s_animation
{
	t_texture	**textures;
	double		current_frame;
	double		speed;
	int			frame_count;
	uint32_t	now_time;
	uint32_t	type;
	uint32_t	props;
}				t_animation;

#endif
