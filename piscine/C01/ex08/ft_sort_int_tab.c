/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:45:48 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/13 12:57:06 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	num_of_cal;
	int	idx;
	int	temp;

	num_of_cal = size - 1;
	while (num_of_cal > 0)
	{
		idx = 0;
		while (idx < num_of_cal)
		{
			if (tab[idx] > tab[idx + 1])
			{
				temp = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = temp;
			}
			idx++;
		}
		num_of_cal--;
	}
}
