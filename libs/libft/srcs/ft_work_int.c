/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:19 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:21:07 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_work_int_zero(t_printf *pf)
{
	char	*onesec;
	int		len;
	char	*tmp;

	if (pf->arg.neg == 1)
		pf->ret += write(1, "-", 1);
	else if ((pf->arg.neg == 0) && (pf->arg.plus == 1 || pf->arg.sp == 1))
		pf->ret += (pf->arg.plus == 1 ? write(1, "+", 1) : write(1, " ", 1));
	if (pf->arg.g_width == 1 && (pf->arg.width > (int)ft_strlen(pf->output)))
	{
		len = pf->arg.width - (int)ft_strlen(pf->output);
		if (pf->arg.neg == 1 || pf->arg.plus == 1 || pf->arg.sp == 1)
			len -= 1;
		onesec = (char*)malloc(sizeof(char) * (len + 1));
		ft_memset(onesec, '0', len);
		onesec[len] = '\0';
		tmp = ft_strjoin(onesec, pf->output);
		free(pf->output);
		pf->output = tmp;
		free(onesec);
	}
	ft_putstr(pf->output);
	pf->ret += (int)ft_strlen(pf->output);
}

void	ft_work_int_left(t_printf *pf)
{
	int		i;

	if (pf->arg.neg == 1)
		pf->ret += write(1, "-", 1);
	else if ((pf->arg.neg == 0) && (pf->arg.plus == 1 || pf->arg.sp == 1))
		pf->ret += (pf->arg.plus == 1 ? write(1, "+", 1) : write(1, " ", 1));
	ft_putstr(pf->output);
	pf->ret += (int)ft_strlen(pf->output);
	i = -1;
	if (pf->arg.g_width == 1 && (pf->arg.width > (int)ft_strlen(pf->output)))
	{
		if (pf->arg.neg == 1 || pf->arg.plus == 1 || pf->arg.sp == 1)
			while (++i < (pf->arg.width - (int)ft_strlen(pf->output) - 1))
				pf->ret += write(1, " ", 1);
		else
			while (++i < (pf->arg.width - (int)ft_strlen(pf->output)))
				pf->ret += write(1, " ", 1);
	}
}

void	ft_work_int_wpad(t_printf *pf)
{
	int		i;
	int		wpad;

	i = 0;
	if (pf->arg.width > (int)ft_strlen(pf->output))
	{
		wpad = pf->arg.width - (int)ft_strlen(pf->output);
		if (pf->arg.neg == 1 || pf->arg.plus == 1 || pf->arg.sp == 1)
			wpad -= 1;
		while (i < wpad)
		{
			pf->ret += write(1, " ", 1);
			i++;
		}
	}
	if (pf->arg.neg == 1)
		pf->ret += write(1, "-", 1);
	else if ((pf->arg.neg == 0) && (pf->arg.plus == 1 || pf->arg.sp == 1))
		pf->ret += (pf->arg.plus == 1 ? write(1, "+", 1) : write(1, " ", 1));
	ft_putstr(pf->output);
	pf->ret += (int)ft_strlen(pf->output);
}

int		ft_set_iprec_prep(t_printf *pf)
{
	int		length;

	length = (int)ft_strlen(pf->tmp);
	if (pf->tmp[0] == '-')
	{
		pf->arg.neg = 1;
		length -= 1;
		pf->tmp++;
	}
	return (length);
}
