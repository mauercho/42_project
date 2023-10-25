/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_dblist2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:26:30 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 21:26:03 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_overlap(t_dblist *a)
{
	t_node	*cur;
	t_node	*check;

	if (a == 0 || a->head == 0)
		return (0);
	cur = a->head;
	while (1)
	{
		check = cur->next;
		while (check != a->head)
		{
			if (cur->data == check->data)
				return (1);
			check = check->next;
		}
		cur = cur->next;
		if (cur == a->tail)
			break ;
	}
	return (0);
}

void	all_free(t_dblist *a, t_dblist *b)
{
	free_stack(a);
	free_stack(b);
	error_make();
}

int	check_if_sorted(t_dblist *a)
{
	t_node	*cur;
	int		i;

	cur = a->head;
	i = 0;
	while (i < a->numofdata - 1)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
		i++;
	}
	return (1);
}

int	is_empty(t_dblist *b)
{
	if (b->numofdata == 0)
		return (1);
	else
		return (0);
}
