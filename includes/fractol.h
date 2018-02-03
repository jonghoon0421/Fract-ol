/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:11:02 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/02 23:36:20 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <string.h>
# include <strings.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>

# define MOVE_UP 126
# define MOVE_DOWN 125
# define MOVE_LEFT 123
# define MOVE_RIGHT 124
# define ZOOM_IN 27
# define ZOOM_OUT 24
# define RESET 15
# define INC_ITER 34
# define DEC_ITER 31
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define DISCRETE 0
# define CONTINUOUS 1
# define PSYCH_OUTWARD 6
# define PSYCH_INWARD 7
# define COLOR_SCHEME 8
# define ESCAPE 53
# define CONVERSION 4

# define BLACK 0x000000
# define THREAD_NUM 4

typedef struct		s_color
{
	double			center;
	double			width;
	int				step;
	double			freq_r;
	double			freq_g;
	double			freq_b;
}					t_color;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			win_wth;
	double			win_hgt;
	double			move_x;
	double			move_y;
	double			zoom;
	double			iter_max;
	t_color			*color_info;
	int				color[50];
	int				mouse_x;
	int				mouse_y;
	pthread_t		tid[THREAD_NUM];
	int				chk;
	int				color_setting;
	double			psych;
}					t_env;

typedef struct		s_thread
{
	t_env			*e;
	int				y_start;
	int				y_end;
}					t_thread;

/*
** main.c
*/
void	*main_draw(void *arg);
void	main_exec(t_env *env);

/*
** ft_error.c
*/
void	ft_error_msg(char *str);

/*
** ft_mandelbrot.c
*/
double	ft_mandelbrot_iter(t_env *env, int row, int col);
double	ft_mandelbrot_mu(t_env *env, double x, double y, double iter);
void	ft_mandelbrot_draw(t_env *env, int row, int row_end);

/*
** ft_window.c
*/
int		ft_window_hook(int keycode, t_env *env);
int		ft_motion_hook(int keycode, int x, int y, t_env *env);

/*
** ft_init.c
*/
void	ft_init_val(t_env *env);
void	ft_init_mlx(t_env *env);
void	ft_init_multi_threading(t_env *env);

/*
** ft_color.c
*/
char	*rgb_to_hex(double r, double g, double b);
int		hex_to_int(char *hexstring);
char	*ft_itoa_base_prec(double value, int base);
void	ft_color_band(t_env *env);
int		ft_color_cont(t_env *env, double i);

#endif
