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

#include "philo.h"

void	init_forks(t_table *table, t_ph_da *ph_params)
{
	unsigned long	i;

	i = 0;
	while (i < ph_params->philo_num)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			exit(1);
		}
		i++;
	}
}

void	init_philo(t_table *table, t_ph_da *ph_params, t_ph_stat *ph_stat)
{
	// int i;

	// i = 0;
	// while (i < ph_params->philo_num)
	// {
		
	// }
	(void)table;
	(void)ph_params;
	(void)ph_stat;
}

void	init_table(t_table *table, t_ph_da *ph_params, t_ph_stat **ph_stat)
{
	table->philo = malloc(sizeof(pthread_t) * ph_params->philo_num);
	if (table->philo == NULL)
	{
		printf("Error: malloc failed for number of philosophers\n");
		exit(1);
	}
	table->forks = malloc(sizeof(pthread_mutex_t) * ph_params->philo_num);
	if (table->forks == NULL)
	{
		printf("Error: malloc failed for number of forks\n");
		exit(1);
	}
	*ph_stat = malloc(sizeof(t_ph_stat) * ph_params->philo_num);
	if (*ph_stat == NULL)
	{
		printf("Error: malloc failed for the status of each philosopher\n");
		exit(1);
	}
	// free(ph_stat);
	init_forks(table, ph_params);
	init_philo(table, ph_params, *ph_stat);
}
