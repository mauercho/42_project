/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:36:49 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/12 09:43:09 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first(int row)
{
	int	row_cnt;

	row_cnt = 1;
	ft_putchar('/');
	while (row_cnt < row - 1)
	{
		ft_putchar('*');
		row_cnt++;
	}
	if (row_cnt == row - 1)
		ft_putchar('\\');
	ft_putchar('\n');
}

void	print_end(int row)
{
	int	row_cnt;

	row_cnt = 1;
	ft_putchar('\\');
	while (row_cnt < row - 1)
	{
		ft_putchar('*');
		row_cnt++;
	}
	if (row_cnt == row - 1)
		ft_putchar('/');
	ft_putchar('\n');
}

void	print_middle(int row)
{
	int	row_cnt;

	row_cnt = 1;
	ft_putchar('*');
	while (row_cnt < row - 1)
	{
		ft_putchar(' ');
		row_cnt++;
	}
	if (row_cnt == row - 1)
		ft_putchar('*');
	ft_putchar('\n');
}

void	rush(int row, int col)
{
	int	col_cnt;

	col_cnt = 1;
	if (row <= 0 || col <= 0)
		return ;
	if (col_cnt == 1)
	{
		print_first(row);
	}
	while (col_cnt < col - 1)
	{
		print_middle(row);
		col_cnt++;
	}
	if (col_cnt == col - 1)
		print_end(row);
}
