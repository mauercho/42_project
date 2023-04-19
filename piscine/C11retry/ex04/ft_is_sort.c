/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:05:31 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/01 13:58:09 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;
	int	up;
	int	down;

	up = 1;
	down = 1;
	idx = 0;
	if (length == 0 || length == 1)
		return (1);
	while (idx < length - 1)
	{
		if ((*f)(tab[idx], tab[idx + 1]) < 0)
			up++;
		else if ((*f)(tab[idx], tab[idx + 1]) > 0)
			down++;
		else
		{
			up++;
			down++;
		}
		idx++;
	}
	if (up == length || down == length)
		return (1);
	return (0);
}
