/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:30:03 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/15 20:05:27 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	idx_for_tofind;

	idx = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[idx] != 0)
	{
		idx_for_tofind = 0;
		while (str[idx + idx_for_tofind] == to_find[idx_for_tofind])
		{
			idx_for_tofind++;
			if (to_find[idx_for_tofind] == 0)
				return (&str[idx]);
		}
		idx++;
	}
	return (0);
}
