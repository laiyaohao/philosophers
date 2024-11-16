/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:10:51 by ylai              #+#    #+#             */
/*   Updated: 2024/11/16 16:51:19 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(t_table *table, t_ph_da *ph_params)
{
	unsigned long	i;

	i = 0;
	while (i < ph_params->philo_num)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
}

void	free_philo(t_table *table, t_ph_da *ph_params)
{
	unsigned long	i;
	void	*res;

	i = 0;
	res = NULL;
	while (i < ph_params->philo_num)
	{
		pthread_join(table->philo[i], &res);
		i++;
	}
	free(res);
	free(table->philo);
}

// void	free_stat(t_ph_da	*ph_params, t_ph_stat *ph_stat)
// {
// 	unsigned long i;

// 	i = 0;
// 	while (i < ph_params->philo_num)
// 	{
// 		free(ph_stat[i]);
// 		i++;
// 	}
// }

void	free_table(t_table *table, t_ph_da *ph_params, t_ph_stat *ph_stat)
{
	free_forks(table, ph_params);
	free_philo(table, ph_params);
	(void)ph_stat;
	// free(ph_stat);
}
