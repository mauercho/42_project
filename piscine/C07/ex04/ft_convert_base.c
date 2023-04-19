/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:00:39 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/26 20:08:07 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	check(char alpha, char *base);
int	return_idx(char *str, int *minus);
int	ft_atoi_base(char *str, char *base);

int	get_length(char *base)
{
	int	length;

	length = 0;
	while (base[length] != 0)
		length++;
	return (length);
}

int	w_length(long long num, char *base_to)
{
	int	word;
	int	length;

	word = 1;
	length = get_length(base_to);
	while (num >= length)
	{
		num /= length;
		word++;
	}
	return (word);
}

void	put_word(char **word, int length, long long num, char *base_to)
{
	int	base_length;
	int	index;
	int	minus;

	minus = 1;
	if (num < 0)
	{
		minus = -1;
		index = length;
		(*word)[0] = '-';
		num *= -1;
	}
	else
		index = length - 1;
	base_length = get_length(base_to);
	while (num >= base_length)
	{
		(*word)[index--] = base_to[num % base_length];
		num /= base_length;
	}
	(*word)[index] = base_to[num];
	if (minus == -1)
		(*word)[length + 1] = 0;
	else
		(*word)[length] = 0;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	char		*word_num;
	int			idx;
	int			minus;

	minus = 1;
	idx = 0;
	if (check_base(base_from) == 0)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	if (check_base(base_to) == 0)
		return (0);
	if (num < 0)
	{
		num *= -1;
		minus = -1;
		word_num = (char *)malloc(sizeof(char) * (w_length(num, base_to) + 2));
	}
	else
		word_num = (char *)malloc(sizeof(char) * (w_length(num, base_to) + 1));
	put_word(&word_num, w_length(num, base_to), minus * num, base_to);
	return (word_num);
}
