/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:10:08 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/24 11:46:44 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	loop_ten(int nbr, char *base)
{
	if (nbr < 10)
	{
		if (write(1, &base[nbr], 1) == -1)
			return (-1);
	}
	else
	{
		if (loop_ten(nbr / 10, base) == -1)
		{
			return (-1);
		}
		if (write(1, &base[nbr % 10], 1) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_putnbr_ten(int nbr, int minus)
{
	char	*base;
	int		num;
	int		cnt;

	cnt = 1;
	if (minus == -1)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	num = minus * nbr;
	base = "0123456789";
	if (loop_ten(num, base) == -1)
		return (-1);
	while (num >= 10)
	{
		num /= 10;
		cnt++;
	}
	if (minus == -1)
		return (cnt + 1);
	return (cnt);
}

int	printd(va_list ap)
{
	int	num;
	int	minus;
	int	cnt;
	int	chk;

	chk = 0;
	minus = 1;
	num = (int)va_arg(ap, int);
	if (num == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (num < 0)
		minus = -1;
	cnt = ft_putnbr_ten(num, minus);
	if (cnt == -1)
		return (-1);
	return (cnt);
}
