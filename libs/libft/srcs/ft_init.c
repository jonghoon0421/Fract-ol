/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:01:00 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:24:08 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_arg(t_printf *pf)
{
	pf->arg.hash = 0;
	pf->arg.sp = 0;
	pf->arg.plus = 0;
	pf->arg.minus = 0;
	pf->arg.zero = 0;
	pf->arg.neg = 0;
	pf->arg.lmod = pf_none;
	pf->arg.type = 0;
	pf->arg.prec = 0;
	pf->arg.g_prec = 0;
	pf->arg.g_width = 0;
	pf->arg.g_lmod = 0;
	pf->tmp = NULL;
	pf->strtmp = NULL;
	pf->output = NULL;
	pf->wchr = 0;
	pf->wstr = NULL;
}
