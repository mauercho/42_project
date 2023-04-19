/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:28:43 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/03 18:15:15 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	com;

	len = ft_strlen(s);
	com = (char)c;
	while (len > 0)
	{
		if (com == *(s + len))
		{	
			return ((char *)(s + len));
		}
		len--;
	}
	if (com == *(s + len))
		return ((char *)(s + len));
	return (0);
}
