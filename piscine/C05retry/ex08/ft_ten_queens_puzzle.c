/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:30:00 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/22 12:49:31 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_condition(int *row, int *diagonal1, int *diagonal2)
{
	if (*row == 0 && *diagonal1 == 0 && *diagonal2 == 0)
		return (1);
	else
		return (0);
}

void	put_arr(int *arr1, int *arr2, int *arr3, int num)
{
	*arr1 = num;
	*arr2 = num;
	*arr3 = num;
}

void	write_arr(char *arr, int *cnt)
{
	write(1, arr, 10);
	write(1, "\n", 1);
	*cnt += 1;
}

void	set(int i, int *cnt, char *arr)
{
	int			j;
	static int	row[10];
	static int	diagonal1[19];
	static int	diagonal2[19];

	j = 0;
	while (j < 10)
	{
		if (check_condition(&row[j], &diagonal1[i + j], &diagonal2[i - j + 9]))
		{
			arr[i] = j + '0';
			if (i == 9)
			{
				write_arr(arr, cnt);
			}
			else
			{
				put_arr(&row[j], &diagonal1[i + j], &diagonal2[i - j + 9], 1);
				set(i + 1, cnt, arr);
				put_arr(&row[j], &diagonal1[i + j], &diagonal2[i - j + 9], 0);
			}
		}
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		cnt;
	char	arr[10];

	cnt = 0;
	set(0, &cnt, arr);
	return (cnt);
}
