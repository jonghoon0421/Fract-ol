/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:29:20 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/12 22:43:35 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_newton4_mu(t_env *env, t_thread *th, double iter)
{
	double	mu;
	double	mod;

	if (iter == env->iter_max)
		mu = iter;
	else
	{
		mod = fabs(P2(th->x) + P2(th->y) - 0.5 /
			(P2(th->ox - th->x) + P2(th->oy - th->y)));
		mod = log(log(mod)) / log(2);
		mu = iter + env->psych - mod;
	}
	return (mu);
}

double	ft_newton4_iter(t_thread *th, t_env *env, int row, int col)
{
	double	iter;
	double	tmp;
	double	sum;

	env->zoom = (env->zoom < 0 ? 0 : env->zoom);
	th->x = (2 * col - env->win_wth) / (env->zoom * env->win_wth / 2) +
		env->x_offset;
	th->y = (2 * row - env->win_hgt) / (env->zoom * env->win_hgt / 2) +
		env->y_offset;
	iter = 0;
	tmp = 1.0;
	sum = 0.0;
	while (++iter < env->iter_max && tmp > 0.000001)
	{
		th->ox = th->x;
		th->oy = th->y;
		tmp = P3(P2(th->ox) + P2(th->oy));
		th->x = (3 * th->ox * tmp + P3(th->ox) - 3 * th->ox * P2(th->oy)) /
			(4.0 * tmp);
		th->y = (th->oy * (3 * tmp - 3 * P2(th->ox) + P2(th->oy))) /
			(4.0 * tmp);
		tmp = P2(th->x - th->ox) + P2(th->y - th->oy);
	}
	return (iter = (env->color_setting == CONTINUOUS ?
		ft_newton4_mu(env, th, iter) : iter));
}

void	ft_newton4_draw(t_thread *th, t_env *env, int row, int row_end)
{
	int		col;
	double	iter;

	while (++row < row_end)
	{
		col = -1;
		while (++col < env->win_wth)
		{
			iter = ft_newton4_iter(th, env, row, col);
			if (env->color_setting == CONTINUOUS)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : ft_color_cont(env, iter));
			else if (env->color_setting == DISCRETE)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : env->color[(int)iter % 50]);
		}
	}
}
