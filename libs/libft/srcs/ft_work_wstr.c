/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:18:25 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:21:36 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_work_wstr_null(t_printf *pf)
{
	int		i;

	i = -1;
	if (pf->arg.minus == 1)
	{
		pf->ret += write(1, "(null)", 6);
		while (++i < pf->arg.width - 6)
			pf->ret += (pf->arg.zero == 1 ?
				write(1, "0", 1) : write(1, " ", 1));
	}
	else
	{
		while (++i < pf->arg.width - 6)
			pf->ret += (pf->arg.zero == 1 ?
				write(1, "0", 1) : write(1, " ", 1));
		pf->ret += write(1, "(null)", 6);
	}
}

void	ft_work_wstr_putchar(t_printf *pf, char c)
{
	pf->ret += write(1, &c, 1);
}

void	ft_work_wstr_wstr(t_printf *pf, int i)
{
	if (pf->wstr[i] <= 0x7F)
		ft_work_wstr_putchar(pf, pf->wstr[i]);
	else if (pf->wstr[i] <= 0x7FF)
	{
		ft_work_wstr_putchar(pf, (pf->wstr[i] >> 6) + 0xC0);
		ft_work_wstr_putchar(pf, (pf->wstr[i] & 0x3F) + 0x80);
	}
	else if (pf->wstr[i] <= 0xFFFF)
	{
		ft_work_wstr_putchar(pf, (pf->wstr[i] >> 12) + 0xE0);
		ft_work_wstr_putchar(pf, ((pf->wstr[i] >> 6) & 0x3F) + 0x80);
		ft_work_wstr_putchar(pf, (pf->wstr[i] & 0x3F) + 0x80);
	}
	else if (pf->wstr[i] <= 0x10FFFF)
	{
		ft_work_wstr_putchar(pf, (pf->wstr[i] >> 18) + 0xF0);
		ft_work_wstr_putchar(pf, ((pf->wstr[i] >> 12) & 0x3F) + 0x80);
		ft_work_wstr_putchar(pf, ((pf->wstr[i] >> 6) & 0x3F) + 0x80);
		ft_work_wstr_putchar(pf, (pf->wstr[i] & 0x3F) + 0x80);
	}
}

int		ft_work_wstr_len(t_printf *pf)
{
	int		i;
	int		length;

	i = -1;
	length = 0;
	while (pf->wstr[++i] != 0)
	{
		if (pf->wstr[i] <= 0x7F)
			length += 1;
		else if (pf->wstr[i] <= 0x7FF)
			length += 2;
		else if (pf->wstr[i] <= 0xFFFF)
			length += 3;
		else if (pf->wstr[i] <= 0x10FFFF)
			length += 4;
	}
	return (length);
}

void	ft_work_wstr_left(t_printf *pf, int length)
{
	int		i;

	i = -1;
	if (pf->arg.g_prec == 1)
	{
		while (pf->wstr[++i] != 0 && i < pf->arg.prec)
			ft_work_wstr_wstr(pf, i);
	}
	else
	{
		while (pf->wstr[++i] != 0)
			ft_work_wstr_wstr(pf, i);
	}
	i = -1;
	while (++i < pf->arg.width - length)
		pf->ret += (pf->arg.zero == 1 ? write(1, "0", 1) : write(1, " ", 1));
}
