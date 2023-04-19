/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:11:12 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 19:24:52 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_range(char alpha, char const *s)
{
	size_t	idx;
	size_t	range;

	idx = 0;
	range = 0;
	while (s[idx] != 0)
	{
		while (s[idx] != 0 && s[idx] == alpha)
			idx++;
		if (s[idx] != 0 && !(s[idx] == alpha))
		{
			while (s[idx] != 0 && !(s[idx] == alpha))
				idx++;
			range++;
		}
	}
	return (range);
}

static char	*get_word(char const *s, char alpha)
{
	size_t	length;
	char	*temp;
	size_t	idx;

	length = 0;
	while (s[length] != 0 && !(s[length] == alpha))
		length++;
	temp = (char *)malloc(sizeof(char) * (length + 1));
	if (!temp)
		return (0);
	idx = 0;
	while (idx < length)
	{
		temp[idx] = s[idx];
		idx++;
	}
	temp[idx] = 0;
	return (temp);
}

static void	free_all(char **temp, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	size_t	idx;
	size_t	j;

	j = 0;
	idx = 0;
	temp = (char **)malloc(sizeof(char *) * (get_range(c, s) + 1));
	if (!temp)
		return (0);
	while (j < get_range(c, s))
	{
		while (s[idx] != 0 && s[idx] == c)
			idx++;
		temp[j] = get_word(&s[idx], c);
		if (!temp[j])
		{
			free_all(temp, j);
			return (0);
		}
		while (s[idx] != 0 && !(s[idx] == c))
			idx++;
		j++;
	}
	temp[j] = 0;
	return (temp);
}
