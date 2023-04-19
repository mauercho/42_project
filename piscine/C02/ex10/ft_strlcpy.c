/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:20:09 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/21 10:08:11 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	int				return_length;

	idx = 0;
	while (src[idx] != 0)
		idx++;
	return_length = idx;
	idx = 0 ;
	if (size > 0)
	{
		while (src[idx] != 0 && idx < size - 1)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = 0;
	}
	return (return_length);
}
