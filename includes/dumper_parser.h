/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_dumper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/28 12:59:46 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMPER_PARSER_H
# define DUMPER_PARSER_H

#include "graphical_objects.h"

# define CAST(node, type) ((type *)node->content)









/*
** ERROR HANDLING
*/

# define OPEN_ERROR 1
# define WRITE_ERROR 2

# define OPEN_ERROR_T "couldn't create world file."
# define WRITE_ERROR_T "error generating world file."

/*
** VALUES SLOTS
*/

# define CSECTOR 2 // current sector

#endif