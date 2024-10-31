/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:10:51 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 18:10:52 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table, t_ph_da *ph_params)
{
	int	i;

	i = 0;
	while (i < ph_params->philo_num)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
	free(table->philo);
}
