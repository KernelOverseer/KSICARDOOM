/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 01:31:48 by abiri             #+#    #+#             */
/*   Updated: 2019/12/17 19:54:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include <mlx.h>
# include "centropy.h"
# include "simplist.h"

typedef struct	s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned int	width;
	unsigned int	height;
	int				*image;
}				t_mlx;

typedef struct	s_editor
{
	t_mlx		mlx;
}				t_editor;
#endif
