/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:51:42 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 19:21:43 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
