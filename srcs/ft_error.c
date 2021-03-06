/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:09:24 by jonkim            #+#    #+#             */
/*   Updated: 2018/02/13 15:36:35 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_msg(char *str)
{
	ft_putendl(str);
	ft_error_parameter();
	exit(0);
}

void	ft_error_instruction(void)
{
	ft_printf("--------------------------KEYBOARD--------------------------\n");
	ft_printf("R : Reset current fractal\n");
	ft_printf("I, O : Increase / decrease max_iteration\n");
	ft_printf("D, F : Switch fractals (previous / next)\n");
	ft_printf("C : Switch color settings (continuous / discrete)\n");
	ft_printf("*Z, *X : Hold to start psychedelic effect (outward / inward)\n");
	ft_printf("ARROW KEYS : Move in 4 directions\n");
	ft_printf("+, - : Zoom in / out\n");
	ft_printf("**SPACE : Switch Julia behavior modes (static / dynamic)\n");
	ft_printf("ESC : Exit\n\n");
	ft_printf("----------------------------MOUSE---------------------------\n");
	ft_printf("LEFT CLICK : Bring the position to the center of window\n");
	ft_printf("**MOTION : Change constant term to cursor position\n");
	ft_printf("WHEEL UP, DOWN : Zoom in / out, follows cursor position\n\n");
	ft_printf("--------------------------NUMBER PAD------------------------\n");
	ft_printf("7, 8, 9 : Increase color frequency (R, G, B), respectively\n");
	ft_printf("4, 5, 6 : Decrease color frequency (R, G, B), respectively\n");
	ft_printf("*1 : Switch color arrangement or to black-n-gray scale\n\n");
	ft_printf(" * : Only available in 'CONTINUOUS' color setting\n");
	ft_printf("** : Only available in 'JULIA' fractal\n\n");
}

void	ft_error_parameter(void)
{
	ft_printf("Choose one [parameter] from ...\n");
	ft_printf("--------------------------PARAMETER-------------------------\n");
	ft_printf("[M] : Mandelbrot\n");
	ft_printf("[J] : Julia\n");
	ft_printf("[B] : Burning Ship\n");
	ft_printf("[T] : Tricorn\n");
	ft_printf("[N3] : Newton Method -- p(z) = z^3 - 1; a = 1\n");
	ft_printf("[N4] : Newton Method -- p(z) = z^4 - 1; a = 1\n");
	ft_printf("[WOC] : Newton Method -- p(z) = z^3 - 2*z - 2; a = 1\n");
	ft_printf("[WC] : Newton Method -- p(z) = z^8 + 15 * z^4 - 16; a = 1\n");
	ft_printf("[S] : Newton Method -- p(z) = sin(z); a = 1\n\n");
}
