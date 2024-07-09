/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:53 by amecani           #+#    #+#             */
/*   Updated: 2024/03/25 18:36:01 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "./print/ft_printf.h"

int		ft_atoi(const char *bomba);
void	singnalin(int pid, char *string);
void	signalin(int sig);
int		ft_atoi(const char *bomba);

#endif