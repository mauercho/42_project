/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:17:09 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/23 19:22:16 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		printc(va_list ap);
int		prints(va_list ap);
int		printp(va_list ap);
int		printd(va_list ap);
int		printu(va_list ap);
int		printx(va_list ap);
int		printhexup(va_list ap);
int		ft_strlen(char *str);

#endif
