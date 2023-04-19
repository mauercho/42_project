/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:41:13 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/16 12:04:53 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx_for_dest;
	int	idx_for_src;

	idx_for_dest = 0;
	idx_for_src = 0;
	while (dest[idx_for_dest] != 0)
		idx_for_dest++;
	while (src[idx_for_src] != 0)
	{
		dest[idx_for_dest + idx_for_src] = src[idx_for_src];
		idx_for_src++;
	}
	dest[idx_for_dest + idx_for_src] = 0;
	return (dest);
}
