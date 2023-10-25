/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:33:23 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/24 18:24:43 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_limit(long long result, int *check, int sign)
{
	if (sign == 1)
	{
		if (result > MAX_INT)
		{
			*check = 1;
			return (0);
		}
	}
	else if (sign == -1)
	{
		if (result * sign < MIN_INT)
		{
			*check = 1;
			return (0);
		}
	}
	return (1);
}

int	check_empty(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == 0)
			return (1);
		while (av[i][j] != 0)
		{
			while (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
				j++;
			if (av[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != 0)
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	while (i < len + 1)
	{
		str[i] = s2[i - ft_strlen(s1) - 1];
		i++;
	}
	str[i] = 0;
	return (str);
}
