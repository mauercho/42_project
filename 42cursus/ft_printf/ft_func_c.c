/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:45:47 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/23 22:32:11 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printc(va_list ap)
{
	unsigned char	ch;

	ch = (unsigned char)va_arg(ap, int);
	if (write(1, &ch, 1) == -1)
		return (-1);
	return (1);
}
