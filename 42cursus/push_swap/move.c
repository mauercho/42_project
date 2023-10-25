/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:27:50 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/19 17:51:56 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_dblist *a, t_dblist *b)
{
	int	data;

	data = pop(a);
	insert_list(b, data);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_dblist *b, t_dblist *a)
{
	int	data;

	data = pop(b);
	insert_list(a, data);
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_dblist *a)
{
	if (a->numofdata <= 1)
		return ;
	a->head = a->head->next;
	a->tail = a->tail->next;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_dblist *b)
{
	if (b->numofdata <= 1)
		return ;
	b->head = b->head->next;
	b->tail = b->tail->next;
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_dblist *a)
{
	if (a->numofdata <= 1)
		return ;
	a->tail = a->tail->prev;
	a->head = a->head->prev;
	ft_putstr_fd("rra\n", 1);
}
