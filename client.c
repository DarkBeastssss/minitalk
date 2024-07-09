/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:06:48 by amecani           #+#    #+#             */
/*   Updated: 2024/03/25 18:59:53 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	singnalin(int pid, char *string)
{
	unsigned char	kar;
	int				i;

	i = 0;
	while (*string)
	{
		kar = *string;
		while (i != 8)
		{
			if (kar & 0x80)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			kar <<= 1;
			i++;
		}
		i = 0;
		string++;
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_atoi(argv[1]))
	{
		ft_printf("Gimmie : PID aaaand STR\n");
		return (0);
	}
	singnalin(ft_atoi(argv[1]), (argv[2]));
	return (0);
}
