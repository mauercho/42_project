/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:28:39 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/31 15:50:41 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;	
	char	com;	

	com = (char)c;
	i = 0;
	while (*(s + i) != 0)
	{
		if (com == *(s + i))
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (com == *(s + i))
		return ((char *)(s + i));
	return (0);
}
