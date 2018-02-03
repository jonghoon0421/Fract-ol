/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:00:06 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/02 20:30:28 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	main_exec(t_env *env)
{
	ft_init_multi_threading(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void	*main_draw(void *arg)
{
	t_thread	*t;

	t = (t_thread*)arg;
	ft_mandelbrot_draw(t->e, t->y_start - 1, t->y_end);
	pthread_exit(NULL);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		if (ft_strstr(av[1], "Mandelbrot"))
		{
			ft_bzero(&env, sizeof(env));
			ft_init_val(&env);
			ft_init_mlx(&env);
			main_exec(&env);
			mlx_hook(env.win, 2, 0, ft_window_hook, &env);
			mlx_hook(env.win, 4, 0, ft_motion_hook, &env);
			mlx_loop(env.mlx);
		}
		else if (ft_strstr(av[1], "Julia"))
			ft_printf("%s\n", av[1]);
			// draw Julia
		else if (ft_strstr(av[1], "Burning"))
			ft_printf("%s\n", av[1]);
			// draw Burning Ship
		else if (ft_strstr(av[1], "SOME_FRACTAL"))
			ft_printf("%s\n", av[1]);
			// draw SOME_FRACTAL
		else if (ft_strstr(av[1], "SOME_FRACTAL"))
			ft_printf("%s\n", av[1]);
			// draw SOME_FRACTAL
		else
			ft_error_msg("Usage: ./fractol [parameter]");
	}
	else
		ft_error_msg("Usage: ./fractol [parameter]");
	return (0);
}
