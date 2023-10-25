/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:45:39 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 16:29:19 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hardcoding_two(t_dblist *a)
{
	if (a->head->data > a->tail->data)
		ra(a);
}

void	hardcoding_three(t_dblist *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->data;
	second = a->head->next->data;
	third = a->tail->data;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		sa(a);
		ra(a);
	}
	else if (second < first && first < third)
		sa(a);
	else if (second < third && third < first)
		ra(a);
	else if (third < first && first < second)
		rra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	hardcoding_four(t_dblist *a, t_dblist *b)
{
	int	i;

	change(a);
	i = small_idx(a, 0, 4);
	if (i <= 2)
	{
		while (--i >= 0)
			ra(a);
	}
	else if (i == 3)
		rra(a);
	pb(a, b);
	hardcoding_three(a);
	pa(b, a);
}

void	hardcoding_five(t_dblist *a, t_dblist *b)
{
	int	i;

	change(a);
	i = small_idx(a, 0, 5);
	if (i <= 2)
	{
		while (--i >= 0)
			ra(a);
	}
	else if (i >= 3 && i <= 4)
	{
		i = 5 - i;
		while (--i >= 0)
			rra(a);
	}
	pb(a, b);
	hardcoding_four(a, b);
	pa(b, a);
}
