/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:10:12 by ylai              #+#    #+#             */
/*   Updated: 2024/12/26 19:27:02 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	think(t_ph_stat *philo)
{
	print(philo, "is thinking");
}

void	kun(t_ph_stat *philo)
{
	print(philo, "is sleeping");
	sleeep(philo->time_to_sleep);
}

void	eat(t_ph_stat *philo)
{
	if (philo->philo_num == 1)
	{
		sleeep(philo->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print(philo, "has taken a fork");
	philo->eating = 1;
	pthread_mutex_lock(philo->meal_mut);
	philo->meal_time = get_time();
	print(philo, "is eating");
	philo->times_eaten++;
	pthread_mutex_unlock(philo->meal_mut);
	sleeep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
