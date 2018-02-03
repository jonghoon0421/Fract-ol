/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:13:40 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:22:40 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_length(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	int num;
	int neg;

	neg = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == 45)
	{
		neg = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str <= 57 && *str >= 48)
	{
		num *= 10;
		num += *str - 48;
		str++;
	}
	return (num *= neg);
}

char	*ft_itoa(int n)
{
	char	*conv;
	int		leng;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	leng = ft_find_length(n);
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	if (n < 0)
	{
		conv[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		conv[--leng] = (n % 10) + 48;
		n /= 10;
	}
	conv[--leng] = n + 48;
	return (conv);
}

char	*ft_uitoa(unsigned int n)
{
	char			*conv;
	int				leng;
	unsigned int	nbr;

	nbr = n;
	leng = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		leng++;
	}
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	while (n > 9)
	{
		conv[--leng] = (n % 10) + 48;
		n /= 10;
	}
	conv[--leng] = n + 48;
	return (conv);
}

char	*ft_ultoa_base(unsigned long n, int base)
{
	char			*conv;
	int				leng;
	unsigned long	nbr;
	char			base_str[16];

	ft_strcpy(base_str, "0123456789abcdef");
	nbr = n;
	leng = 1;
	while (nbr >= (unsigned long)base)
	{
		nbr /= (unsigned long)base;
		leng++;
	}
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	while (leng > 0)
	{
		conv[--leng] = base_str[n % (unsigned long)base];
		n /= (unsigned long)base;
	}
	return (conv);
}
