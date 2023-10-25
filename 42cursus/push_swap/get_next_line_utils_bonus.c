/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:53:04 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 13:53:42 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen_gnl(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (*(s + i) != 0)
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == c)
		return ((char *)(s + i));
	return (0);
}

static char	*putstrzero(void)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * 1);
	if (!temp)
		return (0);
	temp[0] = 0;
	return (temp);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0)
		s1 = putstrzero();
	if (s1 == 0)
		return (0);
	i = -1;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
	{
		free(s1);
		return (0);
	}
	while (s1[++i] != 0)
		str[i] = s1[i];
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}
