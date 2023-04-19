/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:12:10 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 19:22:32 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char alpha, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == alpha)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_length(char	const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	final_idx;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (0);
	final_idx = ft_strlen(s1) - 1;
	while (check(s1[i], set))
		i++;
	while (check(s1[final_idx], set) && final_idx > i)
	{
		final_idx--;
	}
	len = final_idx - i + 1;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	j;
	size_t	i;
	size_t	final_idx;

	i = 0;
	j = 0;
	len = get_length(s1, set);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	final_idx = ft_strlen(s1);
	if (final_idx-- != 0)
	{
		while (check(s1[i], set))
			i++;
		while (check(s1[final_idx], set) && final_idx > i)
			final_idx--;
		while (i <= final_idx)
			str[j++] = s1[i++];
	}
	str[j] = 0;
	return (str);
}
