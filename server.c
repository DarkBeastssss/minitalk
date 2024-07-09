/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:07:25 by amecani           #+#    #+#             */
/*   Updated: 2024/03/25 19:20:38 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signalin(int sig)
{
	static int		bits;
	static int		i;
	unsigned char	c;

	bits <<= 1;
	if (sig == SIGUSR1)
		bits = bits | 1;
	i++;
	if (i == 8)
	{
		c = bits;
		write(1, &c, 1);
		bits = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, signalin);
	signal(SIGUSR2, signalin);
	while (1)
		pause();
	return (0);
}
