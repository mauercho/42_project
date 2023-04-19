/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:54:41 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/26 08:58:56 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

void	loop_for_change(long long nbr)
{
	char	*base;

	base = "0123456789";
	if (nbr < 10)
		write(1, &base[nbr], 1);
	else
	{
		loop_for_change(nbr / 10);
		write(1, &base[nbr % 10], 1);
	}
}

void	ft_putnbr_base(int nbr)
{
	long long	long_num;

	long_num = nbr;
	if (long_num < 0)
	{
		long_num *= -1;
		write(1, "-", 1);
	}
	loop_for_change(long_num);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while (par[idx].str != 0)
	{
		ft_putstr(par[idx].str);
		write(1, "\n", 1);
		ft_putnbr_base(par[idx].size);
		write(1, "\n", 1);
		ft_putstr(par[idx].copy);
		write(1, "\n", 1);
		idx++;
	}
	return ;
}
