/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_dblist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:27:31 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/21 22:14:36 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_dblist *plist)
{
	plist->head = 0;
	plist->numofdata = 0;
	plist->tail = 0;
	plist->cur = 0;
}

void	insert_list(t_dblist *plist, int data)
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
		plist->head->prev = newnode;
		plist->tail->next = newnode;
		newnode->next = plist->head;
		newnode->prev = plist->tail;
		plist->head = newnode;
	}
	(plist->numofdata)++;
}

void	free_stack(t_dblist *a)
{
	t_node	*remove;

	if (a == 0 || a->head == 0)
		return ;
	a->cur = a->head;
	while (a->cur != a->tail)
	{
		remove = a->cur;
		a->cur = a->cur->next;
		free(remove);
	}
	free(a->tail);
	a->head = 0;
	a->tail = 0;
	a->numofdata = 0;
}

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

int	pop(t_dblist *a)
{
	t_node	*cur;
	int		pop_data;

	cur = a->head;
	pop_data = cur->data;
	if (a->numofdata > 1)
	{
		a->head = cur->next;
		a->tail->next = a->head;
		a->head->prev = a->tail;
	}
	else
	{
		a->head = 0;
		a->tail = 0;
	}
	(a->numofdata)--;
	free(cur);
	return (pop_data);
}
