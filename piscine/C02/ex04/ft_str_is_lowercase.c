/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:19:27 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/13 22:23:51 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == 0)
		return (1);
	while (str[idx] != 0)
	{
		if (!(str[idx] >= 'a' && str[idx] <= 'z'))
			return (0);
		idx++;
	}
	return (1);
}
