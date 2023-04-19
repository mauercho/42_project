/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:02:26 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/27 15:24:04 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newone;

	newone = (t_list *)malloc(sizeof(t_list));
	if (!newone)
		return (0);
	newone->content = content;
	newone->next = 0;
	return (newone);
}
