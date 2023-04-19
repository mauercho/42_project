/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:53:10 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/01 13:59:28 by minwucho         ###   ########.fr       */
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
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		length;
	int		cal_num;
	int		idx;

	length = 0;
	while (tab[length] != 0)
		length++;
	cal_num = length - 1;
	while (cal_num > 0)
	{
		idx = 0;
		while (idx < cal_num)
		{
			if (ft_strcmp(tab[idx], tab[idx + 1]) > 0)
			{
				temp = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = temp;
			}
			idx++;
		}
		cal_num--;
	}
}
