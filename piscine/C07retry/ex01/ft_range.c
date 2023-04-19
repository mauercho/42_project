/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:36:34 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/26 11:38:39 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*arr;
	long long	size;
	int			idx;

	idx = 0;
	if (min >= max)
	{
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (idx < size)
	{
		arr[idx] = min++;
		idx++;
	}
	return (arr);
}
