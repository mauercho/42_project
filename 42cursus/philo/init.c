/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:12:46 by minwucho          #+#    #+#             */
/*   Updated: 2023/12/20 20:44:14 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	if (pthread_mutex_init(&(rules->writing), NULL))
		return (FALSE);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (FALSE);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->philo_num);
	if (!(rules->forks))
		return (FALSE);
	i = 0;
	while (i < rules->philo_num)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_and_init_rules(int ac, char **av, t_rules *rules)
{
	rules->philo_num = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->finish_flag = 0;
	if (ac == 6)
	{
		rules->times_philo_must_eat = ft_atoi(av[5]);
		if (rules->times_philo_must_eat <= 0)
			return (FALSE);
	}
	if (rules->philo_num <= 0 || rules->time_to_die < 0 \
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0)
		return (FALSE);
	if (init_mutex(rules) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	init_philo(t_rules *rules, t_philo **philo)
{
	int		i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * rules->philo_num);
	if (!(*philo))
		return (print_error("MALLOC ERROR"));
	while (i < rules->philo_num)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % rules->philo_num;
		(*philo)[i].rules = rules;
		i++;
	}
	return (TRUE);
}
