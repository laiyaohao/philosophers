/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:46:13 by ylai              #+#    #+#             */
/*   Updated: 2025/01/10 20:18:23 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	init_forks(t_table *table)
{
	long long	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (table->forks == NULL)
	{
		printf("Error: malloc failed for number of forks\n");
		return (-2);
	}
	i = 0;
	while (i < table->philo_num)
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

void	init_frm_table(t_table *table, long long i)
{
	table->philo[i].dead = &(table->dead);
	table->philo[i].start = &(table->start);
	table->philo[i].dead_mut = &(table->dead_mut);
	table->philo[i].meal_mut = &(table->meal_mut);
	table->philo[i].prt_mut = &(table->prt_mut);
	table->philo[i].time_mut = &(table->time_mut);
	table->philo[i].time_to_eat = table->time_to_eat;
	table->philo[i].time_to_sleep = table->time_to_sleep;
	table->philo[i].time_to_die = table->time_to_die;
	table->philo[i].philo_num = table->philo_num;
	table->philo[i].must_eat_num = table->must_eat_num;
}

void	init_philo(t_table *table)
{
	long long	i;

	i = 0;
	while (i < table->philo_num)
	{
		init_frm_table(table, i);
		table->philo[i].number = i + 1;
		table->philo[i].start_time = table->start_time;
		table->philo[i].times_eaten = 0;
		table->philo[i].meal_time = table->philo[i].start_time;
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
	if (pthread_mutex_init(&(table->time_mut), NULL))
	{
		printf("Error: pthread_mutex_init failed\n");
		return (4);
	}
	return (-1);
}

void	init_table(t_table *table)
{
	table->dead = 0;
	table->philo = malloc(sizeof(t_ph_stat) * table->philo_num);
	table->start_time = get_time();
	table->start = 0;
	if (table->philo == NULL)
	{
		printf("Error: malloc failed for the status of each philosopher\n");
		exit(1);
	}
	init_philo(table);
}
