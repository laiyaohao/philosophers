/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:10:12 by ylai              #+#    #+#             */
/*   Updated: 2025/01/09 17:49:42 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	think(t_ph_stat *philo)
{
	print(philo, "is thinking", get_time());
}

void	kun(t_ph_stat *philo)
{
	print(philo, "is sleeping", get_time());
	sleeep(philo->time_to_sleep);
}

void	odd_even_lift(t_ph_stat *philo)
{
	if (philo->philo_num % 2 && philo->number == philo->philo_num)
	{
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork", get_time());
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork", get_time());
	}
	else if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork", get_time());
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork", get_time());
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork", get_time());
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork", get_time());
	}
}

void	odd_even_down(t_ph_stat *philo)
{
	if (philo->philo_num % 2 && philo->number == philo->philo_num)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else if (philo->number % 2 == 0)
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
	// philo->eating = 1;
	philo->meal_time = get_time();
	philo->times_eaten++;
	pthread_mutex_unlock(philo->meal_mut);
	print(philo, "is eating", philo->meal_time);
	sleeep(philo->time_to_eat);
	// philo->eating = 0;
	odd_even_down(philo);
}
