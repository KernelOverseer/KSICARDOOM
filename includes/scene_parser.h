/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/14 22:00:36 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "graphical_objects.h"

# define TEXTURE_TYPE uint32_t

//dummy
typedef struct s_vector
{

}				t_vector;

# define IO_ERROR_WRAPPER(x) err > -1 ? x : IO_ERROR
# define NO_ERROR(e) (e > -1)
# define OPEN_ERROR 1
# define IO_ERROR 2
# define MALLOC_ERROR 3

# define CAST(x, t) ((t)x)

#endif
