/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:56:08 by minwucho          #+#    #+#             */
/*   Updated: 2023/12/20 20:35:38 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;
	t_philo	*philo_arr;

	if (ac != 5 && ac != 6)
		return (print_error("4 or 5 args are necessary"));
	memset(&rules, 0, sizeof(t_rules));
	if (check_and_init_rules(ac, av, &rules) == FALSE)
		return (print_error("Invalid argv. SRY"));
	if (init_philo(&rules, &philo_arr) == FALSE)
		return (print_error("Philo allocate error"));
	if (start_philo(philo_arr, &rules) == FALSE)
		return (print_error("Philo start error"));
}
