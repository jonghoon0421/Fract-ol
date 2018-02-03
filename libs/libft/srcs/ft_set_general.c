/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:13:55 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:19:11 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_general_zero(t_printf *pf)
{
	int		i;

	i = -1;
	if (pf->arg.g_width == 1 && pf->arg.width > 1)
	{
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, "0", 1);
	}
	pf->ret += write(1, &pf->arg.type, 1);
}

void	ft_set_general_left(t_printf *pf)
{
	int		i;

	i = -1;
	pf->ret += write(1, &pf->arg.type, 1);
	if (pf->arg.g_width == 1 && pf->arg.width > 1)
	{
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, " ", 1);
	}
}

void	ft_set_general_wpad(t_printf *pf)
{
	int		i;

	i = -1;
	if (pf->arg.g_width == 1 && pf->arg.width > 1)
	{
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, " ", 1);
	}
	pf->ret += write(1, &pf->arg.type, 1);
}

void	ft_set_general(const char *format, t_printf *pf)
{
	pf->arg.type = format[pf->str_i];
	if (pf->arg.zero == 1)
		ft_set_general_zero(pf);
	else if (pf->arg.minus == 1)
		ft_set_general_left(pf);
	else
		ft_set_general_wpad(pf);
	pf->str_i++;
}
