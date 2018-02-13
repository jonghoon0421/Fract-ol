/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:50:40 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/08 23:55:47 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_val(t_env *env)
{
	env->win_wth = 400;
	env->win_hgt = 400;
	env->x_offset = 0;
	env->y_offset = 0;
	env->zoom = 1;
	env->iter_max = 20;
	env->psych = 0;
	env->r = 0;
	env->c = 0;
	env->julia_mode = JULIA_MOVE;
	if (env->color_init == 0)
	{
		env->color_info = (t_color*)ft_memalloc(sizeof(t_color) * 2);
		env->color_init = 1;
	}
	env->color_info->center = 127.5;
	env->color_info->width = 127.5;
	env->color_info->step = 50;
	env->color_info->freq_r = 0.4;
	env->color_info->freq_g = 0.4;
	env->color_info->freq_b = 0.4;
	env->color_setting = DISCRETE;
	ft_color_band(env);
}

void	ft_init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_wth, env->win_hgt, "TEST");
	env->img = mlx_new_image(env->mlx, env->win_wth, env->win_hgt);
	env->data = (int*)mlx_get_data_addr(env->img, &env->bits_per_pixel,
		&env->size_line, &env->endian);
}

void	ft_init_multi_threading(t_env *env)
{
	int			i;
	int			y_dist;
	t_thread	thread[THREAD_NUM];
	int			ret;

	i = -1;
	y_dist = env->win_hgt / THREAD_NUM;
	while (++i < THREAD_NUM)
	{
		ret = 1;
		thread[i].e = env;
		thread[i].y_start = y_dist * i;
		thread[i].y_end = thread[i].y_start + y_dist;
		ret = pthread_create(&env->tid[i], NULL, main_draw, (void*)&thread[i]);
		(ret != 0 ? ft_error_msg("Error : pthread_create()") : 0);
	}
	i = -1;
	while (++i < THREAD_NUM)
	{
		ret = 1;
		ret = pthread_join(env->tid[i], NULL);
		(ret != 0 ? ft_error_msg("Error : pthread_join()") : 0);
	}
}
