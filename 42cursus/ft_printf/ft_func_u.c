/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:13:05 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/24 12:06:15 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	loop_unint(unsigned int nbr, char *base)
{
	if (nbr < 10)
	{
		if (write(1, &base[nbr], 1) == -1)
			return (-1);
	}
	else
	{
		if (loop_unint(nbr / 10, base) == -1)
			return (-1);
		if (write(1, &base[nbr % 10], 1) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_putnbr_unint(unsigned int nbr)
{
	char			*base;
	unsigned int	num;
	int				cnt;

	cnt = 1;
	base = "0123456789";
	num = nbr;
	if (loop_unint(num, base) == -1)
		return (-1);
	while (num >= 10)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

int	printu(va_list ap)
{
	unsigned int	num;
	int				cnt;

	num = (unsigned int)va_arg(ap, int);
	cnt = ft_putnbr_unint(num);
	if (cnt == -1)
		return (-1);
	return (cnt);
}
