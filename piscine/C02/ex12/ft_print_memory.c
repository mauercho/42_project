/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:40:49 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/21 10:50:29 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_loop(unsigned long long num, char *arr, char address[16]);

void	print_numbers(unsigned char *str, unsigned int size, char *arr)
{
	int				idx;
	int				odd;
	unsigned int	gap;

	gap = size;
	idx = -1;
	odd = 1;
	while (++idx < 16)
	{
		odd *= -1;
		if (gap > 0)
		{
			write(1, &arr[str[idx] / 16], 1);
			write(1, &arr[str[idx] % 16], 1);
			gap--;
		}
		else
			write(1, "  ", 2);
		if (odd == 1)
			write(1, " ", 1);
	}
}

void	print_letters(unsigned char *str)
{
	if (*str >= 32 && *str <= 126)
		write(1, str, 1);
	else
		write(1, ".", 1);
}

void	print_address(unsigned char *str)
{
	unsigned long long	num;
	char				*num_arr;
	char				arr[16];
	int					i;

	i = 0;
	while (i < 16)
	{
		arr[i] = '0';
		i++;
	}
	num_arr = "0123456789abcdef";
	num = (unsigned long long)(str);
	convert_loop(num, num_arr, arr);
	i = 0;
	while (i < 16)
	{
		write(1, &arr[i], 1);
		i++;
	}
	write(1, ": ", 2);
}

void	convert_loop(unsigned long long num, char *arr, char address[17])
{
	int	i;

	i = 15;
	while (1)
	{
		if (num >= 16)
		{
			address[i] = arr[num % 16];
			i--;
			num /= 16;
		}
		else
		{
			address[i] = arr[num];
			break ;
		}
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	char			*num_arr;
	unsigned int	cnt;
	unsigned int	gap;

	gap = size;
	cnt = 0;
	num_arr = "0123456789abcdef";
	str = (unsigned char *)addr;
	while (cnt < size)
	{
		if (cnt % 16 == 0)
		{
			print_address(str);
			print_numbers(str, gap, num_arr);
		}
		print_letters(str);
		str++;
		cnt++;
		gap--;
		if (cnt % 16 == 0 || cnt == size)
			write(1, "\n", 1);
	}
	return (addr);
}
