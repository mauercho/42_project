/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:23:45 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/15 20:06:15 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	diff;
	unsigned int	idx;

	idx = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (size + src_len);
	if (dest_len >= size)
		return (size + src_len);
	diff = size - dest_len - 1;
	while (diff > 0 && src[idx] != 0)
	{
		dest[dest_len + idx] = src[idx];
		idx++;
		diff--;
	}
	dest[dest_len + idx] = 0;
	return (dest_len + src_len);
}
