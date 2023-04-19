/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:40:45 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/09 20:04:07 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char first, char second, char third)
{
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	print_789(void)
{
	write(1, "7", 1);
	write(1, "8", 1);
	write(1, "9", 1);
}

void	ft_print_comb(void)
{
	char	first_num;
	char	second_num;
	char	third_num;

	first_num = '0';
	while (first_num <= '6' )
	{
		second_num = first_num + 1;
		while (second_num <= '8' )
		{
			third_num = second_num + 1;
			while (third_num <= '9' )
			{	
				ft_print(first_num, second_num, third_num);
				third_num++;
			}
			second_num++;
		}
		first_num++;
	}
	print_789();
}
