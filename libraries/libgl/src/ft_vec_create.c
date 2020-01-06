/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:31:41 by msidqi            #+#    #+#             */
/*   Updated: 2019/10/05 15:37:52 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

void		ft_create_vec2(t_vec2 *a, double x, double y)
{
	a->x = x;
	a->y = y;
}

void		ft_create_vec3(t_vec3 *a, double x, double y, double z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}

/*
** free matrix with ft_destroy_matrix
*/

t_matrix	*ft_create_matrix(int rows, int cols)
{
	t_matrix		*mat;
	int				i;
	int				j;

	i = -1;
	if (rows != cols || rows * cols < 2 || !(mat = malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(mat->v = (double **)malloc(sizeof(double*) * rows)))
		return (NULL);
	mat->cols = cols;
	mat->rows = rows;
	while (++i < rows)
	{
		mat->v[i] = (double *)malloc(sizeof(double) * cols);
		j = -1;
		while (++j < cols)
		{
			if (j == i)
				mat->v[i][j] = 1;
			else
				mat->v[i][j] = 0;
		}
	}
	return (mat);
}

t_matrix4	ft_create_matrix4(void)
{
	unsigned int	i;
	unsigned int	j;
	t_matrix4		mat;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j == i)
				mat.v[i][j] = 1;
			else
				mat.v[i][j] = 0;
		}
	}
	return (mat);
}

t_vec4		ft_create_vec4(double x, double y, double z, double w)
{
	t_vec4	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}
