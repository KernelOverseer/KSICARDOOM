/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_equation_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:05:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/10/03 13:43:01 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

static double	ft_root_3(double x)
{
	double	s;
	double	r;

	s = 1.0;
	r = 1.5;
	while (x < 1.0)
	{
		x *= 8.0;
		s *= 0.5;
	}
	while (x > 8.0)
	{
		x *= 0.125;
		s *= 2.0;
	}
	r -= 1.0 / 3.0 * (r - x / (r * r));
	r -= 1.0 / 3.0 * (r - x / (r * r));
	r -= 1.0 / 3.0 * (r - x / (r * r));
	r -= 1.0 / 3.0 * (r - x / (r * r));
	r -= 1.0 / 3.0 * (r - x / (r * r));
	r -= 1.0 / 3.0 * (r - x / (r * r));
	return (r * s);
}

static double	ft_root3(double x)
{
	if (x > 0)
		return (ft_root_3(x));
	else if (x < 0)
		return (-ft_root_3(-x));
	else
		return (0.0);
}

static int		ft_solve_equation_3_2(double *x, double *t, double a)
{
	t[5] = -ft_root3(fabs(t[2]) + sqrt(t[3] - t[4]));
	t[5] = t[2] < 0 ? -t[5] : t[5];
	t[6] = t[5] == 0 ? 0 : t[1] / t[5];
	x[0] = t[5] + t[6] - a / 3.0;
	x[1] = -0.5 * (t[5] + t[6]) - a / 3.0;
	x[2] = 0.5 * sqrt(3.0) * (t[5] - t[6]);
	if (fabs(x[2]) < 1e-6)
	{
		x[2] = x[1];
		return (2);
	}
	return (1);
}

int				ft_solve_equation_3(double *x, double a, double b, double c)
{
	double t[8];

	t[0] = a * a;
	t[1] = (t[0] - 3 * b) / 9.0;
	t[2] = (a * (2 * t[0] - 9 * b) + 27 * c) / 54.0;
	t[3] = t[2] * t[2];
	t[4] = t[1] * t[1] * t[1];
	if (t[3] <= (t[4] + 1e-6))
	{
		t[7] = t[2] / sqrt(t[4]);
		t[7] = t[7] < -1 ? -1 : t[7];
		t[7] = t[7] > 1 ? 1 : t[7];
		t[7] = acos(t[7]);
		t[1] = -2 * sqrt(t[1]);
		x[0] = t[1] * cos(t[7] / 3.0) - a / 3.0;
		x[1] = t[1] * cos((t[7] + 2 * M_PI) / 3.0) - a / 3.0;
		x[2] = t[1] * cos((t[7] - 2 * M_PI) / 3.0) - a / 3.0;
		return (3);
	}
	else
		return (ft_solve_equation_3_2(x, t, a));
}

void			ft_sort_double_table(double *x)
{
	double	t;

	if (x[0] > x[1])
	{
		t = x[0];
		x[0] = x[1];
		x[1] = t;
	}
	if (x[2] < x[1])
	{
		t = x[2];
		x[2] = x[1];
		x[1] = t;
		if (x[0] > x[1])
		{
			t = x[0];
			x[0] = x[1];
			x[1] = t;
		}
	}
}
