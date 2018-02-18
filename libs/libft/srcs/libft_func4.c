/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 22:37:48 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:22:48 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long n)
{
	char			*conv;
	int				leng;
	unsigned long	nbr;

	leng = 1;
	nbr = n;
	while (nbr > 9)
	{
		nbr /= 10;
		leng++;
	}
	conv = (char*)malloc(sizeof(char) * (leng + 1));
	conv[leng] = '\0';
	while (n > 9)
	{
		conv[--leng] = (n % 10) + 48;
		n /= 10;
	}
	conv[--leng] = n + 48;
	return (conv);
}

char	*ft_uitoa_base(unsigned int n, int base)
{
	char			*conv;
	int				leng;
	unsigned int	nbr;
	char			base_str[16];

	ft_strcpy(base_str, "0123456789abcdef");
	nbr = n;
	leng = 1;
	while (nbr >= (unsigned int)base)
	{
		nbr /= (unsigned int)base;
		leng++;
	}
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	while (leng > 0)
	{
		conv[--leng] = base_str[n % (unsigned int)base];
		n /= (unsigned int)base;
	}
	return (conv);
}

char	*ft_uitoa_base_cap(unsigned int n, int base)
{
	char			*conv;
	int				leng;
	unsigned int	nbr;
	char			base_str[16];

	ft_strcpy(base_str, "0123456789ABCDEF");
	nbr = n;
	leng = 1;
	while (nbr >= (unsigned int)base)
	{
		nbr /= (unsigned int)base;
		leng++;
	}
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	while (leng > 0)
	{
		conv[--leng] = base_str[n % (unsigned int)base];
		n /= (unsigned int)base;
	}
	return (conv);
}

char	*ft_ltoa(long n)
{
	char	*conv;
	long	nbr;
	int		leng;

	leng = 1;
	n < 0 ? ++leng : 0;
	nbr = n < 0 ? -n : n;
	if (nbr == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	while (nbr > 9)
	{
		nbr /= 10;
		++leng;
	}
	conv = (char*)malloc(sizeof(char) * (leng + 1));
	conv[leng] = '\0';
	n < 0 ? *conv = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n > 9)
	{
		conv[--leng] = (n % 10) + 48;
		n /= 10;
	}
	conv[--leng] = n + 48;
	return (conv);
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
