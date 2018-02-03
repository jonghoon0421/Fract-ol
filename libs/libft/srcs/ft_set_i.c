/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:46:15 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:19:22 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_iprec(t_printf *pf)
{
	int		length;
	int		siz;
	int		i;

	i = -1;
	length = ft_set_iprec_prep(pf);
	if (pf->tmp[0] == '0' && pf->arg.zero == 0)
	{
		if (pf->arg.g_prec == 1 && pf->arg.prec == 0)
			pf->output = ft_strnew(0);
		else if (pf->arg.g_prec == 0)
			pf->output = ft_strdup("0");
	}
	else if (pf->arg.g_prec == 1 && (pf->arg.prec > length))
	{
		pf->output = (char*)malloc(sizeof(char) * (pf->arg.prec + 1));
		ft_memset(pf->output, '0', pf->arg.prec);
		pf->output[pf->arg.prec] = '\0';
		siz = pf->arg.prec - length;
		while (++i + siz < pf->arg.prec)
			pf->output[i + siz] = pf->tmp[i];
	}
	else
		pf->output = ft_strdup(pf->tmp);
}

void	ft_set_int_lmod(t_printf *pf)
{
	if (pf->arg.type == 'D')
		pf->tmp = ft_ltoa((long)pf->num);
	else if (pf->arg.lmod == pf_none)
		pf->tmp = ft_itoa((int)pf->num);
	else if (pf->arg.lmod == pf_h)
		pf->tmp = ft_itoa((short)pf->num);
	else if (pf->arg.lmod == pf_hh)
		pf->tmp = ft_itoa((char)pf->num);
	else if (pf->arg.lmod == pf_l)
		pf->tmp = ft_ltoa((long)pf->num);
	else if (pf->arg.lmod == pf_ll)
		pf->tmp = ft_ltoa((long long)pf->num);
	else if (pf->arg.lmod == pf_j)
		pf->tmp = ft_ltoa((intmax_t)pf->num);
	else if (pf->arg.lmod == pf_z)
		pf->tmp = ft_ultoa((ssize_t)pf->num);
}

void	ft_set_int(const char *format, t_printf *pf)
{
	pf->arg.type = format[pf->str_i];
	pf->num = va_arg(pf->ap, long);
	ft_set_int_lmod(pf);
	ft_set_iprec(pf);
	if (pf->arg.zero == 1 && pf->arg.g_prec == 0)
		ft_work_int_zero(pf);
	else if (pf->arg.minus == 1)
		ft_work_int_left(pf);
	else
		ft_work_int_wpad(pf);
	free(pf->output);
	if (pf->arg.neg == 1)
		free(--pf->tmp);
	else
		free(pf->tmp);
	pf->str_i++;
}

void	ft_set_uint_lmod(t_printf *pf)
{
	if (pf->arg.type == 'U')
		pf->tmp = ft_ultoa((unsigned long)pf->unum);
	else if (pf->arg.lmod == pf_none)
		pf->tmp = ft_ultoa((unsigned int)pf->unum);
	else if (pf->arg.lmod == pf_h)
		pf->tmp = ft_ultoa((unsigned short)pf->unum);
	else if (pf->arg.lmod == pf_hh)
		pf->tmp = ft_ultoa((unsigned char)pf->unum);
	else if (pf->arg.lmod == pf_l)
		pf->tmp = ft_ultoa((unsigned long)pf->unum);
	else if (pf->arg.lmod == pf_ll)
		pf->tmp = ft_ultoa((unsigned long long)pf->unum);
	else if (pf->arg.lmod == pf_j)
		pf->tmp = ft_ultoa((uintmax_t)pf->unum);
	else if (pf->arg.lmod == pf_z)
		pf->tmp = ft_ultoa((size_t)pf->unum);
}

void	ft_set_uint(const char *format, t_printf *pf)
{
	pf->arg.type = format[pf->str_i];
	pf->unum = va_arg(pf->ap, unsigned long);
	ft_set_uint_lmod(pf);
	ft_set_iprec(pf);
	if (pf->arg.zero == 1 && pf->arg.g_prec == 0)
		ft_work_uint_zero(pf);
	else if (pf->arg.minus == 1)
		ft_work_uint_left(pf);
	else
		ft_work_uint_wpad(pf);
	free(pf->output);
	if (pf->arg.neg == 1)
		free(--pf->tmp);
	else
		free(pf->tmp);
	pf->str_i++;
}
