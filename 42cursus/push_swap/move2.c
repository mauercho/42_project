/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:48 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 21:25:05 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_dblist *b)
{
	if (b->numofdata <= 1)
		return ;
	b->tail = b->tail->prev;
	b->head = b->head->prev;
	ft_putstr_fd("rrb\n", 1);
}

void	sa(t_dblist *a)
{
	int	temp;

	if (a->numofdata <= 1)
		return ;
	temp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = temp;
	ft_putstr_fd("sa\n", 1);
}

void	a_to_b(t_dblist *a, t_dblist *b, double chunk)
{
	int		i;

	i = 0;
	while (a->numofdata != 0)
	{
		if (a->head->data <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->head->data > i && a->head->data <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->head->data > i + chunk)
		{
			if (i < a->numofdata / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
	}
}

void	repeat_pa(t_dblist *b, t_dblist *a, int flag, int cnt)
{
	int	i;

	i = cnt;
	if (flag == 1)
	{
		while (i > 0)
		{
			rrb(b);
			i--;
		}
	}
	else if (flag == 0)
	{
		while (i > 0)
		{
			rb(b);
			i--;
		}
	}
	pa(b, a);
}

void	b_to_a(t_dblist *b, t_dblist *a)
{
	int		max_num;
	t_node	*tail;
	t_node	*head;
	int		cnt;

	while (b->numofdata != 0)
	{
		cnt = 0;
		max_num = b->numofdata - 1;
		tail = b->tail;
		head = b->head;
		while (tail->data != max_num && head->data != max_num)
		{
			cnt += 1;
			tail = tail->prev;
			head = head->next;
		}
		if (tail->data == max_num)
			repeat_pa(b, a, 1, cnt + 1);
		else if (head->data == max_num)
			repeat_pa(b, a, 0, cnt);
	}
}
