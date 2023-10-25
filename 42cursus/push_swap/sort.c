/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:03:06 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 18:19:06 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	idx_find(int *arr, int data, int max_idx)
{
	int	i;

	i = 0;
	while (i < max_idx)
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

void	change(t_dblist *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	i = 0;
	cur = a->head;
	arr = for_quick_arr(a);
	quicksort(arr, 0, a->numofdata - 1);
	while (i < a->numofdata)
	{
		cur->data = idx_find(arr, cur->data, a->numofdata);
		cur = cur->next;
		i++;
	}
	free(arr);
}

static void	start_sorting(t_dblist *a, t_dblist *b)
{
	double	chunk;
	int		num;

	num = a->numofdata;
	chunk = (0.000000053 * num * num) + (0.03 * num) + 14.5;
	change(a);
	a_to_b(a, b, chunk);
	b_to_a(b, a);
}

static void	start_hardcoding(t_dblist *a, t_dblist *b)
{
	if (a->numofdata == 2)
		hardcoding_two(a);
	else if (a->numofdata == 3)
		hardcoding_three(a);
	else if (a->numofdata == 4)
		hardcoding_four(a, b);
	else if (a->numofdata == 5)
		hardcoding_five(a, b);
}

void	sort(t_dblist *a, t_dblist *b)
{
	if (check_if_sorted(a))
	{
		free_stack(a);
		exit(0);
	}
	if (a->numofdata <= 5)
		start_hardcoding(a, b);
	else
		start_sorting(a, b);
}
