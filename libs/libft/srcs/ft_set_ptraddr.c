/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ptraddr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:39:19 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:20:27 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_ptraddr_wpad(t_printf *pf)
{
	int		i;
	int		length;

	i = -1;
	length = (int)ft_strlen(pf->tmp) + 2;
	if (pf->arg.g_width == 1 && pf->arg.width > length)
	{
		while (++i < pf->arg.width - length)
			pf->ret += write(1, " ", 1);
	}
	ft_putstr("0x");
	ft_putstr(pf->tmp);
	pf->ret += length;
}

void	ft_set_ptraddr_left(t_printf *pf)
{
	int		i;
	int		length;

	i = -1;
	length = (int)ft_strlen(pf->tmp) + 2;
	ft_putstr("0x");
	ft_putstr(pf->tmp);
	if (pf->arg.g_width == 1 && pf->arg.width > length)
		while (++i < pf->arg.width - length)
			pf->ret += write(1, " ", 1);
	pf->ret += length;
}

void	ft_set_ptraddr_zero(t_printf *pf)
{
	int		length;
	int		i;

	i = -1;
	length = (int)ft_strlen(pf->tmp) + 2;
	ft_putstr("0x");
	if (pf->arg.g_width == 1 && pf->arg.width > length)
		while (++i < pf->arg.width - length)
			pf->ret += write(1, "0", 1);
	ft_putstr(pf->tmp);
	pf->ret += length;
}

void	ft_set_ptraddr(const char *format, t_printf *pf)
{
	int		i;

	i = -1;
	pf->arg.type = format[pf->str_i];
	pf->unum = va_arg(pf->ap, unsigned long);
	pf->tmp = ft_ultoa_base(pf->unum, 16);
	if (pf->arg.zero == 1)
		ft_set_ptraddr_zero(pf);
	else if (pf->arg.minus == 1)
		ft_set_ptraddr_left(pf);
	else
		ft_set_ptraddr_wpad(pf);
	free(pf->tmp);
	pf->str_i++;
}
