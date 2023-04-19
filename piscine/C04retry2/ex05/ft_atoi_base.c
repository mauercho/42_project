/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:48:32 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/19 21:36:05 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
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

int	check(char alpha, char *base)
{
	int	length;
	int	idx_base;

	idx_base = 0;
	length = 0;
	while (base[length] != 0)
		length++;
	while (idx_base < length)
	{
		if (base[idx_base] == alpha)
			return (idx_base);
		idx_base++;
	}
	return (-1);
}

int	return_idx(char *str, int *minus)
{
	int	idx;

	idx = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			*minus *= -1;
		idx++;
	}
	return (idx);
}

int	ft_atoi_base(char *str, char *base)
{
	int			length;
	int			idx;
	int			count_minus;
	long long	num;

	num = 0;
	count_minus = 1;
	idx = 0;
	length = 0;
	while (base[length] != 0)
		length++;
	if (check_base(base) == 0)
		return (0);
	idx = return_idx(str, &count_minus);
	while (check(str[idx], base) != -1)
	{
		if (num == 0)
			num += check(str[idx], base);
		else
			num = num * length + check(str[idx], base);
		idx++;
	}
	return (count_minus * num);
}
