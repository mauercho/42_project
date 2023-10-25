/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:27:37 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 19:39:14 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limit(long long result, int *check, int sign)
{
	if (sign == 1)
	{
		if (result > MAX_INT)
		{
			*check = 1;
			return (0);
		}
	}
	else if (sign == -1)
	{
		if (result * sign < MIN_INT)
		{
			*check = 1;
			return (0);
		}
	}
	return (1);
}

static void	check_sign(char *s, int *sign, int *check, int *i)
{
	int	idx;

	idx = 0;
	if (s[idx] == '+' || s[idx] == '-')
	{
		if (s[idx] == '-')
			*sign = -1;
		(*i)++;
		if (s[1] == 0)
			*check = 1;
	}
}

static int	atoi_and_parse(char *s, int *check)
{
	int			i;
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	i = 0;
	check_sign(s, &sign, check, &i);
	while (s[i] != 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + s[i] - '0';
		else
			*check = 1;
		i++;
		if (*check == 1 || !check_limit(result, check, sign))
			return (0);
	}
	return (result * sign);
}

void	parsing(char **str, t_dblist *a)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (str[i] != 0)
	{
		insert_list_tail(a, atoi_and_parse(str[i], &check));
		if (check == 1)
		{
			free_stack(a);
			make_free(str);
			error_make();
		}
		i++;
	}
	if (check_overlap(a))
	{
		free_stack(a);
		make_free(str);
		error_make();
	}
	make_free(str);
}
