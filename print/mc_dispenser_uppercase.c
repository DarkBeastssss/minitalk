/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MC_Dispenser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:54:25 by amecani           #+#    #+#             */
/*   Updated: 2023/12/07 17:55:54 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstring(char *str)
{
	int	l;
	int	check;

	if (str == NULL)
		return (write(1, "(null)", 6));
	l = 0;
	while (*str)
	{
		check = ft_putchar(*str);
		if (check == -1)
			return (-1);
		l += check;
		str++;
	}
	return (l);
}

int	ft_putnbr(long n)
{
	int		count;
	long	check;

	count = 0;
	if (n < 0)
	{
		check = write(1, "-", 1);
		if (check == -1)
			return (-1);
		count += check;
		n = -n;
	}
	if (n / 10 > 0)
	{
		check = ft_putnbr(n / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = n % 10 + '0';
	check = write(1, &(check), 1);
	if (check == -1)
		return (-1);
	return (count + (int) check);
}

int	ft_unsigned(unsigned int n)
{
	int		count;
	int		check;
	char	o;

	count = 0;
	if (n / 10 > 0)
	{
		check = ft_unsigned(n / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	o = n % 10 + '0';
	check = write(1, &o, 1);
	if (check == -1)
		return (-1);
	return (count + check);
}
