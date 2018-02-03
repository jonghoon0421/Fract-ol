/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:21:31 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/02 23:36:13 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_mandelbrot_mu(t_env *env, double x, double y, double iter)
{
	double	mu;
	double	mod;

	if (iter == env->iter_max)
		mu = iter;
	else
	{
		mod = sqrt(x * x + y * y);
		mu = iter + env->psych - log(log(mod)) / log(2);
	}
	return (mu);
}

double	ft_mandelbrot_iter(t_env *env, int row, int col)
{
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	old_x;
	double	old_y;
	double	iter;

	env->zoom = (env->zoom < 0 ? 0 : env->zoom);
	c_re = (2 * col - env->win_wth) / (env->zoom * env->win_wth / 2) +
		env->move_x / env->zoom;
	c_im = (2 * row - env->win_hgt) / (env->zoom * env->win_hgt / 2) +
		env->move_y / env->zoom;
	x = 0;
	y = 0;
	iter = -1;
	while (++iter < env->iter_max && (x * x + y * y) <= 4)
	{
		old_x = x;
		old_y = y;
		x = old_x * old_x - old_y * old_y + c_re;
		y = 2 * old_x * old_y + c_im;
	}
	return (iter = (env->color_setting == CONTINUOUS ?
		ft_mandelbrot_mu(env, x, y, iter) : iter));
}

void	ft_mandelbrot_draw(t_env *env, int row, int row_end)
{
	int		col;
	double	iter;

	while (++row < row_end)
	{
		col = -1;
		while (++col < env->win_wth)
		{
			iter = ft_mandelbrot_iter(env, row, col);
			if (env->color_setting == CONTINUOUS)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : ft_color_cont(env, iter));
			else if (env->color_setting == DISCRETE)
				env->data[(row * env->size_line / CONVERSION) + col] =
				(iter == env->iter_max ? BLACK : env->color[(int)iter % 50]);
		}
	}
}
