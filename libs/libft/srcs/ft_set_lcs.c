/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:40:07 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:19:35 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_lc(t_printf *pf)
{
	int i;

	i = -1;
	if (pf->arg.minus != 1 && pf->arg.g_width == 1 && pf->arg.zero == 1)
	{
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, "0", 1);
		pf->ret += write(1, &pf->chrtmp, 1);
	}
	else if (pf->arg.minus != 1 && pf->arg.g_width == 1)
	{
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, " ", 1);
		pf->ret += write(1, &pf->chrtmp, 1);
	}
	else if (pf->arg.minus == 1 && pf->arg.g_width == 1)
	{
		pf->ret += write(1, &pf->chrtmp, 1);
		while (++i < pf->arg.width - 1)
			pf->ret += write(1, " ", 1);
	}
	else
		pf->ret += write(1, &pf->chrtmp, 1);
}

void	ft_set_lsprec(t_printf *pf)
{
	char	*onesec;
	int		len;
	int		i;

	i = -1;
	len = (int)ft_strlen(pf->strtmp);
	if (pf->arg.g_prec == 1 && pf->arg.prec == 0)
		pf->strtmp = ft_strnew(0);
	else if (pf->arg.g_prec == 1 && pf->arg.prec > 0 && (pf->arg.prec < len))
	{
		onesec = (char*)malloc(sizeof(char) * (pf->arg.prec));
		while (++i < pf->arg.prec)
			onesec[i] = pf->strtmp[i];
		onesec[pf->arg.prec] = '\0';
		free(pf->strtmp);
		pf->strtmp = ft_strdup(onesec);
		free(onesec);
	}
	else
		return ;
}

void	ft_set_ls(t_printf *pf)
{
	int i;
	int len;

	ft_set_lsprec(pf);
	i = -1;
	len = (int)ft_strlen(pf->strtmp);
	if (pf->arg.minus != 1 && pf->arg.g_width == 1 && pf->arg.zero == 1)
		ft_set_ls_subfunc1(pf, len);
	else if (pf->arg.minus != 1 && pf->arg.g_width == 1)
		ft_set_ls_subfunc2(pf, len);
	else if (pf->arg.minus == 1 && pf->arg.g_width == 1)
		ft_set_ls_subfunc3(pf, len);
	else
		while (++i < len)
			pf->ret += write(1, &pf->strtmp[i], 1);
}

void	ft_set_lcs(const char *format, t_printf *pf)
{
	if (format[pf->str_i] == 'c' || format[pf->str_i] == 'C')
	{
		pf->arg.type = format[pf->str_i];
		pf->chrtmp = va_arg(pf->ap, int);
		ft_set_lc(pf);
	}
	else if (format[pf->str_i] == 's' || format[pf->str_i] == 'S')
	{
		pf->arg.type = format[pf->str_i];
		pf->strtmp = va_arg(pf->ap, char*);
		if (pf->strtmp == NULL)
			ft_work_wstr_null(pf);
		else
		{
			pf->strtmp = ft_strdup(pf->strtmp);
			ft_set_ls(pf);
		}
	}
	free(pf->strtmp);
	pf->str_i++;
}
