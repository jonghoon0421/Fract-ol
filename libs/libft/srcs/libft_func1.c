/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:55:35 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/09 18:22:26 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)str;
	while (n-- > 0)
		*tmp++ = (unsigned char)c;
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	char	*tmp;

	while (*str)
	{
		if (*str == c)
		{
			tmp = (char*)str;
			return (tmp);
		}
		str++;
	}
	if (c == '\0')
	{
		tmp = (char*)str;
		return (tmp);
	}
	return (NULL);
}
