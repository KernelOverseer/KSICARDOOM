/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_equation_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:05:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/10/03 13:42:23 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

static int		ft_solve_4_bi(double *x, double b, double d)
{
	double t;
	double s[6];

	t = b * b - 4 * d;
	if (t >= 0)
	{
		s[0] = sqrt(t);
		s[1] = (-b + s[0]) / 2;
		s[2] = (-b - s[0]) / 2;
		if (s[1] < 0)
			return (0);
		s[3] = sqrt(-s[2]);
		s[4] = sqrt(s[1]);
		s[5] = sqrt(s[2]);
		x[0] = -s[4];
		x[1] = s[4];
		x[2] = s[2] >= 0 ? -s[5] : 0;
		x[3] = s[2] >= 0 ? s[5] : s[3];
		return (s[2] >= 0 ? 4 : 2);
	}
	else
		return (0);
}

static double	ft_nf4step(double x, t_solve solve)
{
	double	fxs;
	double	fx;

	fxs = ((4 * x * 3 * solve.a) * x + 2 * solve.b) * x + solve.c;
	if (fxs == 0)
		return (x);
	fx = (((x + solve.a) * x + solve.b) * x + solve.c) * x + solve.d;
	return (x - fx / fxs);
}

static int		ft_solve_4_de_2(double *x, double c)
{
	double	sz1;
	double	szr;
	double	szi;
	double	r;

	sz1 = sqrt(x[0]);
	r = sqrt(x[1] * x[1] + x[2] * x[2]);
	if (x[2] == 0)
	{
		r = sqrt(r);
		szr = x[1] >= 0 ? r : 0;
		szi = x[1] >= 0 ? 0 : r;
	}
	else
	{
		szr = sqrt(0.5 * (x[1] + r));
		szi = 0.5 * x[2] / szr;
	}
	x[0] = c > 0 ? -sz1 / 2 - szr : sz1 / 2 - szr;
	x[1] = c > 0 ? -sz1 / 2 + szr : sz1 / 2 + szr;
	x[2] = c > 0 ? sz1 / 2 : -sz1 / 2;
	x[3] = c > 0 ? szi : szi;
	return (2);
}

static int		ft_solve_4_de(double *x, double b, double c, double d)
{
	int		res;
	double	s[3];

	if (fabs(c) < 1e-14 * (fabs(b) + fabs(d)))
		return (ft_solve_4_bi(x, b, d));
	res = ft_solve_equation_3(x, 2 * b, b * b - 4 * d, -c * c);
	if (res > 1)
	{
		ft_sort_double_table(x);
		if (x[0] > 0)
		{
			s[0] = sqrt(x[0]);
			s[1] = sqrt(x[1]);
			s[2] = sqrt(x[2]);
			x[0] = c > 0 ? (-s[0] - s[1] - s[2]) / 2 : (s[2] - s[1] - s[0]) / 2;
			x[1] = c > 0 ? (-s[0] + s[1] + s[2]) / 2 : (s[1] - s[0] - s[2]) / 2;
			x[2] = c > 0 ? (s[0] - s[1] + s[2]) / 2 : (s[0] - s[1] - s[2]) / 2;
			x[3] = c > 0 ? (s[0] + s[1] - s[2]) / 2 : (s[0] + s[1] + s[2]) / 2;
			return (4);
		}
		return (0);
	}
	x[0] = x[0] < 0 ? 0 : x[0];
	return (ft_solve_4_de_2(x, c));
}

int				ft_solve_equation_4(t_solve solve, double *x)
{
	int	res;

	solve.m = solve.d + 0.25 * solve.a * (0.25 * solve.b * solve.a
			- 3. / 64 * solve.a * solve.a * solve.a - solve.c);
	solve.n = solve.c + 0.5 * solve.a * (0.25 * solve.a * solve.a - solve.b);
	solve.o = solve.b - 0.375 * solve.a * solve.a;
	res = ft_solve_4_de(x, solve.o, solve.n, solve.m);
	x[3] = res == 4 ? x[3] - solve.a / 4 : x[3];
	x[1] = res == 2 || res == 4 ? x[1] - solve.a / 4 : x[1];
	x[0] -= solve.a / 4;
	x[2] -= solve.a / 4;
	if (res > 0)
	{
		x[0] = ft_nf4step(x[0], solve);
		x[1] = ft_nf4step(x[1], solve);
	}
	if (res > 2)
	{
		x[2] = ft_nf4step(x[2], solve);
		x[3] = ft_nf4step(x[3], solve);
	}
	return (res);
}
