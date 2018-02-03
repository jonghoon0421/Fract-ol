/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:09:24 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/02 16:36:07 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_msg(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	ft_error_inst(void)
{
	ft_printf("Choose one [parameter] from ...\n");
	ft_printf("Mandelbrot\n");
	ft_printf("Julia\n");
	ft_printf("Burning Ship\n");
	ft_printf("SOME_FRACTAL\n");
	ft_printf("SOME_FRACTAL\n");
}
