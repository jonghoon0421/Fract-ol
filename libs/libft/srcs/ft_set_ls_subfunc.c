/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ls_subfunc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 00:57:21 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:20:03 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_ls_subfunc1(t_printf *pf, int length)
{
	int		i;

	i = -1;
	while (++i < pf->arg.width - length)
		pf->ret += write(1, "0", 1);
	i = -1;
	while (++i < length)
		pf->ret += write(1, &pf->strtmp[i], 1);
}

void	ft_set_ls_subfunc2(t_printf *pf, int length)
{
	int		i;

	i = -1;
	while (++i < pf->arg.width - length)
		pf->ret += write(1, " ", 1);
	i = -1;
	while (++i < length)
		pf->ret += write(1, &pf->strtmp[i], 1);
}

void	ft_set_ls_subfunc3(t_printf *pf, int length)
{
	int		i;

	i = -1;
	while (++i < length)
		pf->ret += write(1, &pf->strtmp[i], 1);
	i = -1;
	while (++i < pf->arg.width - length)
		pf->ret += write(1, " ", 1);
}
