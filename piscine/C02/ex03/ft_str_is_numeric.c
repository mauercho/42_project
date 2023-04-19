/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:13:55 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/13 22:24:26 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == 0)
		return (1);
	while (str[idx] != 0)
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (0);
		idx++;
	}
	return (1);
}
