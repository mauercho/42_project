/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:18:27 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/15 19:47:20 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				idx;
	unsigned int	cnt;

	cnt = n;
	idx = 0;
	if (n == 0)
		return (0);
	while ((s1[idx] && s2[idx]) && cnt > 0)
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		cnt--;
		if (cnt == 0)
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (s1[idx] - s2[idx]);
}
