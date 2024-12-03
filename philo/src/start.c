/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:43 by ylai              #+#    #+#             */
/*   Updated: 2024/11/30 19:08:16 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_death(t_table *table, t_ph_da *ph_da)
{
	unsigned int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < ph_da->philo_num)
	{
		if (table->philo[i].left_to_die <= 0)
		{
			j = table->philo[i].number;
			break;
		}
		i++;
	}
	return (j);
}

void	start_odd(t_table *table, t_ph_da *ph_da)
{
	int	dead;
	int	i;

	dead = -1;
	i = 0;
	while (1)
	{
		dead = check_death(table, ph_da);
		if (dead != -1)
		{
			printf("Philosopher %d died\n", dead);
			break;
		}
		while (i < ph_da->philo_num)
		{
			if (table->philo[i].number % 2)
			{
				pthread_mutex_lock(&(table->forks[i]));
				pthread_mutex_lock(&(table->forks[(i + 1) % ph_da->philo_num]));
				printf("Philosopher %d is eating\n", table->philo[i].number);
				table->philo[i].left_to_die -= ph_da->time_to_eat;
				pthread_mutex_unlock(&(table->forks[i]));
				pthread_mutex_unlock(&(table->forks[(i + 1) % ph_da->philo_num]));
				i++;
				break;
			}
		}
	}
}

void	start_even(t_table *table, t_ph_da *ph_da)
{
	
}

void	start(t_table *table, t_ph_da *ph_da)
{
	int	i;

	i = 0;
	if (ph_da->philo_num % 2)
	{
		start_odd(table, ph_da);
	}
	else
	{
		start_even(table, ph_da);
	}
}