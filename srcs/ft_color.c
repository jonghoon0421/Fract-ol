/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:23:42 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/02 21:10:25 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color_cont(t_env *env, double i)
{
	double	r;
	double	g;
	double	b;
	int		color;
	char	*res;

	r = sin(env->color_info->freq_r * i + 0) * env->color_info->width +
		env->color_info->center;
	g = sin(env->color_info->freq_g * i + (2 * M_PI / 3)) *
		env->color_info->width + env->color_info->center;
	b = sin(env->color_info->freq_b * i + (4 * M_PI / 3)) *
		env->color_info->width + env->color_info->center;
	res = rgb_to_hex(round(r), round(g), round(b));
	color = hex_to_int(res);
	return (color);
}

void	ft_color_band(t_env *env)
{
	int		i;
	double	r;
	double	g;
	double	b;
	char	*res;

	i = -1;
	while (++i < env->color_info->step)
	{
		r = sin(env->color_info->freq_r * i + 0) * env->color_info->width +
			env->color_info->center;
		g = sin(env->color_info->freq_g * i + (2 * M_PI / 3)) *
			env->color_info->width + env->color_info->center;
		b = sin(env->color_info->freq_b * i + (4 * M_PI / 3)) *
			env->color_info->width + env->color_info->center;
		res = rgb_to_hex(round(r), round(g), round(b));
		env->color[i] = hex_to_int(res);
	}
}

int		hex_to_int(char *hexstring)
{
	int				number;

	number = (int)strtol(hexstring, NULL, 0);
	return (number);
}

char	*rgb_to_hex(double r, double g, double b)
{
	char	*first;
	char	*second;
	char	*third;
	char	*tmp;
	char	*hexstring;

	first = ft_itoa_base_prec(r, 16);
	tmp = ft_strjoin("0x", first);
	second = ft_itoa_base_prec(g, 16);
	hexstring = ft_strjoin(tmp, second);
	free(tmp);
	tmp = ft_strdup(hexstring);
	free(hexstring);
	third = ft_itoa_base_prec(b, 16);
	hexstring = ft_strjoin(tmp, third);
	free(tmp);
	return (hexstring);
}

char		*ft_itoa_base_prec(double value, int base)
{
	char	*stpoint;
	char	*res;
	long	n;
	int		neg;
	int		leng;

	stpoint = "0123456789ABCDEF";
	n = (long)value;
	leng = 2;
	neg = ((n < 0 && base == 10) ? 1 : 0);
	if (n < 0)
		n = -n;
	if (!(res = (char*)malloc(sizeof(char) * (leng + 1))))
		return (0);
	res[leng] = '\0';
	while (leng > 0)
	{
		res[--leng] = stpoint[n % (long)base];
		n /= (long)base;
	}
	if (neg == 1)
		res[0] = 45;
	return (res);
}
