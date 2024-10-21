/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 01:05:42 by minwucho          #+#    #+#             */
/*   Updated: 2023/12/20 18:33:07 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_func(void *argv)
{
	t_rules		*rules;
	t_philo		*philo;

	philo = argv;
	rules = philo->rules;
	if (philo->num % 2 == 0)
		sleep_until_even_eat(rules);
	while (!rules->finish)
	{
		if (rules->philo_num - 1 == philo->id && philo->eat_count == 0)
			usleep(1);
		ph_action(rules, philo);
		if (rules->philo_num == 1)
			spend_time((long long)rules->time_to_sleep, rules);
		if (rules->time_to_eats == philo->eat_count)
		{
			rules->finished_eat++;
			break ;
		}
		ph_stat_printf(rules, philo->id, "is sleeping");
		spend_time((long long)rules->time_to_sleep, rules);
		ph_stat_printf(rules, philo->id, "is thinking");
	}
	return (0);
}

int	start_philo(t_philo *philo, t_rules *rules)
{
	int		i;

	i = 0;
	while (i < rules->philo_num)
	{
		philo[i].init_time = get_time();
		if (pthread_create(&(philo[i].thread_id), NULL, thread_func, &(philo[i])))
			return (FALSE);
		i++;
	}
	check_finish(rules, philo);
	i = 0;
	while (i < rules->philo_num)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (TRUE);
}

void	ph_check_finish(t_rules *rules, t_philo *philo)
{
	int			i;
	long long	now;

	while (!rules->finish_flag)
	{
		if ((rules->time_to_eat != 0) && (rules->philo_num == rules->finished_eat))
		{
			rules->finish_flag = 1;
			break ;
		}
		i = 0;
		while (i < rules->philo_num)
		{
			now = get_time();
			if ((now - philo[i].last_eat) >= rules->time_to_die)
			{
				ph_stat_printf(rules, i, "died");
				rules->finish_flag = 1;
				pthread_mutex_unlock(&(rules->print));
				break ;
			}
			i++;
		}
	}
}
