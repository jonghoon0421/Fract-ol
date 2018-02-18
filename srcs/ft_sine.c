/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:13:45 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/17 16:54:18 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_sine_mu(t_env *env, double _Complex oz, double _Complex z,
		double iter)
{
	double	mu;
	double	mod;

	if (iter == env->iter_max)
		mu = iter;
	else
	{
		mod = fabs(-cabs(z) - 0.5 / cabs(oz - z));
		mod = log(log(mod)) / log(M_PI);
		mu = iter + env->psych - mod;
	}
	return (mu);
}

double	ft_sine_iter(t_thread *th, t_env *env, int row, int col)
{
	double			iter;
	double			tol;
	double _Complex	old_z;
	double _Complex	z;

	env->zoom = (env->zoom < 0 ? 0 : env->zoom);
	th->x = (2 * col - env->win_wth) / (env->zoom * env->win_wth / 2) +
		env->x_offset - M_PI / 2;
	th->y = (2 * row - env->win_hgt) / (env->zoom * env->win_hgt / 2) +
		env->y_offset;
	z = th->x + th->y * I;
	iter = 0;
	tol = 0.000001;
	while (++iter < env->iter_max)
	{
		old_z = z;
		z = old_z - csin(z) / ccos(z);
		if (cabs(z - old_z) < tol)
			break ;
	}
	return (iter = (env->color_setting == CONTINUOUS ?
		ft_sine_mu(env, old_z, z, iter) : iter));
}

void	ft_sine_draw(t_thread *th, t_env *env, int row, int row_end)
{
	int		col;
	double	iter;

	while (++row < row_end)
	{
		col = -1;
		while (++col < env->win_wth)
		{
			iter = ft_sine_iter(th, env, row, col);
			if (env->color_setting == CONTINUOUS)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : ft_color_cont(env, iter));
			else if (env->color_setting == DISCRETE)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : env->color[(int)iter % 50]);
		}
	}
}
