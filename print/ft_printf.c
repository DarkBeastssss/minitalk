/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:44:23 by amecani           #+#    #+#             */
/*   Updated: 2023/12/07 15:34:49 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_finder(va_list args, const char skiaa)
{
	if (skiaa == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (skiaa == 's')
		return (ft_putstring(va_arg(args, char *)));
	if (skiaa == 'd' || skiaa == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (skiaa == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	if (skiaa == 'x')
		return (ft_x(va_arg(args, unsigned int)));
	if (skiaa == 'X')
		return (ft_xx(va_arg(args, unsigned int)));
	if (skiaa == 'p')
		return (ft_p(va_arg(args, unsigned long)));
	return (ft_putchar('%'));
}

int	ft_printf(const char *intput, ...)
{
	int		sa;
	int		i;
	va_list	args;

	i = 0;
	sa = 0;
	va_start(args, intput);
	while (intput[i] != '\0')
	{
		if (intput[i] == '%' && ft_strchr("cpdsiuxX%", intput[i + 1]))
			sa += specifier_finder(args, intput[i + 1]);
		if (intput[i] == '%' && ft_strchr("cpdsiuxX%", intput[i + 1]))
			i++;
		else
			sa += ft_putchar(intput[i]);
		if (sa < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (sa);
}
