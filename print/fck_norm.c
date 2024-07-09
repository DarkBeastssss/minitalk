/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fck_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:15:46 by amecani           #+#    #+#             */
/*   Updated: 2023/12/07 18:13:17 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*save_point;

	c = c % 256;
	save_point = NULL;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == c)
			return (save_point = (char *)s);
		s++;
	}
	return (0);
}

long long int	ft_x(unsigned long long int location)
{
	char					*hexa_libary;
	char					empty;
	unsigned long long int	temp_l;
	unsigned long long int	l;

	l = 0;
	if (location == 0)
		return (ft_putchar('0'));
	temp_l = location;
	hexa_libary = "0123456789abcdef";
	empty = (hexa_libary[location % 16]);
	location = location / 16;
	while (temp_l)
	{
		temp_l = temp_l / 16;
		l++;
	}
	if (location)
		ft_x(location);
	ft_putchar(empty);
	return (l);
}

long long int	ft_xx(unsigned long long int location)
{
	char					*hexa_libary;
	char					empty;
	unsigned long long int	temp_l;
	unsigned long long int	l;

	l = 0;
	if (location == 0)
		return (ft_putchar('0'));
	temp_l = location;
	hexa_libary = "0123456789ABCDEF";
	empty = (hexa_libary[location % 16]);
	location = location / 16;
	while (temp_l)
	{
		temp_l = temp_l / 16;
		l++;
	}
	if (location)
		ft_xx(location);
	ft_putchar(empty);
	return (l);
}

long long int	ft_p(unsigned long long int p)
{
	unsigned long long int	count;
	int						flag;

	flag = 0;
	flag = write(1, "0x", 2);
	if (flag == -1)
		return (-1);
	count = 2;
	if (p == 0)
	{
		flag = ft_putchar('0');
		if (flag == -1)
			return (-1);
		return (count + flag);
	}
	flag = ft_x(p);
	if (flag == -1)
		return (-1);
	return (count + flag);
}
		// return (flag++);
