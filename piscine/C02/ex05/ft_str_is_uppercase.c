/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:25:45 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/13 22:26:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == 0)
		return (1);
	while (str[idx] != 0)
	{
		if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
			return (0);
		idx++;
	}
	return (1);
}
