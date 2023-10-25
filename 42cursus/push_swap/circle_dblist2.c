/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_dblist2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:38:11 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 15:52:10 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_list_tail(t_dblist *plist, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	if (plist->head == 0)
	{
		plist->head = newnode;
		plist->tail = newnode;
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	else
	{
		plist->tail->next = newnode;
		plist->head->prev = newnode;
		newnode->next = plist->head;
		newnode->prev = plist->tail;
		plist->tail = newnode;
	}
	(plist->numofdata)++;
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

int	small_idx(t_dblist *a, int target, int length)
{
	int		i;
	t_node	*head;

	head = a->head;
	i = 0;
	while (i < length)
	{
		if (head->data == target)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}
