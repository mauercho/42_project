/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:06:01 by minwucho          #+#    #+#             */
/*   Updated: 2023/09/30 21:14:52 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	check_integer(int *i, char *str, double *result)
{
	int	idx;

	idx = *i;
	if (str[idx] == '2' || str[idx] == '1' || str[idx] == '0')
	{
		(*i) += 1;
		*result += str[idx] - '0';
	}
	else
		manual();
}

static void	check_dot(int *i, char *str)
{
	int	idx;

	idx = *i;
	if (str[idx] == 0)
		return ;
	else if (str[idx] != '.')
		manual();
	(*i)++;
}

static void	check_float(int *i, char *str, double *result)
{
	double	pow_num;
	int		idx;

	idx = *i;
	pow_num = 1;
	while (pow_num <= MAX_FLOATING_POINT)
	{
		if (str[idx] >= '0' && str[idx] <= '9')
		{
			*result += ((str[idx] - '0') * pow(0.1, pow_num));
			idx++;
			if (*result > 2 || *result < -2)
				manual();
		}
		else if (str[idx] == 0)
		{
			return ;
		}
		else
			manual();
		pow_num++;
	}
	if (str[idx] != 0)
		manual();
}

double	check_and_atod(char *str)
{
	int			i;
	int			sign;
	double		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	check_integer(&i, str, &result);
	check_dot(&i, str);
	check_float(&i, str, &result);
	return (result * sign);
}
