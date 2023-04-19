/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:27:11 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/14 10:44:13 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	idx;
	int	diff;

	diff = 'a' - 'A';
	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			str[idx] -= diff;
		}
		idx++;
	}
	return (str);
}
