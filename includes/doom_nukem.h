/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/28 12:59:46 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include "centropy.h"
# include "simplist.h"

# define EXEC_NAME "DOOM_NUKEM"

typedef struct  s_scene
{

}               t_scene;
 
/*
** ERROR HANDLING
*/

int		        ft_perror(char *command, char *arg, int err);

# define N_SCENE 0
# define F_OPEN 1

# define N_SCENE_T ": no passed scene file."
# define F_OPEN_T ": cannot open game map: "

#endif