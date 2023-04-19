/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:40:07 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/27 19:32:03 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	if (!*lst)
		return ;
	while (tmp->next != 0)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	ft_lstdelone(tmp, del);
	*lst = 0;
}
