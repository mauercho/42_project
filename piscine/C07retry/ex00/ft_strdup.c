/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:25 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/22 13:33:32 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != 0)
		idx++;
	return (idx);
}

char	*ft_strdup(char *src)
{
	int		idx;
	char	*arr;
	int		length;

	length = ft_strlen(src);
	idx = 0;
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (!arr)
		return (0);
	while (idx < length)
	{
		arr[idx] = src[idx];
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}
