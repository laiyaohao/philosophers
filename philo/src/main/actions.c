/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:10:12 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 16:32:24 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	think(t_ph_stat *philo)
{
	
}

void	kun(t_ph_stat *philo)
{
	
}

void	eat(t_ph_stat *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	pthread_mutex_lock(&(philo->left_fork));
	// printf("Philosopher %d is eating\n", table->philo[i].number);
	// table->philo[i].left_to_die -= ph_da->time_to_eat;
	// pthread_mutex_unlock(&(table->forks[i]));
	// pthread_mutex_unlock(&(table->forks[(i + 1) % ph_da->philo_num]));
}