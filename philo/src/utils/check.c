#include "../../inc/philo.h"

int is_dead(t_ph_stat *philo, unsigned int i)
{
	pthread_mutex_lock(philo->meal_mut);
	if (get_time() - philo[i].meal_time >= philo->time_to_die \
	&& philo[i].eating == 0)
	{
		pthread_mutex_unlock(philo->meal_mut);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_mut);
	return (0);
}

int find_death(t_ph_stat *philo)
{
	int i;
	
	i = 0;
	while (i < philo->philo_num)
	{
		if (is_dead(philo, i))
		{
			print(&(philo[i]), "died");
			pthread_mutex_lock(philo->dead_mut);
			*philo->dead = 1;
			pthread_mutex_unlock(philo->dead_mut);
			return (1);
		}
		i++;
	}
	return (0);
}

int ful_meal_req(t_ph_stat *philo)
{
	int i;
	int ful;

	i = 0;
	ful = 0;
	if (philo->must_eat_num == -1)
		return (0);
	while (i < philo->philo_num)
	{
		pthread_mutex_lock(philo->meal_mut);
		if (philo[i].times_eaten >= philo->must_eat_num)
			ful++;
		pthread_mutex_unlock(philo->meal_mut);
		i++;
	}
	i = 0;
	if (ful == philo->philo_num)
	{
		pthread_mutex_lock(philo->dead_mut);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_mut);
		return (1);
	}
	return (0);
}

void	*check(void *arg)
{
	t_ph_stat *philo;

	philo = (t_ph_stat *)arg;
	while (1)
	
		if (find_death(philo) == 1 || ful_meal_req(philo) == 1)
			break;
	
	return (arg);
}
