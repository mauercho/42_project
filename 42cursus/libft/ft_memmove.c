/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:24:05 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 20:23:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (const unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (len == 0)
		return (dst);
	if (tmp_dst <= tmp_src)
	{
		while (len--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		tmp_dst += len - 1;
		tmp_src += len - 1;
		while (len--)
			*tmp_dst-- = *tmp_src--;
	}
	return (dst);
}
