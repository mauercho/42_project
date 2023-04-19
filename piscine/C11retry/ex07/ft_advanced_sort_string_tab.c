/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:25:26 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/01 13:43:32 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if ((*cmp)(tab[idx], tab[idx + 1]) > 0)
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
