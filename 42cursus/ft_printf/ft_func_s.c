/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:00:40 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/23 22:33:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string(char	*str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		len++;
	}
	return (len);
}

int	prints(va_list ap)
{
	char	*str;
	int		len;

	str = (char *)va_arg(ap, char *);
	if (str)
	{
		len = print_string(str);
		return (len);
	}
	else
		return (write(1, "(null)", 6));
}
