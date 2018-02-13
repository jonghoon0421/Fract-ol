/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:21:31 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/12 22:39:34 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_julia_mu(t_env *env, double x, double y, double iter)
{
	double	mu;
	double	mod;

	if (iter == env->iter_max)
		mu = iter;
	else
	{
		mod = x * x + y * y;
		mu = iter + env->psych + log(log(4) / log(mod)) / log(2);
	}
	return (mu);
}

double	ft_julia_iter(t_thread *th, t_env *env, int row, int col)
{
	double	iter;

	env->zoom = (env->zoom < 0 ? 0 : env->zoom);
	th->x = (2 * col - env->win_wth) / (env->zoom * env->win_wth / 2) +
		env->x_offset;
	th->y = (2 * row - env->win_hgt) / (env->zoom * env->win_hgt / 2) +
		env->y_offset;
	iter = 0;
	while (++iter < env->iter_max && (th->x * th->x + th->y * th->y) < 4)
	{
		th->ox = th->x;
		th->oy = th->y;
		th->x = P2(th->ox) - P2(th->oy) + (4 * env->c / env->win_wth) - 2;
		th->y = 2 * th->ox * th->oy + (4 * env->r / env->win_hgt) - 2;
	}
	return (iter = (env->color_setting == CONTINUOUS ?
		ft_julia_mu(env, th->x, th->y, iter) : iter));
}

void	ft_julia_draw(t_thread *th, t_env *env, int row, int row_end)
{
	int		col;
	double	iter;

	while (++row < row_end)
	{
		col = -1;
		while (++col < env->win_wth)
		{
			iter = ft_julia_iter(th, env, row, col);
			if (env->color_setting == CONTINUOUS)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : ft_color_cont(env, iter));
			else if (env->color_setting == DISCRETE)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : env->color[(int)iter % 50]);
		}
	}
}
