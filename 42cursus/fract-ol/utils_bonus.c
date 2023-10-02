/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:05:50 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/01 12:42:05 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
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

void	manual(void)
{
	ft_putstr_fd("YOU HAVE TO WRITE ./fractol ", 1);
	ft_putstr_fd("+ mandelbrot or julia or burningship\n", 1);
	ft_putstr_fd("YOU SHOULD PUT DOUBLE NUM WHEN YOU USE julia!!!\n", 1);
	ft_putstr_fd("DOUBLE BETWEEN -2.0 and 2.0\n", 1);
	ft_putstr_fd("ONLY UP TO 7 DECIMAL PLACES ARE ALLOWED.", 1);
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != 0 && s2[idx] != 0)
	{
		if (s1[idx] != s2[idx])
		{
			return (s1[idx] - s2[idx]);
		}
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}
