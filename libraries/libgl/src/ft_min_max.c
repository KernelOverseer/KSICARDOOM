/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:22:19 by msidqi            #+#    #+#             */
/*   Updated: 2019/07/17 15:22:41 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

double	ft_max(double val, double max)
{
	return (val > max ? max : val);
}

double	ft_min(double val, double min)
{
	return (val < min ? min : val);
}
