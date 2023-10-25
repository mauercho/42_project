/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:58:19 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 21:17:35 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_dblist *a, t_dblist *b)
{
	int	data;

	data = pop(a);
	insert_list(b, data);
}

void	pa(t_dblist *b, t_dblist *a)
{
	int	data;

	data = pop(b);
	insert_list(a, data);
}

void	ra(t_dblist *a)
{
	if (a->numofdata <= 1)
		return ;
	a->head = a->head->next;
	a->tail = a->tail->next;
}

void	rb(t_dblist *b)
{
	if (b->numofdata <= 1)
		return ;
	b->head = b->head->next;
	b->tail = b->tail->next;
}

void	rra(t_dblist *a)
{
	if (a->numofdata <= 1)
		return ;
	a->tail = a->tail->prev;
	a->head = a->head->prev;
}
