/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 22:59:23 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/12 23:00:08 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_complex_mu(t_env *env, double complex oz, double complex z,
		double iter)
{
	double	mu;
	double	mod;

	(void)oz;
	if (iter == env->iter_max)
		mu = iter;
	else
	{
		mod = fabs(-cabs(z) - 0.5 / cabs(oz - z));
		mod = log(log(mod)) / log(2);
		mu = iter + env->psych - mod;
	}
	return (mu);
}

double	ft_complex_iter(t_thread *th, t_env *env, int row, int col)
{
	double			iter;
	double			tol;
	double complex	oz;
	double complex	z;
	
	env->zoom = (env->zoom < 0 ? 0 : env->zoom);
	th->x = (2 * col - env->win_wth) / (env->zoom * env->win_wth / 2) +
		env->x_offset;
	th->y = (2 * row - env->win_hgt) / (env->zoom * env->win_hgt / 2) +
		env->y_offset;
	z = th->x + th->y * I;
	iter = 0;
	tol = 0.000001;
	while (++iter < env->iter_max)
	{
		oz = z;
		z = oz - (P8(oz) + 15 * P4(oz) - 16) / (8 * P7(oz) + 60 * P3(oz));
		if (cabs(z - oz) < tol)
			break;
	}
	return (iter = (env->color_setting == CONTINUOUS ?
		ft_complex_mu(env, oz, z, iter) : iter));
}

void	ft_complex_draw(t_thread *th, t_env *env, int row, int row_end)
{
	int		col;
	double	iter;

	while (++row < row_end)
	{
		col = -1;
		while (++col < env->win_wth)
		{
			iter = ft_complex_iter(th, env, row, col);
			if (env->color_setting == CONTINUOUS)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : ft_color_cont(env, iter));
			else if (env->color_setting == DISCRETE)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : env->color[(int)iter % 50]);
		}
	}
}
