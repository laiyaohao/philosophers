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

#include "../../inc/philo.h"

void	free_forks(t_table *table, int mu_err)
{
	unsigned long	i;

	i = 0;
	while (!mu_err && i < table->philo_num)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
}

void	free_philo(t_table *table, int tr_err)
{
	unsigned long	i;
	void	*res;
	int	s;

	i = 0;
	res = NULL;
	s = -1;
	if (!tr_err)
	{
		if (pthread_join(table->checker, &res) != 0)
			printf("pthread_join error\m");
		free(res);
		res = NULL;
	}
	while (!tr_err && i < table->philo_num)
	{
		if (pthread_join(table->philo[i].t_id, &res) != 0)
		{
			printf("pthread_join error\n");
			return ;
		}
		i++;
		free(res);
		res = NULL;
	}
}

void	free_table(t_table *table, int *mu_err, int *tr_err)
{
	free_forks(table, *mu_err);
	free_philo(table, *tr_err);
	free(table->philo);
}
