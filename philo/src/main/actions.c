/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:10:12 by ylai              #+#    #+#             */
/*   Updated: 2024/12/23 17:19:44 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	think(t_ph_stat *philo)
{
	size_t	time;

	time = get_time() - philo->start_time;
	// pthread_mutex_lock(philo->prt_mut);
	print(philo, "is thinking", time);
	// pthread_mutex_unlock(philo->prt_mut);
}

void	kun(t_ph_stat *philo)
{
	size_t	time;

	time = get_time() - philo->start_time;
	// pthread_mutex_lock(philo->prt_mut);
	print(philo, "is sleeping", time);
	// pthread_mutex_unlock(philo->prt_mut);
	sleeep(philo->time_to_sleep);
}

void	eat(t_ph_stat *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->right_fork);
	// pthread_mutex_lock(philo->prt_mut);
	time = get_time() - philo->start_time;
	print(philo, "has taken a fork", time);
	// pthread_mutex_unlock(philo->prt_mut);
	if (philo->philo_num == 1)
	{
		sleeep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	time = get_time() - philo->start_time;
	// pthread_mutex_lock(philo->prt_mut);
	print(philo, "has taken a fork", time);
	// pthread_mutex_unlock(philo->prt_mut);
	philo->eating = 1;
	pthread_mutex_lock(philo->meal_mut);
	philo->meal_time = get_time();
	time = philo->meal_time - philo->start_time;
	// pthread_mutex_lock(philo->prt_mut);
	print(philo, "is eating", time);
	// pthread_mutex_unlock(philo->prt_mut);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->meal_mut);
	sleeep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
