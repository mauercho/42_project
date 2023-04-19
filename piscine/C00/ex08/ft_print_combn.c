/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:32:38 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/15 10:00:05 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_arr(char *arr, int length)
{
	int	idx;

	idx = 0;
	write(1, ", ", 2);
	while (idx < length)
	{
		write(1, &arr[idx], 1);
		idx++;
	}
}

void	print_first_arr(int length)
{
	int		idx;
	char	num;

	idx = 0;
	while (idx < length)
	{
		num = idx + '0';
		write(1, &num, 1);
		idx++;
	}
}

void	make_start_arr(char *arr, int length)
{
	int	idx;

	idx = 0;
	while (idx < length)
	{
		arr[idx] = idx + '0';
		idx++;
	}
}

void	make_max_arr(char *arr, int length)
{
	int	idx;

	idx = 0;
	while (idx < length)
	{
		arr[idx] = 10 + idx - length + '0';
		idx++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];
	char	max_arr[10];
	int		idx;
	int		ref;
	int		check;

	if (!(n > 0 && n < 10))
		return ;
	idx = 0;
	make_start_arr(arr, n);
	make_max_arr(max_arr, n);
	print_first_arr(n);
	while (arr[0] != max_arr[0])
	{
		ref = n - 1;
		while (arr[ref] == max_arr[ref])
			ref--;
		check = ++arr[ref];
		while (ref < n - 1)
			arr[++ref] = ++check;
		print_arr(arr, n);
	}
}
