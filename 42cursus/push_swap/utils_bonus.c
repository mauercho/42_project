/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:57:02 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 21:16:55 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen_gnl(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	cnt;

	cnt = n;
	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] && (unsigned char)s2[i]) && cnt > 0)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		cnt--;
		if (cnt == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	error_make(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

void	do_ok_or_ko(t_dblist *a, t_dblist *b)
{
	if (check_if_sorted(a) && is_empty(b))
	{
		ft_putstr_fd("OK\n", 1);
		free_stack(a);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		free_stack(a);
		free_stack(b);
	}
}
