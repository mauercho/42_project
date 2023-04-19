/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:00:48 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/31 15:50:53 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!arr)
		return (0);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
