/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_xi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:39:55 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:20:55 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_xint_hash(t_printf *pf)
{
	if (pf->arg.type == 'o' || pf->arg.type == 'O')
		pf->ret += write(1, "0", 1);
	else if (pf->arg.type == 'x' || pf->arg.type == 'X')
	{
		if (pf->arg.type == 'x')
			pf->ret += write(1, "0x", 2);
		else
			pf->ret += write(1, "0X", 2);
	}
}

void	ft_set_xiprec(t_printf *pf)
{
	int		length;
	int		siz;
	int		i;

	i = -1;
	length = (int)ft_strlen(pf->tmp);
	if (pf->tmp[0] == '0')
	{
		if (pf->arg.g_prec == 1)
			pf->output = ft_strnew(0);
		else
			pf->output = ft_strdup("0");
	}
	else if (pf->arg.prec > length)
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

void	ft_set_xint_lmod(t_printf *pf, int base)
{
	if (pf->arg.lmod == pf_h)
		pf->tmp = ft_ultoa_base((unsigned short)pf->unum, base);
	else if (pf->arg.lmod == pf_none)
		pf->tmp = ft_ultoa_base((unsigned int)pf->unum, base);
	else if (pf->arg.lmod == pf_hh)
		pf->tmp = ft_ultoa_base((unsigned char)pf->unum, base);
	else
		pf->tmp = ft_ultoa_base((unsigned long)pf->unum, base);
	ft_set_xiprec(pf);
}

void	ft_set_xint(const char *format, t_printf *pf)
{
	int		i;

	i = -1;
	pf->arg.type = format[pf->str_i];
	pf->unum = va_arg(pf->ap, unsigned long);
	if (pf->arg.type == 'o' || pf->arg.type == 'O')
		ft_set_xint_lmod(pf, 8);
	else if (pf->arg.type == 'x' || pf->arg.type == 'X')
	{
		ft_set_xint_lmod(pf, 16);
		if (pf->arg.type == 'X')
			while (pf->output[++i] != '\0')
				pf->output[i] = ft_toupper(pf->output[i]);
	}
	if (pf->arg.zero == 1)
		ft_work_xint_zero(pf);
	else if (pf->arg.minus == 1)
		ft_work_xint_left(pf);
	else
		ft_work_xint_wpad(pf);
	free(pf->output);
	free(pf->tmp);
	pf->str_i++;
}
