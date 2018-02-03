/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_wcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:43:20 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:20:41 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_wchr(t_printf *pf)
{
	int		i;

	i = -1;
	if (pf->arg.minus == 1)
		ft_work_wchr_left(pf);
	else
	{
		while (++i < pf->arg.width - 1)
			pf->ret += (pf->arg.zero == 1 ?
				write(1, "0", 1) : write(1, " ", 1));
		ft_work_wchr_wchar(pf);
	}
}

void	ft_set_wstr(t_printf *pf)
{
	int		i;
	int		length;

	i = -1;
	length = (pf->arg.g_prec == 1 ? pf->arg.prec : ft_work_wstr_len(pf));
	if (pf->arg.minus == 1)
		ft_work_wstr_left(pf, length);
	else
	{
		while (pf->arg.width-- > length)
			pf->ret += (pf->arg.zero == 1 ?
				write(1, "0", 1) : write(1, " ", 1));
		if (pf->arg.g_prec == 1 && pf->arg.prec >= 0)
			while (pf->wstr[++i] != 0 && ((i * 4) < pf->arg.prec))
				ft_work_wstr_wstr(pf, i);
		else
			while (pf->wstr[++i] != 0)
				ft_work_wstr_wstr(pf, i);
	}
}

void	ft_set_wcs(const char *format, t_printf *pf)
{
	pf->arg.type = format[pf->str_i];
	if (pf->arg.type == 'c' || pf->arg.type == 'C')
	{
		pf->wchr = va_arg(pf->ap, wchar_t);
		if (pf->wchr == '\0')
			return (ft_work_wchr_null(pf));
		ft_set_wchr(pf);
	}
	else if (pf->arg.type == 's' || pf->arg.type == 'S')
	{
		pf->wstr = va_arg(pf->ap, wchar_t*);
		if (pf->wstr == NULL)
			return (ft_work_wstr_null(pf));
		ft_set_wstr(pf);
	}
	pf->str_i++;
}
