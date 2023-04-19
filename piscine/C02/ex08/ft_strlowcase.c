/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:44:44 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/14 10:52:20 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	idx;
	int	diff;

	diff = 'a' - 'A';
	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			str[idx] += diff;
		}
		idx++;
	}
	return (str);
}
