/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:10:12 by ylai              #+#    #+#             */
/*   Updated: 2024/12/30 19:36:25 by ylai             ###   ########.fr       */
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

void	odd_even_lift(t_ph_stat *philo)
{
	// odd
	if (philo->number % 2 && (philo->philo_num % 2 && philo->number != philo->philo_num))
	{
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork");
	}
}

void	odd_even_down(t_ph_stat *philo)
{
	if (philo->number % 2 && (philo->philo_num % 2 && philo->number != philo->philo_num))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	eat(t_ph_stat *philo)
{
	if (philo->philo_num == 1)
	{
		sleeep(philo->time_to_die);
		return ;
	}
	odd_even_lift(philo);
	pthread_mutex_lock(philo->meal_mut);
	philo->eating = 1;
	philo->meal_time = get_time();
	print(philo, "is eating");
	philo->times_eaten++;
	pthread_mutex_unlock(philo->meal_mut);
	sleeep(philo->time_to_eat);
	philo->eating = 0;
	// pthread_mutex_unlock(philo->left_fork);
	// pthread_mutex_unlock(philo->right_fork);
	odd_even_down(philo);
}
