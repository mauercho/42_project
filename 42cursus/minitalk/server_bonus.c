/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:32:57 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/03 12:03:41 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_func(int signal, siginfo_t *pidinfo, void *a)
{
	static int	bit;
	static char	alpha;
	pid_t		pid;

	(void)a;
	pid = pidinfo->si_pid;
	if (signal == SIGUSR1)
		alpha = alpha | (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (alpha == 0)
			kill(pid, SIGUSR1);
		else
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
	pid_t				pid;
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &handler_func;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_pid_print(pid);
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
