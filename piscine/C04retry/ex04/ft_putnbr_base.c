/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:18:03 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/19 12:46:52 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *base)
{
	int	length;
	int	idx;
	int	check_idx;

	idx = 0;
	length = 0;
	while (base[length] != 0)
		length++;
	if (length <= 1)
		return (0);
	while (base[idx] != 0)
	{
		check_idx = idx + 1;
		while (base[check_idx] != 0)
		{
			if (base[idx] == base[check_idx])
				return (0);
			check_idx++;
		}
		if (base[idx] == '+' || base[idx] == '-'
			|| (base[idx] >= 9 && base[idx] <= 13) || base[idx] == 32)
			return (0);
		idx++;
	}
	return (1);
}

void	loop_for_change(long long nbr, char *base, int length)
{
	if (nbr < length)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		loop_for_change(nbr / length, base, length);
		write(1, &base[nbr % length], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	long_num;
	int			idx;

	long_num = nbr;
	idx = 0;
	if (check(base) == 0)
		return ;
	while (base[idx] != 0)
		idx++;
	if (long_num < 0)
	{
		long_num *= -1;
		write(1, "-", 1);
	}
	loop_for_change(long_num, base, idx);
	return ;
}
