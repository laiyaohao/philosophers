/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:43 by ylai              #+#    #+#             */
/*   Updated: 2024/12/23 18:14:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	check_death(t_ph_stat *philo)
{
	pthread_mutex_lock(philo->dead_mut);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_mut);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mut);
	return (0);
}

void	*strt_rou(void *arg)
{
	t_ph_stat	*philo;

	philo = arg;
	if (philo->number % 2 == 0)
	{
		sleeep(philo->time_to_eat - 10);
	}
	while (check_death(philo) != 1)
	{
		eat(philo);
		kun(philo);
		think(philo);
	}
	return (arg);
}

void	start(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_create(&table->philo[i].t_id, NULL, &strt_rou, \
		&(table->philo[i])) != 0)
			free_table(table, -1, -1);
		i++;
	}
	if (pthread_create(&table->checker, NULL, &(check), table->philo) != 0)
		free_table(table, -1, -1);
		// return (-2);
	// if (pthread_create(&table->checker_m, NULL, &(check_m), table->philo) != 0)
	// 	// free_table(table, -1, -1);
	// 	return (-2);
	i = 0;
	if (pthread_join(table->checker, NULL) != 0)
		free_table(table, -1, -1);
	while (i < table->philo_num)
	{
		if (pthread_join(table->philo[i].t_id, NULL) != 0)
			free_table(table, -1, -1);
		i++;
	}
	// return (-1);
}
