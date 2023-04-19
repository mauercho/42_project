/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:07:09 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/16 12:07:12 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				idx_for_dest;
	int				idx_for_src;
	unsigned int	cnt;

	idx_for_dest = 0;
	idx_for_src = 0;
	cnt = nb;
	while (dest[idx_for_dest] != 0)
		idx_for_dest++;
	while (src[idx_for_src] != 0 && cnt > 0)
	{
		dest[idx_for_dest + idx_for_src] = src[idx_for_src];
		idx_for_src++;
		cnt--;
	}
	dest[idx_for_dest + idx_for_src] = 0;
	return (dest);
}
