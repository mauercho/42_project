/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:45:51 by minwucho          #+#    #+#             */
/*   Updated: 2023/12/20 18:33:07 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE -1
# define MAXINT 2147483647
# define MININT -2147483648

typedef struct s_rules
{
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_philo_must_eat;
	int					flag;
	int 				finish_flag;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing;
}	t_rules;

typedef struct s_philo
{
	int			num;
	int			eat_count;
	int			left;
	int			right;
	long long	last_eat;
	long long	init_time;
	pthread_t	thread_id;
	t_rules		*rules;
}	t_philo;

int			print_error(char *s);
int			ft_atoi(const char *str);
t_philo 	*check_and_init_philo(t_rules *rules);
long long	get_time(void);
int			check_and_init_rules(int ac, char **av, t_rules *rules);
int			start_philo(t_philo *philo, t_rules *rules);
int			init_philo(t_rules *rules, t_philo **philo);

#endif
