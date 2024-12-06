/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:46:13 by ylai              #+#    #+#             */
/*   Updated: 2024/11/16 16:55:07 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	init_forks(t_table *table, int *mu_err)
{
	unsigned long	i;

	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			*mu_err = 1;
			return ;
		}
		i++;
	}
}

static void *strt_rou(void *arg)
{
	// t_ph_stat	*tinfo = arg;
	// char *uargv;
	t_ph_stat *philo;
	
	philo = arg;

	printf("dead: %d\n", philo->number);
	if (philo->number % 2)
		printf("eating\n");
	else
		printf("sleeping\n");
	return NULL;
}

void	init_philo(t_table *table)
{
	unsigned long	i;
	int	j;

	i = 0;
	// j = 1;
	while (i < table->philo_num)
	{
		table->philo[i].number = i + 1;
		table->philo[i].dead = -1;
		table->philo[i].start_time = get_time();
		// j = pthread_create(&(philo[i].t_id), NULL, &strt_rou, &philo[i]);
		// if (j != 0)
		// {
		// 	printf("Error: pthread_mutex_init failed\n");
		// 	*tr_err = 1;
		// 	return ;
		// }
		table->philo[i].times_eaten = 0;
		table->philo[i].meal_time = get_time();
		table->philo[i].left_fork = &(table->forks[i]);
		if (i == 0)
			table->philo[i].right_fork = &(table->forks[table->philo_num - 1]);
		else
			table->philo[i].right_fork = &(table->forks[i - 1]);
		i++;
	}
}

void	init_table(t_table *table, int *mu_err, int *tr_err)
{
	table->philo = malloc(sizeof(t_ph_stat) * table->philo_num);
	if (table->philo == NULL)
	{
		printf("Error: malloc failed for the status of each philosopher\n");
		exit(1);
	}
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (table->forks == NULL)
	{
		printf("Error: malloc failed for number of forks\n");
		exit(1);
	}
	init_forks(table, mu_err);
	init_philo(table);
	// unsigned long i = 0;
	// while (i < ph_params->philo_num)
	// {
	// 	printf("philo[i].dead: %d\n", table->philo[i].dead);
	// 	i++;
	// }
}
