/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:51:25 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/25 21:43:54 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	i = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
