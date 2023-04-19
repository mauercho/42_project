/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:37:09 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 19:21:04 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlength(int num, int minus)
{
	int	length;

	length = 1;
	while (num >= 10)
	{
		length++;
		num /= 10;
	}
	if (minus < 0)
		return (length + 1);
	return (length);
}

static char	*return_char(int num, int minus)
{
	int		length;
	char	*temp;

	length = getlength(num, minus);
	temp = (char *)malloc(sizeof(char) * (length + 1));
	if (!temp)
		return (0);
	temp[length] = 0;
	if (minus == -1)
		temp[0] = '-';
	while (num >= 10)
	{
		temp[--length] = '0' + num % 10;
		num /= 10;
	}
	temp[--length] = num % 10 + '0';
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		minus;

	minus = 1;
	if (n == -2147483648)
	{
		temp = ft_strdup("-2147483648");
		if (!temp)
			return (0);
		return (temp);
	}
	if (n < 0)
		minus = -1;
	temp = return_char(minus * n, minus);
	if (!temp)
		return (0);
	return (temp);
}
