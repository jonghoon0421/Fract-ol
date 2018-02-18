/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:11:02 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/17 17:05:55 by jonkim           ###   ########.fr       */
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
# include <complex.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define TRICORN 4
# define NEWTON3 5
# define NEWTON4 6
# define WITHOUT_COMPLEX 7
# define WITH_COMPLEX 8
# define SINE 9

# define MOVE_UP 126
# define MOVE_DOWN 125
# define MOVE_LEFT 123
# define MOVE_RIGHT 124
# define ZOOM_IN 24
# define ZOOM_OUT 27
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
# define JULIA_MOVE 38
# define JULIA_HOLD 40
# define JULIA_TOGGLE 49
# define F_NEXT 3
# define F_PREV 2
# define P2(x) ((x) * (x))
# define P3(x) ((x) * (x) * (x))
# define P4(x) ((x) * (x) * (x) * (x))
# define P5(x) ((x) * (x) * (x) * (x) * (x))
# define P6(x) ((x) * (x) * (x) * (x) * (x) * (x))
# define P7(x) ((x) * (x) * (x) * (x) * (x) * (x) * (x))
# define P8(x) ((x) * (x) * (x) * (x) * (x) * (x) * (x) * (x))

# define PAD7 89
# define PAD4 86
# define PAD8 91
# define PAD5 87
# define PAD9 92
# define PAD6 88
# define PAD1 83
# define PAD2 84

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define THREAD_NUM 4

typedef struct	s_color
{
	double		center;
	double		width;
	int			step;
	double		freq_r;
	double		freq_g;
	double		freq_b;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		win_wth;
	double		win_hgt;
	double		x_offset;
	double		y_offset;
	double		x_counter;
	double		y_counter;
	double		zoom;
	double		iter_max;
	t_color		*color_info;
	int			color[50];
	pthread_t	tid[THREAD_NUM];
	int			color_setting;
	double		psych;
	int			fractal;
	double		r;
	double		c;
	int			julia_mode;
	int			color_init;
}				t_env;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_thread
{
	t_env		*e;
	int			y_start;
	int			y_end;
	double		x;
	double		y;
	double		ox;
	double		oy;
}				t_thread;

/*
** main.c
*/
void			*main_draw(void *arg);
void			main_exec(t_env *env);
void			main_center_mark(t_env *env);
void			main_pick_fractal(t_env *env, char **av);

/*
** ft_error.c
*/
void			ft_error_msg(char *str);
void			ft_error_parameter(void);
void			ft_error_instruction(void);

/*
** ft_mandelbrot.c
*/
double			ft_mandel_iter(t_thread *th, t_env *env, int row, int col);
double			ft_mandel_mu(t_env *env, double x, double y, double iter);
void			ft_mandel_draw(t_thread *th, t_env *env, int row, int row_end);

/*
** ft_burningship.c
*/
void			ft_burning_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_burning_iter(t_thread *th, t_env *env, int row, int col);
double			ft_burning_mu(t_env *env, double x, double y, double iter);

/*
** ft_julia.c
*/
void			ft_julia_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_julia_iter(t_thread *th, t_env *env, int row, int col);
double			ft_julia_mu(t_env *env, double x, double y, double iter);

/*
** ft_newton3.c
*/
void			ft_newton3_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_newton3_iter(t_thread *th, t_env *env, int row, int col);
double			ft_newton3_mu(t_env *env, t_thread *th, double iter);

/*
** ft_sine.c
*/
void			ft_sine_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_sine_iter(t_thread *th, t_env *env, int row, int col);
double			ft_sine_mu(t_env *env, double _Complex oz, double _Complex z,
				double iter);

/*
** ft_complex.c
*/
void			ft_complex_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_complex_iter(t_thread *th, t_env *env, int row, int col);
double			ft_complex_mu(t_env *env, double _Complex oz, double _Complex z,
				double iter);

/*
** ft_newton4.c
*/
void			ft_newton4_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_newton4_iter(t_thread *th, t_env *env, int row, int col);
double			ft_newton4_mu(t_env *env, t_thread *th, double iter);

/*
** ft_no_complex.c
*/
void			ft_no_complex_draw(t_thread *th, t_env *env, int row,
				int row_end);
double			ft_no_complex_iter(t_thread *th, t_env *env, int row, int col);
double			ft_no_complex_mu(t_env *env, t_thread *th, double iter);

/*
** ft_tricorn.c
*/
void			ft_tricorn_draw(t_thread *th, t_env *env, int row, int row_end);
double			ft_tricorn_iter(t_thread *th, t_env *env, int row, int col);
double			ft_tricorn_mu(t_env *env, double x, double y, double iter);

/*
** ft_window.c
*/
int				ft_window_hook(int keycode, t_env *env);
void			ft_window_hook_more(int keycode, t_env *env);
int				ft_mouse_hook(int keycode, int x, int y, t_env *env);
int				ft_motion_hook(int x, int y, t_env *env);
void			ft_window_mvmt(int keycode, t_env *env);

/*
** ft_init.c
*/
void			ft_init_val(t_env *env);
void			ft_init_mlx(t_env *env);
void			ft_init_multi_threading(t_env *env);

/*
** ft_color.c
*/
char			*rgb_to_hex(double r, double g, double b);
int				hex_to_int(char *hexstring);
char			*ft_itoa_base_prec(double value, int base);
void			ft_color_band(t_env *env);
int				ft_color_cont(t_env *env, double i);

#endif
