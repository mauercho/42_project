/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:27:22 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/13 22:29:58 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == 0)
		return (1);
	while (str[idx] != 0)
	{
		if (!(str[idx] >= 32 && str[idx] <= 126))
			return (0);
		idx++;
	}
	return (1);
}
