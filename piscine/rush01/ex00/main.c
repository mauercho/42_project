/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:18:00 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/19 21:40:43 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		check(char *str);
int		*numbers_get(char *str);
int		check_arg(int num, char *str);
void	show_solution(int matrix[4][4]);

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}

int	check(char *str)
{
	int	length;
	int	idx;

	idx = 0;
	length = ft_strlen(str);
	if (length != 31)
		return (1);
	while (str[idx] != 0)
	{
		if (idx % 2 == 0)
		{
			if (!(str[idx] >= '1' && str[idx] <= '4'))
				return (1);
		}
		else
		{
			if (str[idx] != ' ')
				return (1);
		}
		idx++;
	}
	return (0);
}

int	*numbers_get(char *str)
{
	int	*num_arr;
	int	idx;
	int	idx_num;

	idx_num = 0;
	idx = 0;
	while (str[idx] != 0)
	{
		if (idx % 2 == 0)
		{
			num_arr[idx_num] = str[idx] - '0';
			idx_num++;
		}
		idx++;
	}
	return (num_arr);
}

void	show_solution(int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &matrix[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	check_arg(int num, char *str)
{
	if (num != 2)
		return (0);
	if (check(str))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	matrix[4][4];
	int	arr1d[16];
	int	i;
	int	j;

	if (check_arg(argc, argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	arr1d = numbers_get(argv[1]);
	return (0);
}
