/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:53:47 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/13 11:19:39 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	idx;

	idx = 0;
	while (idx < size / 2)
	{
		temp = tab[idx];
		tab[idx] = tab[size - 1 - idx];
		tab[size -1 - idx] = temp;
		idx++;
	}
}
