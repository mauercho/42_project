/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:40:04 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/15 18:12:58 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != 0 && s2[idx] != 0)
	{
		if (s1[idx] != s2[idx])
		{
			return (s1[idx] - s2[idx]);
		}
		idx++;
	}
	return (s1[idx] - s2[idx]);
}
