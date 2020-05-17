/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:30:22 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 03:01:06 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

enum	e_error_code
{
	ERROR_graphical_init,
	ERROR_scene_init,
	ERROR_allocation_problem,
	ERROR_missing_asset
};

int	ft_raise_exception(int error_code, const char *description);
# endif
