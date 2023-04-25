/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:37:32 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/24 11:39:31 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	loop_add(unsigned long long num, char *base)
{
	if (num < (unsigned long long)ft_strlen(base))
		write(1, &base[num], 1);
	else
	{
		loop_add(num / ft_strlen(base), base);
		write(1, &base[num % ft_strlen(base)], 1);
	}
}

static int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long	num;
	int					cnt;

	num = nbr;
	cnt = 1;
	loop_add(num, base);
	while (num >= (unsigned long long)ft_strlen(base))
	{
		num /= ft_strlen(base);
		cnt++;
	}
	return (cnt);
}

int	printp(va_list ap)
{
	void	*arg;
	int		cnt;

	arg = (void *)va_arg(ap, char *);
	if (write(1, "0x", 2) < 0)
	{
		return (-1);
	}
	cnt = ft_putnbr_base((unsigned long long)arg, "0123456789abcdef");
	return (cnt + 2);
}
