/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 20:40:36 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/13 00:23:04 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_window_offset(int keycode, t_env *env)
{
	if (keycode == MOVE_LEFT)
		env->x_offset += 0.05 / env->zoom;
	if (keycode == MOVE_RIGHT)
		env->x_offset -= 0.05 / env->zoom;
	if (keycode == MOVE_UP)
		env->y_offset += 0.05 / env->zoom;
	if (keycode == MOVE_DOWN)
		env->y_offset -= 0.05 / env->zoom;
}

void	ft_window_hook_more(int keycode, t_env *env)
{
	if (keycode == JULIA_MOVE)
		env->julia_mode = JULIA_MOVE;
	if (keycode == JULIA_HOLD)
		env->julia_mode = JULIA_HOLD;
	if (keycode == F_CHANGE)
	{
		env->fractal++;
		if (env->fractal == 10)
			env->fractal = 1;
	}
	env->color_info->freq_r += (keycode == PAD7 ? 0.1 : 0);
	env->color_info->freq_r -= (keycode == PAD4 ? 0.1 : 0);
	env->color_info->freq_g += (keycode == PAD8 ? 0.1 : 0);
	env->color_info->freq_g -= (keycode == PAD5 ? 0.1 : 0);
	env->color_info->freq_b += (keycode == PAD9 ? 0.1 : 0);
	env->color_info->freq_b -= (keycode == PAD6 ? 0.1 : 0);
	if (keycode == PAD1)
	{
		if (env->color_info->width == 127.5)
			env->color_info->width = 0;
		else if (env->color_info->width == 0)
			env->color_info->width = -127.5;
		else if (env->color_info->width == -127.5)
			env->color_info->width = 127.5;
	}
}

int		ft_window_hook(int keycode, t_env *env)
{
	keycode == ESCAPE ? exit(0) : 0;
	if (keycode >= 123 && keycode <= 126)
		ft_window_offset(keycode, env);
	keycode == ZOOM_IN ? env->zoom /= 0.9 : 0;
	keycode == ZOOM_OUT ? env->zoom *= 0.9 : 0;
	keycode == RESET ? ft_init_val(env) : 0;
	keycode == INC_ITER ? env->iter_max += 1 : 0;
	keycode == DEC_ITER ? env->iter_max -= 1 : 0;
	if (env->color_setting == CONTINUOUS)
	{
		keycode == PSYCH_OUTWARD ? env->psych++ : 0;
		keycode == PSYCH_INWARD ? env->psych-- : 0;
	}
	if (keycode == COLOR_SCHEME)
	{
		if (env->color_setting == DISCRETE)
			env->color_setting = CONTINUOUS;
		else
			env->color_setting = DISCRETE;
	}
	ft_window_hook_more(keycode, env);
	main_exec(env);
	return (0);
}

int		ft_mouse_hook(int keycode, int x, int y, t_env *env)
{
	env->x_counter = ((2 * x - env->win_wth) / (env->win_wth / 2)) / env->zoom;
	env->y_counter = ((2 * y - env->win_hgt) / (env->win_hgt / 2)) / env->zoom;
	if (keycode == LEFT_CLICK)
	{
		env->x_offset += env->x_counter;
		env->y_offset += env->y_counter;
	}
	if (keycode == WHEEL_UP || keycode == WHEEL_DOWN)
	{
		if (keycode == WHEEL_UP)
		{
			env->x_offset += env->x_counter / 9.5;
			env->y_offset += env->y_counter / 9.5;
			env->zoom /= 0.9;
		}
		else
		{
			env->x_offset -= env->x_counter / 9.5;
			env->y_offset -= env->y_counter / 9.5;
			env->zoom *= 0.9;
		}
	}
	main_exec(env);
	return (0);
}

int		ft_motion_hook(int x, int y, t_env *env)
{
	if (env->julia_mode == JULIA_MOVE)
	{
		env->c = x;
		env->r = y;
	}
	main_exec(env);
	return (0);
}
