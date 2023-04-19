/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:49:35 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/29 19:51:09 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*ptr;

	new_lst = 0;
	while (lst)
	{
		ptr = f(lst->content);
		if (!ptr)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_node = ft_lstnew(ptr);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			free(ptr);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
