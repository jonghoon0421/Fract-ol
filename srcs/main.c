/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:00:06 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/13 15:12:17 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	main_center_mark(t_env *env)
{
	int		rc;
	int		cc;

	rc = (int)env->win_hgt / 2;
	cc = (int)env->win_wth / 2;
	env->data[(rc) * env->size_line / CONVERSION + (cc)] = WHITE;
	env->data[(rc - 1) * env->size_line / 4 + (cc)] = WHITE;
	env->data[(rc - 2) * env->size_line / 4 + (cc)] = WHITE;
	env->data[(rc + 1) * env->size_line / 4 + (cc)] = WHITE;
	env->data[(rc + 2) * env->size_line / 4 + (cc)] = WHITE;
	env->data[(rc) * env->size_line / 4 + (cc - 1)] = WHITE;
	env->data[(rc) * env->size_line / 4 + (cc - 2)] = WHITE;
	env->data[(rc) * env->size_line / 4 + (cc + 1)] = WHITE;
	env->data[(rc) * env->size_line / 4 + (cc + 2)] = WHITE;
}

void	main_exec(t_env *env)
{
	static char	zoom[30] = "ZOOM : ";
	static char	x_ofs[30] = "X_OFF : ";
	static char	y_ofs[30] = "Y_OFF : ";

	ft_init_multi_threading(env);
	main_center_mark(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	ft_bzero(zoom + 7, 23);
	ft_bzero(x_ofs + 8, 22);
	ft_bzero(y_ofs + 8, 22);
	sprintf(zoom + 7, "%.2e", env->zoom);
	sprintf(x_ofs + 8, "%.1e", env->x_offset);
	sprintf(y_ofs + 8, "%.1e", env->y_offset);
	mlx_string_put(env->mlx, env->win, env->win_wth - 160, 0, WHITE, zoom);
	mlx_string_put(env->mlx, env->win, env->win_wth - 160, 15, WHITE, x_ofs);
	mlx_string_put(env->mlx, env->win, env->win_wth - 160, 30, WHITE, y_ofs);
}

void	*main_draw(void *arg)
{
	t_thread	*t;

	t = (t_thread*)arg;
	if (t->e->fractal == MANDELBROT)
		ft_mandel_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == JULIA)
		ft_julia_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == BURNINGSHIP)
		ft_burning_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == TRICORN)
		ft_tricorn_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == NEWTON3)
		ft_newton3_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == NEWTON4)
		ft_newton4_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == WITHOUT_COMPLEX)
		ft_no_complex_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == WITH_COMPLEX)
		ft_complex_draw(t, t->e, t->y_start - 1, t->y_end);
	else if (t->e->fractal == SINE)
		ft_sine_draw(t, t->e, t->y_start - 1, t->y_end);
	pthread_exit(NULL);
}

void	main_pick_fractal(t_env *env, char **av)
{
	if (ft_strstr(av[1], "M"))
		env->fractal = MANDELBROT;
	else if (ft_strstr(av[1], "J"))
		env->fractal = JULIA;
	else if (ft_strstr(av[1], "B"))
		env->fractal = BURNINGSHIP;
	else if (ft_strstr(av[1], "T"))
		env->fractal = TRICORN;
	else if (ft_strstr(av[1], "N3"))
		env->fractal = NEWTON3;
	else if (ft_strstr(av[1], "N4"))
		env->fractal = NEWTON4;
	else if (ft_strstr(av[1], "WOC"))
		env->fractal = WITHOUT_COMPLEX;
	else if (ft_strstr(av[1], "WC"))
		env->fractal = WITH_COMPLEX;
	else if (ft_strstr(av[1], "S"))
		env->fractal = SINE;
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2 && (ft_strcmp(av[1], "M") == 0 || ft_strcmp(av[1], "J") == 0
		|| ft_strcmp(av[1], "B") == 0 || ft_strcmp(av[1], "T") == 0 ||
		ft_strcmp(av[1], "N3") == 0 || ft_strcmp(av[1], "N4") == 0 ||
		ft_strcmp(av[1], "WOC") == 0 || ft_strcmp(av[1], "WC") == 0 ||
		ft_strcmp(av[1], "S") == 0))
	{
		ft_error_parameter();
		ft_error_instruction();
		ft_bzero(&env, sizeof(env));
		main_pick_fractal(&env, av);
		ft_init_val(&env);
		ft_init_mlx(&env);
		main_exec(&env);
		mlx_hook(env.win, 2, 0, ft_window_hook, &env);
		mlx_hook(env.win, 4, 0, ft_mouse_hook, &env);
		mlx_hook(env.win, 6, 0, ft_motion_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_error_msg("Usage: ./fractol [parameter]");
	return (0);
}
