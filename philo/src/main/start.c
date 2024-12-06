/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:43 by ylai              #+#    #+#             */
/*   Updated: 2024/11/30 19:08:16 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"



void	start_odd(t_table *table)
{
	int	dead;
	int	i;

	dead = -1;
	i = 0;
	while (1)
	{
		dead = check_death(table, ph_da);
		if (dead != -1)
		{
			printf("Philosopher %d died\n", dead);
			break;
		}
		while (i < ph_da->philo_num)
		{
			if (table->philo[i].number % 2)
			{
				pthread_mutex_lock(&(table->forks[i]));
				pthread_mutex_lock(&(table->forks[(i + 1) % ph_da->philo_num]));
				printf("Philosopher %d is eating\n", table->philo[i].number);
				table->philo[i].left_to_die -= ph_da->time_to_eat;
				pthread_mutex_unlock(&(table->forks[i]));
				pthread_mutex_unlock(&(table->forks[(i + 1) % ph_da->philo_num]));
				i++;
				break;
			}
		}
	}
}

void	strt_rou(t_table *table)
{
	
}

void	start(t_table *table, int *tr_err)
{
	int	i;

	i = 0;
	if (pthread_create(&(table->checker), NULL, &(check), table) != 0)
	{
		printf("Error: pthread_create failed\n");
		*tr_err = 1;
		return ;
	}
	while (i < table->philo_num)
	{
		if (pthread_craete(&table->philo[i].t_id), NULL, &strt_rou, &table != 0)
		{
			printf("Error: pthread_create failed\n");
			*tr_err = 1;
			return ;
		}
		i++;
	}
	// if (table->philo_num % 2)
	// {
	// 	// start_odd(table, ph_da);
	// 	// delay
	// }
	// else
	// {
	// 	start_even(table);
	// }
	// j = pthread_create(&(philo[i].t_id), NULL, &strt_rou, &philo[i]);
	// if (j != 0)
	// {
	// 	printf("Error: pthread_mutex_init failed\n");
	// 	*tr_err = 1;
	// 	return ;
	// }
}