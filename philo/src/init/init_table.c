/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:46:13 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 19:09:21 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	// table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	// if (table->forks == NULL)
	// {
	// 	printf("Error: malloc failed for number of forks\n");
	// 	return (-2);
	// }
	while ((unsigned long)i < table->philo_num)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			return (i);
		}
		i++;
	}
	return (-1);
}

// static void *strt_rou(void *arg)
// {
// 	// t_ph_stat	*tinfo = arg;
// 	// char *uargv;
// 	t_ph_stat *philo;
	
// 	philo = arg;

// 	printf("dead: %d\n", philo->number);
// 	if (philo->number % 2)
// 		printf("eating\n");
// 	else
// 		printf("sleeping\n");
// 	return NULL;
// }

void	init_philo(t_table *table)
{
	unsigned long	i;

	i = 0;
	while (i < table->philo_num)
	{
		table->philo[i].number = i + 1;
		table->philo[i].dead = 0;
		table->philo[i].eating = 0;
		table->philo[i].start_time = get_time();
		table->philo[i].dead_mut = &(table->dead_mut);
		table->philo[i].meal_mut = &(table->meal_mut);
		table->philo[i].prt_mut = &(table->prt_mut);
		table->philo[i].times_eaten = 0;
		table->philo[i].meal_time = get_time();
		table->philo[i].time_to_eat = table->time_to_eat;
		table->philo[i].time_to_sleep = table->time_to_sleep;
		table->philo[i].left_fork = &(table->forks[i]);
		if (i == 0)
			table->philo[i].right_fork = &(table->forks[table->philo_num - 1]);
		else
			table->philo[i].right_fork = &(table->forks[i - 1]);
		i++;
	}
}

int	init_mut(t_table *table)
{
	if (pthread_mutex_init(&(table->dead_mut), NULL))
	{
		printf("Error: pthread_mutex_init failed\n");
		return (1);
	}
	if (pthread_mutex_init(&(table->meal_mut), NULL))
	{
		printf("Error: pthread_mutex_init failed\n");
		return (2);
	}
	if (pthread_mutex_init(&(table->prt_mut), NULL))
	{
		printf("Error: pthread_mutex_init failed\n");
		return (3);
	}
	return (-1);
}

void	init_table(t_table *table)
{
	// table->philo = malloc(sizeof(t_ph_stat) * table->philo_num);
	// if (table->philo == NULL)
	// {
	// 	printf("Error: malloc failed for the status of each philosopher\n");
	// 	exit(1);
	// }
	init_philo(table);
	// }
}
