/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_wchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:17:26 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:21:26 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_work_wchr_null(t_printf *pf)
{
	int		i;

	i = -1;
	while (++i < pf->arg.width - 1)
		pf->ret += (pf->arg.zero == 1 ? write(1, "0", 1) : write(1, " ", 1));
	pf->ret += write(1, "\0", 1);
}

void	ft_work_wchr_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_work_wchr_wchar(t_printf *pf)
{
	if (pf->wchr <= 0x7F)
		ft_work_wchr_putchar(pf->wchr);
	else if (pf->wchr <= 0x7FF)
	{
		ft_work_wchr_putchar((pf->wchr >> 6) + 0xC0);
		ft_work_wchr_putchar((pf->wchr & 0x3F) + 0x80);
	}
	else if (pf->wchr <= 0xFFFF)
	{
		ft_work_wchr_putchar((pf->wchr >> 12) + 0xE0);
		ft_work_wchr_putchar(((pf->wchr >> 6) & 0x3F) + 0x80);
		ft_work_wchr_putchar((pf->wchr & 0x3F) + 0x80);
	}
	else if (pf->wchr <= 0x10FFFF)
	{
		ft_work_wchr_putchar((pf->wchr >> 18) + 0xF0);
		ft_work_wchr_putchar(((pf->wchr >> 12) & 0x3F) + 0x80);
		ft_work_wchr_putchar(((pf->wchr >> 6) & 0x3F) + 0x80);
		ft_work_wchr_putchar((pf->wchr & 0x3F) + 0x80);
	}
	pf->ret += 1;
}

void	ft_work_wchr_left(t_printf *pf)
{
	int		i;

	i = -1;
	ft_work_wchr_wchar(pf);
	if (pf->arg.g_width == 1 && pf->arg.width > 1)
	{
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, " ", 1);
	}
}
