/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:45:28 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/26 19:37:38 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*temp;
	int	idx;

	idx = -1;
	size = max - min;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	temp = (int *)malloc(sizeof(int) * size);
	if (!temp)
		return (-1);
	while (++idx < size)
	{
		temp[idx] = min++;
	}
	*range = temp;
	return (size);
}
