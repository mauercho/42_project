/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:27:23 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 16:42:18 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_free(char **s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != 0)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**join_and_split(int ac, char **av)
{
	int		i;
	char	**s;
	char	*temp;
	char	**free_temp;

	i = 1;
	temp = "";
	free_temp = (char **)malloc(sizeof(char *) * ac);
	while (i < ac)
	{
		temp = ft_strjoin(temp, av[i]);
		free_temp[i - 1] = temp;
		i++;
	}
	free_temp[i - 1] = 0;
	s = ft_split(temp, " \t\n\v\f\r");
	make_free(free_temp);
	return (s);
}

int	main(int ac, char **av)
{
	char		**str;
	t_dblist	a;
	t_dblist	b;

	init_list(&a);
	init_list(&b);
	if (ac < 2)
		exit(0);
	str = join_and_split(ac, av);
	parsing(str, &a);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}
