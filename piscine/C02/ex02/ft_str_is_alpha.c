/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:05:38 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/21 09:42:13 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == 0)
		return (1);
	while (str[idx] != 0)
	{
		if (!((str[idx] >= 'A' && str[idx] <= 'Z')
				|| (str[idx] >= 'a' && str[idx] <= 'z')))
			return (0);
		idx++;
	}
	return (1);
}
