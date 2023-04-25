/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:19:40 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/23 21:57:21 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

static int	check_type(const char *format, va_list ap)
{
	if (*format == 'c')
		return (printc(ap));
	else if (*format == 's')
		return (prints(ap));
	else if (*format == 'p')
		return (printp(ap));
	else if (*format == 'd' || *format == 'i')
		return (printd(ap));
	else if (*format == 'u')
		return (printu(ap));
	else if (*format == 'x')
		return (printx(ap));
	else if (*format == 'X')
		return (printhexup(ap));
	else if (*format == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	else
		return (-1);
}

static int	check(const char *format, va_list ap)
{
	int	i;
	int	len;

	if (format == 0)
		return (-1);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len = check_type(format, ap);
			if (len == -1)
				return (-1);
			i += len;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			i++;
		}
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = check(format, ap);
	va_end(ap);
	return (result);
}
