/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:58:39 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/03 12:03:30 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_func(int signal)
{
	static int	bit;
	static char	alpha;

	if (signal == SIGUSR1)
		alpha = alpha | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(alpha, 1);
		bit = 0;
		alpha = 0;
	}
}

static void	ft_pid_print(pid_t pid)
{
	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" \n", 1);
	ft_putstr_fd("Waiting for client input\n", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_pid_print(pid);
	signal(SIGUSR1, handler_func);
	signal(SIGUSR2, handler_func);
	while (1)
		pause();
	return (0);
}
