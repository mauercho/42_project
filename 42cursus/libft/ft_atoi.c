/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:27:07 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/31 16:00:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				idx;
	int				minus;
	unsigned int	num;

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
		idx++;
	}
	if (minus == -1 && num > 2147483648)
		return (0);
	if (minus == 1 && num > 2147483647)
		return (-1);
	return (minus * num);
}
