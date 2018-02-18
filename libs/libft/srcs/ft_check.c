/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:53:22 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:24:21 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_bflag(const char *format, t_printf *pf)
{
	if (format[pf->str_i] == '#')
		pf->arg.hash = 1;
	if (format[pf->str_i] == '0')
		pf->arg.zero = (pf->arg.minus == 1 ? 0 : 1);
	if (format[pf->str_i] == '-')
	{
		pf->arg.minus = 1;
		pf->arg.zero = 0;
	}
	if (format[pf->str_i] == '+')
		pf->arg.plus = 1;
	if (format[pf->str_i] == ' ')
		pf->arg.sp = 1;
	ft_strchr(CHECK_FLAG, format[pf->str_i]) != NULL ? pf->str_i++ : 0;
}

void	ft_check_enum(const char *format, t_printf *pf)
{
	if (format[pf->str_i] == 'h' && format[pf->str_i + 1] != 'h')
		pf->arg.lmod = (pf->arg.lmod > pf_h ? pf->arg.lmod : pf_h);
	else if (format[pf->str_i] == 'h' && format[pf->str_i + 1] == 'h')
	{
		pf->arg.lmod = (pf->arg.lmod > pf_hh ? pf->arg.lmod : pf_hh);
		pf->str_i++;
	}
	else if (format[pf->str_i] == 'l' && format[pf->str_i + 1] != 'l')
		pf->arg.lmod = (pf->arg.lmod > pf_l ? pf->arg.lmod : pf_l);
	else if (format[pf->str_i] == 'l' && format[pf->str_i + 1] == 'l')
	{
		pf->arg.lmod = (pf->arg.lmod > pf_ll ? pf->arg.lmod : pf_ll);
		pf->str_i++;
	}
	else if (format[pf->str_i] == 'j')
		pf->arg.lmod = (pf->arg.lmod > pf_j ? pf->arg.lmod : pf_j);
	else if (format[pf->str_i] == 'z')
		pf->arg.lmod = (pf->arg.lmod > pf_z ? pf->arg.lmod : pf_z);
}

void	ft_check_flag_prec(const char *format, t_printf *pf)
{
	if (!(format[pf->str_i + 1] >= '0' && format[pf->str_i + 1] <= '9') &&
			format[pf->str_i + 1] != '*')
	{
		pf->arg.g_prec = 1;
		pf->str_i++;
	}
	else if (format[pf->str_i + 1] == '*')
		ft_asterisk_prec(pf);
	else
	{
		pf->arg.prec = ft_atoi(&format[pf->str_i + 1]);
		pf->str_i += ft_find_length(pf->arg.prec) + 1;
		if (format[pf->str_i] == '.')
		{
			pf->arg.prec = 0;
			pf->arg.g_prec = 0;
		}
		else
			pf->arg.g_prec = 1;
	}
}

void	ft_check_flag(const char *format, t_printf *pf)
{
	while ((ft_strchr(CHECK_VALID, format[pf->str_i]) != NULL) &&
			format[pf->str_i] != '\0')
	{
		ft_check_bflag(format, pf);
		if (ft_strchr(CHECK_NUM, format[pf->str_i]) != NULL &&
				format[pf->str_i - 1] != '.' && format[pf->str_i] != '\0')
		{
			pf->arg.width = ft_atoi(&format[pf->str_i]);
			pf->str_i += ft_find_length(pf->arg.width);
			pf->arg.g_width = 1;
		}
		if (format[pf->str_i] == '.')
			ft_check_flag_prec(format, pf);
		if (ft_strchr(CHECK_ENUM, format[pf->str_i]) != NULL &&
				format[pf->str_i] != '\0')
		{
			ft_check_enum(format, pf);
			pf->str_i += 1;
			pf->arg.g_lmod = 1;
		}
		if (format[pf->str_i] == '*')
			ft_asterisk_width(pf);
	}
}

void	ft_check_type(const char *format, t_printf *pf)
{
	if (format[pf->str_i] == 'd' || format[pf->str_i] == 'i' ||
			format[pf->str_i] == 'D')
		ft_set_int(format, pf);
	else if (format[pf->str_i] == 'u' || format[pf->str_i] == 'U')
		ft_set_uint(format, pf);
	else if ((format[pf->str_i] == 'c' || format[pf->str_i] == 's') &&
			pf->arg.lmod != pf_l)
		ft_set_lcs(format, pf);
	else if (format[pf->str_i] == 'C' || format[pf->str_i] == 'S')
		ft_set_lcs(format, pf);
	else if (format[pf->str_i] == 'C' || format[pf->str_i] == 'S' ||
			((format[pf->str_i] == 'c' || format[pf->str_i] == 's') &&
			pf->arg.lmod == pf_l))
		ft_set_wcs(format, pf);
	else if (ft_strchr(CHECK_OCTHEX, format[pf->str_i]) != NULL)
		ft_set_xint(format, pf);
	else if (format[pf->str_i] == 'p')
		ft_set_ptraddr(format, pf);
	else if (format[pf->str_i] == '%')
		ft_set_percent(pf);
	else
		ft_set_general(format, pf);
}
