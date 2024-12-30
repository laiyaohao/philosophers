/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:10:51 by ylai              #+#    #+#             */
/*   Updated: 2024/12/30 17:41:47 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	free_forks(t_table *table, long long fr_err)
{
	long long	i;

	i = 0;
	while (fr_err == -1LL && i < table->philo_num)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	while (fr_err != -1LL && i < fr_err)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
}

void	free_mut(t_table *table, long long mu_err)
{
	if (mu_err == -1LL)
	{
		pthread_mutex_destroy(&(table->dead_mut));
		pthread_mutex_destroy(&(table->meal_mut));
		pthread_mutex_destroy(&(table->prt_mut));
		pthread_mutex_destroy(&(table->time_mut));
	}
	if (mu_err == 2LL)
		pthread_mutex_destroy(&(table->dead_mut));
	if (mu_err == 3LL)
	{
		pthread_mutex_destroy(&(table->dead_mut));
		pthread_mutex_destroy(&(table->meal_mut));
	}
	if (mu_err == 4LL)
	{
		pthread_mutex_destroy(&(table->dead_mut));
		pthread_mutex_destroy(&(table->meal_mut));
		pthread_mutex_destroy(&(table->prt_mut));
	}
}

void	free_table(t_table *table, long long mu_err, long long fr_err)
{
	free_forks(table, fr_err);
	free_mut(table, mu_err);
	free(table->philo);
}
