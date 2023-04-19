/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:23:44 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/26 23:23:53 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check(char alpha, char *charset)
{
	int	idx;

	idx = 0;
	while (charset[idx] != 0)
	{
		if (alpha == charset[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	get_range(char *str, char *charset)
{
	int	idx;
	int	range;

	range = 0;
	idx = 0;
	while (str[idx] != 0)
	{
		while (str[idx] != 0 && check(str[idx], charset))
			idx++;
		if (str[idx] != 0 && !check(str[idx], charset))
		{
			while (str[idx] != 0 && !check(str[idx], charset))
			{
				idx++;
			}
			range++;
		}
	}
	return (range);
}

char	*get_word(char *str, char *charset)
{
	int		length;
	char	*temp;
	int		idx;

	length = 0;
	while (str[length] != 0 && !check(str[length], charset))
		length++;
	temp = (char *)malloc(sizeof(char) * (length + 1));
	if (!temp)
		return (0);
	temp[length] = 0;
	idx = 0;
	while (idx < length)
	{
		temp[idx] = str[idx];
		idx++;
	}
	return (temp);
}

char	**ft_split(char *str, char *charset)
{
	char	**temp;
	int		range;
	int		idx;
	int		j;

	j = 0;
	idx = 0;
	range = get_range(str, charset);
	temp = (char **)malloc(sizeof(char *) * (range + 1));
	if (!temp)
		return (0);
	while (j < range)
	{
		while (str[idx] != 0 && check(str[idx], charset))
			idx++;
		if (str[idx] != 0 && !check(str[idx], charset))
		{
			temp[j] = get_word(&str[idx], charset);
			while (str[idx] != 0 && !check(str[idx], charset))
				idx++;
			j++;
		}
	}
	temp[range] = 0;
	return (temp);
}
