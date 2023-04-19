/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:48:33 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/21 15:28:16 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	diff;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (dstsize + src_len);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	diff = dstsize - dst_len - 1;
	while (diff > 0 && src[i] != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
		diff--;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
