/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:10:51 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 16:46:29 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	free_forks(t_table *table, int fr_err)
{
	unsigned long	i;

	i = 0;
	while (fr_err == -1 && i < table->philo_num)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	while (fr_err != -1 && i < fr_err)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
}

void	free_mut(t_table *table, int mu_err)
{
	if (mu_err == -1)
	{
		pthread_mutex_destroy(&(table->dead_mut));
		pthread_mutex_destroy(&(table->meal_mut));
		pthread_mutex_destroy(&(table->prt_mut));
	}
	if (mu_err == 2)
		pthread_mutex_destroy(&(table->dead_mut));
	if (mu_err == 3)
	{
		pthread_mutex_destroy(&(table->dead_mut));
		pthread_mutex_destroy(&(table->meal_mut));
	}
}

void	free_table(t_table *table, int mu_err, int tr_err, int fr_err)
{
	free_forks(table, fr_err);
	free_mut(table, mu_err);
	free_philo(table, tr_err);
	free(table->philo);
}
