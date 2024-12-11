/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:43 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 19:14:11 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"



// void	start_odd(t_table *table)
// {
// 	int	dead;
// 	int	i;

// 	dead = -1;
// 	i = 0;
// 	while (1)
// 	{
// 		dead = check_death(table);
// 		if (dead != -1)
// 		{
// 			printf("Philosopher %d died\n", dead);
// 			break;
// 		}
// 		while (i < table->philo_num)
// 		{
// 			if (table->philo[i].number % 2)
// 			{
// 				pthread_mutex_lock(&(table->forks[i]));
// 				pthread_mutex_lock(&(table->forks[(i + 1) % table->philo_num]));
// 				printf("Philosopher %d is eating\n", table->philo[i].number);
// 				// table->philo[i].left_to_die -= ph_da->time_to_eat;
// 				pthread_mutex_unlock(&(table->forks[i]));
// 				pthread_mutex_unlock(&(table->forks[(i + 1) % table->philo_num]));
// 				i++;
// 				break;
// 			}
// 		}
// 	}
// }

int check_death(t_ph_stat *philo)
{
	pthread_mutex_lock(philo->dead_mut);
	if (philo->dead == 1)
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
		ft_usleep(1);
	}
	while (!check_death(philo))
	{
		eat(philo);
		kun(philo);
		think(philo);
	}
	return (arg);
}

int	start(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_create(&(table->checker), NULL, &(check), table) != 0)
	{
		printf("Error: pthread_create failed\n");
		return (-2);
	}
	while ((unsigned long)i < table->philo_num)
	{
		if (pthread_create(&table->philo[i].t_id, NULL, &strt_rou, &(table->philo[i])) != 0)
		{
			printf("Error: pthread_create failed\n");
			return (i);
		}
		i++;
	}
	i = 0;
	if (pthread_join(table->checker, NULL) != 0)
		free_table(table, -1, 0, -1);
	while ((unsigned long)i < table->philo_num)
	{
		if (pthread_join(table->philo[i].t_id, NULL) != 0)
		{
			free_table(table, -1, 0, -1);
		}
		i++;
	}
	return (-1);
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