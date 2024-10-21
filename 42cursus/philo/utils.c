/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:02:09 by minwucho          #+#    #+#             */
/*   Updated: 2023/12/19 15:00:59 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *s)
{
	printf("%s \n", s);
	return (FALSE);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		print_error("gettimeofday error");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	check_limit(long long num, int minus)
{
	int	check;

	if (minus == 1)
	{
		if (num > MAXINT)
			return (print_error("MAX INT ERROR"));
	}
	else
	{
		if (num * -1 < MININT)
			return (print_error("MIN INT ERROR"));
	}
	return (TRUE);
}

int	ft_atoi(const char *str)
{
	int				idx;
	int				minus;
	long long		num;

	num = 0;
	minus = 1;
	idx = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + str[idx] - '0';
		if (check_limit(num, minus) == FALSE)
			return (FALSE);
		idx++;
	}
	if (check_limit(num, minus) == FALSE)
		return (FALSE);
	return (minus * (int)num);
}
