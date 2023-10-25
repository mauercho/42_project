/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:35:46 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 20:22:28 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check(char alpha, char *charset)
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

static size_t	get_range(char const *s, char *charset)
{
	size_t	idx;
	size_t	range;

	idx = 0;
	range = 0;
	while (s[idx] != 0)
	{
		while (s[idx] != 0 && check(s[idx], charset))
			idx++;
		if (s[idx] != 0 && !check(s[idx], charset))
		{
			while (s[idx] != 0 && !check(s[idx], charset))
				idx++;
			range++;
		}
	}
	return (range);
}

static char	*get_word(char const *s, char *charset)
{
	size_t	length;
	char	*temp;
	size_t	idx;

	length = 0;
	while (s[length] != 0 && !(check(s[length], charset)))
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

char	**ft_split(char const *s, char *charset)
{
	char	**temp;
	size_t	idx;
	size_t	j;

	j = 0;
	idx = 0;
	temp = (char **)malloc(sizeof(char *) * (get_range(s, charset) + 1));
	if (!temp)
		return (0);
	while (j < get_range(s, charset))
	{
		while (s[idx] != 0 && check(s[idx], charset))
			idx++;
		temp[j] = get_word(&s[idx], charset);
		if (!temp[j])
		{
			free_all(temp, j);
			return (0);
		}
		while (s[idx] != 0 && !(check(s[idx], charset)))
			idx++;
		j++;
	}
	temp[j] = 0;
	return (temp);
}
