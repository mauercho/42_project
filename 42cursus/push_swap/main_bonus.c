/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:55:17 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:48 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	process_with_str(char *str, t_dblist *a, t_dblist *b)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(b, a);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(a, b);
	else
		all_free(a, b);
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
	t_dblist	a;
	t_dblist	b;
	char		**str;
	char		*s;

	if (ac < 2)
		exit(0);
	if (check_empty(ac, av))
		error_make();
	init_list(&a);
	init_list(&b);
	str = join_and_split(ac, av);
	parsing(str, &a);
	s = malloc(5);
	while (s)
	{
		free(s);
		s = get_next_line(0);
		if (!s)
			break ;
		process_with_str(s, &a, &b);
	}
	do_ok_or_ko(&a, &b);
	return (0);
}
