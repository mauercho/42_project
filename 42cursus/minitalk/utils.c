/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:31:19 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/01 18:31:34 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				idx;
	int				minus;
	unsigned int	num;

	num = 0;
	minus = 1;
	idx = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + str[idx] - '0';
		idx++;
	}
	if (minus == -1 && num > 2147483648)
		return (0);
	if (minus == 1 && num > 2147483647)
		return (-1);
	return (minus * num);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	loop(int nb, int fd)
{
	char	alpha;

	if (nb < 10)
	{
		alpha = nb + '0';
		write(fd, &alpha, 1);
	}
	else
	{
		loop(nb / 10, fd);
		alpha = nb % 10 + '0';
		write(fd, &alpha, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		loop(n, fd);
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(fd, &str[i], 1);
		i++;
	}
}
