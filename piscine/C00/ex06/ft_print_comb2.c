/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:11:46 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/10 10:57:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number_string(int first, int second)
{
	char	for_first_number;
	char	for_second_number;

	for_first_number = first / 10 + '0';
	write(1, &for_first_number, 1);
	for_first_number = first % 10 + '0';
	write(1, &for_first_number, 1);
	write(1, " ", 1);
	for_second_number = second / 10 + '0';
	write(1, &for_second_number, 1);
	for_second_number = second % 10 + '0';
	write(1, &for_second_number, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb2(void)
{
	int	first_num;
	int	second_num;

	first_num = 0;
	while (first_num < 98)
	{
		second_num = first_num + 1;
		while (second_num <= 99)
		{
			print_number_string(first_num, second_num);
			second_num++;
		}
		first_num++;
	}
	write(1, "98 99", 5);
	return ;
}
