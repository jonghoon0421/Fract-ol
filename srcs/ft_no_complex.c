/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:00:37 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/12 23:00:52 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_no_complex_mu(t_env *env, t_thread *th, double iter)
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

double	ft_no_complex_iter(t_thread *th, t_env *env, int row, int col)
{
	double	iter;
	double	tmp;

	env->zoom = (env->zoom < 0 ? 0 : env->zoom);
	th->x = (2 * col - env->win_wth) / (env->zoom * env->win_wth / 2) +
		env->x_offset;
	th->y = (2 * row - env->win_hgt) / (env->zoom * env->win_hgt / 2) +
		env->y_offset;
	iter = 0;
	tmp = 1.0;
	while (++iter < env->iter_max && tmp > 0.000001)
	{
		th->ox = th->x;
		th->oy = th->y;
		tmp = P2(3 * P2(th->ox) - 3 * P2(th->oy) - 2) + P2(6 * th->ox * th->oy);
		th->x = (6 * P5(th->ox) + 12 * P3(th->ox) * P2(th->oy) -
				4 * P3(th->ox) - 6 * P2(th->ox) + 6 * th->ox * P4(th->oy) +
				12 * th->ox * P2(th->oy) + 6 * P2(th->oy) + 4) / tmp;
		th->y = (6 * P4(th->ox) * th->oy + 12 * P2(th->ox) * P3(th->oy) -
				12 * P2(th->ox) * th->oy + 12 * th->ox * th->oy +
				6 * P5(th->oy) + 4 * P3(th->oy)) / tmp;
		tmp = P2(th->x - th->ox) + P2(th->y - th->oy);
	}
	return (iter = (env->color_setting == CONTINUOUS ?
		ft_no_complex_mu(env, th, iter) : iter));
}

void	ft_no_complex_draw(t_thread *th, t_env *env, int row, int row_end)
{
	int		col;
	double	iter;

	while (++row < row_end)
	{
		col = -1;
		while (++col < env->win_wth)
		{
			iter = ft_no_complex_iter(th, env, row, col);
			if (env->color_setting == CONTINUOUS)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : ft_color_cont(env, iter));
			else if (env->color_setting == DISCRETE)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : env->color[(int)iter % 50]);
		}
	}
}
