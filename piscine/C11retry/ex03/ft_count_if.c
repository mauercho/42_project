/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:35 by minwucho          #+#    #+#             */
/*   Updated: 2023/03/01 11:23:30 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
		{
			cnt++;
		}
		i++;
	}
	return (cnt);
}
