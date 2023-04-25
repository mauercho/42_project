/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:21:13 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/24 12:10:24 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	loop_hexa(unsigned int nbr, char *base)
{
	if (nbr < 16)
	{
		if (write(1, &base[nbr], 1) == -1)
			return (-1);
	}
	else
	{
		if (loop_hexa(nbr / 16, base) == -1)
			return (-1);
		if (write(1, &base[nbr % 16], 1) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	unsigned int	num;
	int				cnt;

	cnt = 1;
	num = nbr;
	if (loop_hexa(nbr, base) == -1)
		return (-1);
	while (nbr >= 16)
	{
		nbr /= 16;
		cnt++;
	}
	return (cnt);
}

int	printx(va_list ap)
{
	char			*hexdown;
	unsigned int	num;
	int				cnt;

	hexdown = "0123456789abcdef";
	num = (unsigned int)va_arg(ap, int);
	cnt = ft_putnbr_hexa(num, hexdown);
	if (cnt == -1)
		return (-1);
	return (cnt);
}

int	printhexup(va_list ap)
{
	char			*hexup;
	unsigned int	num;
	int				cnt;

	hexup = "0123456789ABCDEF";
	num = (unsigned int)va_arg(ap, int);
	cnt = ft_putnbr_hexa(num, hexup);
	if (cnt == -1)
		return (-1);
	return (cnt);
}
