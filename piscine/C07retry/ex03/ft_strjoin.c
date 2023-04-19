/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:10:51 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/25 19:54:09 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcpy(char **dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != 0)
	{
		(*dest)[idx] = src[idx];
		idx++;
	}
	(*dest)[idx] = 0;
	return ;
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}

int	get_length(char **strs, char *sep, int size)
{
	int	idx;
	int	length;

	length = 0;
	idx = 0;
	while (idx < size)
	{
		length += ft_strlen(strs[idx]);
		if (idx != size - 1)
			length += ft_strlen(sep);
		idx++;
	}
	return (length);
}

char	*make_temp(int size, char **strs, char *sep, int length)
{
	char	*temp;
	int		idx;

	idx = 0;
	temp = (char *)malloc(sizeof(char) * (length + 1));
	while (idx < size)
	{
		ft_strcpy(&temp, strs[idx]);
		temp += ft_strlen(strs[idx]);
		if (idx != size - 1)
		{
			ft_strcpy(&temp, sep);
			temp += ft_strlen(sep);
		}
		idx++;
	}
	*temp = 0;
	temp -= length;
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*temp;
	int		idx;

	idx = 0;
	if (size == 0)
	{
		temp = (char *)malloc(sizeof(char));
		return (temp);
	}
	length = get_length(strs, sep, size);
	temp = make_temp(size, strs, sep, length);
	return (temp);
}
