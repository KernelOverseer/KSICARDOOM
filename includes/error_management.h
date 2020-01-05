/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:30:22 by abiri             #+#    #+#             */
/*   Updated: 2020/01/05 21:21:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

enum	e_error_code
{
	ERROR_graphical_init,
	ERROR_scene_init,
	ERROR_allocation_problem
};

int	ft_raise_exception(int error_code, char *description);
# endif
