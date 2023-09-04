/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:30:20 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/03 12:13:35 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(pid_t pid, char alpha)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((alpha & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

static void	send_str(pid_t pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		send_char(pid, str[i]);
	}
	send_char(pid, '\n');
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3 && argv[2][0] != 0)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 99998)
		{
			ft_putstr_fd("Wrong PID!!!\n", 1);
			return (0);
		}
		send_str(pid, argv[2]);
	}
	else
	{
		ft_putstr_fd("Wrong Format!!!\n", 1);
	}
	return (0);
}
