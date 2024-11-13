/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:46:13 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 17:49:30 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_table *table, t_ph_da *ph_params)
{
	int	i;

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

void	init_philo(t_table *table, t_ph_da *ph_params);

void	init_table(t_table *table, t_ph_da *ph_params)
{
	table->philo = malloc(sizeof(pthread_t *) * ph_params->philo_num);
	if (table->philo == NULL)
	{
		printf("Error: malloc failed for number of philosophers\n");
		exit(1);
	}
	table->forks = malloc(sizeof(pthread_mutex_t *) * ph_params->philo_num);
	if (table->forks == NULL)
	{
		printf("Error: malloc failed for number of forks\n");
		exit(1);
	}
	init_forks(table, ph_params);
	init_philo(table, ph_params);
}
