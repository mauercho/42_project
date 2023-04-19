/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:19:46 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/12 22:13:53 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int row, int col);

int	main(void)
{
	rush(3, 3);
	rush(0, 1);
	rush(5, -3);
	rush(10, 3);
	rush(1, 5);
	rush(5, 1);
	rush(2, 4);
	rush(1, 1);
	rush(2, 1);
	rush(50, 25);
	rush(5, 3);
	rush(5, 1);
	rush(1, 1);
	rush(1, 5);
	rush(4, 4);
	rush(-3, 5);
	return (0);
}
