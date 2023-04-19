/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:02 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/27 18:15:20 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
