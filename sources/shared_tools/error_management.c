/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:29:06 by abiri             #+#    #+#             */
/*   Updated: 2020/05/16 03:00:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

const char	*g_error_codes[] =
{
	"Cannot initialise graphical environment",
	"Cannot initialise scene",
	"An allocation problem occured",
	"Missing asset : "
};

int	ft_raise_exception(int error_code, const char *description)
{
	const char	*error_decription;

	error_decription = g_error_codes[error_code];
	ft_putstr_fd("\e[1m\e[31mERROR : \e[0m", 2);
	ft_putstr_fd(error_decription, 2);
	if (description)
		ft_putstr_fd(description, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}