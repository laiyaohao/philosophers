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

void	free_forks(t_table *table, t_ph_da *ph_params, int mu_err)
{
	unsigned long	i;

	i = 0;
	while (!mu_err && i < ph_params->philo_num)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
}

void	free_philo(t_ph_stat *philo, t_ph_da *ph_params, int tr_err)
{
	unsigned long	i;
	void	*res;
	int	s;

	i = 0;
	res = NULL;
	s = -1;
	while (!tr_err && i < ph_params->philo_num)
	{
		s = pthread_join(philo[i].t_id, &res);
		if (s != 0)
		{
			printf("pthread_join error\n");
			exit(1);
		}
		i++;
		free(res);
		res = NULL;
	}
}

void	free_table(t_table *table, t_ph_da *ph_params, int *mu_err, int *tr_err)
{
	free_forks(table, ph_params, *mu_err);
	free_philo(table->philo, ph_params, *tr_err);
	free(table->philo);
}
