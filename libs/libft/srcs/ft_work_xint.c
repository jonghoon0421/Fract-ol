/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_xint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:39:48 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:21:46 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_work_xint_zero_part2(t_printf *pf, int length)
{
	char	*onesec;
	char	*tmp;

	if (pf->arg.g_width == 1 && (pf->arg.width > (int)ft_strlen(pf->output)))
	{
		if (pf->arg.hash == 1 && (pf->arg.type == 'o' || pf->arg.type == 'O'))
			length -= 1;
		else if (pf->arg.hash == 1 &&
				(pf->arg.type == 'x' || pf->arg.type == 'X'))
			length -= 2;
		onesec = (char*)malloc(sizeof(char) * (length + 1));
		ft_memset(onesec, '0', length);
		onesec[length] = '\0';
		tmp = ft_strjoin(onesec, pf->output);
		free(pf->output);
		pf->output = tmp;
		free(onesec);
	}
	ft_putstr(pf->output);
	pf->ret += (int)ft_strlen(pf->output);
}

void	ft_work_xint_zero(t_printf *pf)
{
	int		len;

	(pf->arg.hash == 1 && pf->unum != 0) ? ft_set_xint_hash(pf) : 0;
	if (pf->arg.hash == 1 && pf->unum == 0 && (pf->arg.type == 'o' ||
				pf->arg.type == 'O'))
	{
		free(pf->output);
		pf->output = ft_strdup("0");
	}
	len = pf->arg.width - (int)ft_strlen(pf->output);
	ft_work_xint_zero_part2(pf, len);
}

void	ft_work_xint_left(t_printf *pf)
{
	int		i;
	int		len;

	i = -1;
	(pf->arg.hash == 1 && pf->unum != 0) ? ft_set_xint_hash(pf) : 0;
	if (pf->arg.hash == 1 && pf->unum == 0 && (pf->arg.type == 'o' ||
				pf->arg.type == 'O'))
	{
		free(pf->output);
		pf->output = ft_strdup("0");
	}
	ft_putstr(pf->output);
	pf->ret += (int)ft_strlen(pf->output);
	len = pf->arg.width - (int)ft_strlen(pf->output);
	if (pf->arg.hash == 1 && (pf->arg.type == 'o' || pf->arg.type == 'O'))
		len -= 1;
	else if (pf->arg.hash == 1 &&
			(pf->arg.type == 'x' || pf->arg.type == 'X'))
		len -= 2;
	if (pf->arg.g_width == 1 && (pf->arg.width > (int)ft_strlen(pf->output)))
		while (++i < len)
			pf->ret += write(1, " ", 1);
}

void	ft_work_xint_wpad(t_printf *pf)
{
	int		i;
	int		len;

	i = -1;
	len = pf->arg.width - (int)ft_strlen(pf->output);
	if (pf->arg.hash == 1 && (pf->arg.type == 'o' || pf->arg.type == 'O'))
		len -= 1;
	else if (pf->arg.hash == 1 &&
			(pf->arg.type == 'x' || pf->arg.type == 'X'))
		len -= 2;
	if (pf->arg.g_width == 1 && (pf->arg.width > (int)ft_strlen(pf->output)))
		while (++i < len)
			pf->ret += write(1, " ", 1);
	(pf->arg.hash == 1 && pf->unum != 0) ? ft_set_xint_hash(pf) : 0;
	if (pf->arg.hash == 1 && pf->unum == 0 && (pf->arg.type == 'o' ||
				pf->arg.type == 'O'))
	{
		free(pf->output);
		pf->output = ft_strdup("0");
	}
	ft_putstr(pf->output);
	pf->ret += (int)ft_strlen(pf->output);
}
