/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:30:00 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/23 09:22:04 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int arr[10];

void print_arr(void)
{
	int i;
	
	i = 0;
	while (i < 10)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
}

void set(int i)
{
	int j;
	j = 0;
	while (j < 10)
	{
		arr[i] = j;
		if (i == 9)
			print_arr();
		else
			set(i + 1);
		j++;
	}



}

int	main(void)
{	
	set(0);

	return (0);
}
