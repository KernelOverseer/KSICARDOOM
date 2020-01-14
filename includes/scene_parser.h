/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2020/01/14 21:40:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "graphical_objects.h"

# define TEXTURE_TYPE uint32_t

# define IO_ERROR_WRAPPER(x) err > -1 ? x : IO_ERROR
# define NO_ERROR(e) e > -1
# define OPEN_ERROR 1
# define IO_ERROR 2
# define MALLOC_ERROR 3

#endif
