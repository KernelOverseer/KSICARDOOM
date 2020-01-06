/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:33:45 by msidqi            #+#    #+#             */
/*   Updated: 2019/07/17 15:34:10 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

int		ft_destroy_matrix(t_matrix *mat)
{
	int	i;

	i = -1;
	if (!mat)
		return (0);
	while (++i < mat->rows)
		free(mat->v[i]);
	free(mat->v);
	free(mat);
	return (1);
}
