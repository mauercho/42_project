/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:56:57 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/14 21:12:11 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if ((unsigned char)str[idx] >= 32 && (unsigned char)str[idx] <= 126)
		{
			ft_putchar(str[idx]);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[(unsigned char)str[idx] / 16]);
			ft_putchar("0123456789abcdef"[(unsigned char)str[idx] % 16]);
		}
		idx++;
	}
}
