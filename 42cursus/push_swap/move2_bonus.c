/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:16:40 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 21:21:47 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb(t_dblist *b)
{
	if (b->numofdata <= 1)
		return ;
	b->tail = b->tail->prev;
	b->head = b->head->prev;
}

void	sa(t_dblist *a)
{
	int	temp;

	if (a->numofdata <= 1)
		return ;
	temp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = temp;
}

void	sb(t_dblist *b)
{
	int	temp;

	if (b->numofdata <= 1)
		return ;
	temp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = temp;
}

void	ss(t_dblist *a, t_dblist *b)
{
	sa(a);
	sb(b);
}

void	rr(t_dblist *a, t_dblist *b)
{
	ra(a);
	rb(b);
}
