/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:19:09 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:18:25 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_parse(const char *format, t_printf *pf)
{
	int		len;

	len = (int)ft_strlen(format);
	pf->str_i++;
	ft_init_arg(pf);
	ft_check_flag(format, pf);
	if (len > pf->str_i)
		ft_check_type(format, pf);
	else
		return ;
}

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	va_start(pf.ap, format);
	while (format[pf.str_i] != '\0')
	{
		if (format[pf.str_i] == '%')
			ft_printf_parse(format, &pf);
		else
		{
			pf.ret += write(1, &format[pf.str_i], 1);
			pf.str_i++;
		}
	}
	va_end(pf.ap);
	return (pf.ret);
}
