/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:06:13 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/19 12:02:40 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != 0 && s2[idx] != 0)
	{
		if (s1[idx] != s2[idx])
		{
			return (s1[idx] - s2[idx]);
		}
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

void	ft_print(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		write(1, &str[idx], 1);
		idx++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		cal_num;
	int		idx;
	char	*temp;

	cal_num = argc - 2;
	while (cal_num > 0)
	{
		idx = 0;
		while (idx < cal_num)
		{
			if (ft_strcmp(argv[idx + 1], argv[idx + 2]) > 0)
			{
				temp = argv[idx + 1];
				argv[idx + 1] = argv[idx + 2];
				argv[idx + 2] = temp;
			}
			idx++;
		}
		cal_num--;
	}
	idx = 1;
	while (idx < argc)
		ft_print(argv[idx++]);
	return (0);
}
