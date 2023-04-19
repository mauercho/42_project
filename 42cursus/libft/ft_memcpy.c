/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:54:38 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 20:28:00 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*tmp_src;

	i = 0;
	ptr = (unsigned char *)dst;
	tmp_src = src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*(ptr + i) = *(tmp_src + i);
		i++;
	}
	return (dst);
}
