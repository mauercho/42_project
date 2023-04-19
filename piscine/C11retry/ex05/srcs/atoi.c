/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:15 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/28 17:58:48 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int			idx;
	int			minus;
	long long	num;

	num = 0;
	minus = 1;
	idx = 0;
	while (is_space(str[idx]))
		idx++;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		if (num == 0)
			num = str[idx] - '0';
		else
			num = num * 10 + str[idx] - '0';
		idx++;
	}
	return (minus * num);
}
