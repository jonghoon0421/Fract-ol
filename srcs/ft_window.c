/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 20:40:36 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/02 23:36:15 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_window_hook(int keycode, t_env *env)
{
	printf("%d\n", keycode);
	keycode == ESCAPE ? exit(0) : 0;
	keycode == MOVE_LEFT ? env->move_x += 0.05 : 0;
	keycode == MOVE_RIGHT ? env->move_x -= 0.05 : 0;
	keycode == MOVE_UP ? env->move_y += 0.05 : 0;
	keycode == MOVE_DOWN ? env->move_y -= 0.05 : 0;
	keycode == ZOOM_IN ? env->zoom *= 0.9 : 0;
	keycode == ZOOM_OUT ? env->zoom /= 0.9 : 0;
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
	main_exec(env);
	return (0);
}

int		ft_motion_hook(int keycode, int x, int y, t_env *env)
{
	if (keycode == LEFT_CLICK)
	{
		env->mouse_x = x;
		env->mouse_y = y;
	}
	keycode == WHEEL_UP ? env->zoom *= 1.1 : 0;
	keycode == WHEEL_DOWN ? env->zoom *= 0.9 : 0;
	main_exec(env);
	return (0);
}
