#include "../../inc/philo.h"

int is_dead(t_table *table, unsigned int i)
{
	pthread_mutex_lock(&(table->meal_mut));
	if (get_time() - table->philo[i].meal_time >= table->time_to_die \
	&& table->philo[i].eating == 0)
	{
		printf("philo %d should have been dead\n\n\n\n", table->philo[i].number);
		pthread_mutex_unlock(&table->meal_mut);
		return (1);
	}
	pthread_mutex_unlock(&table->meal_mut);
	return (0);
}

int find_death(t_table *table)
{
	int i;
	
	i = 0;
	while (i < table->philo_num)
	{
		if (is_dead(table, i))
		{
			print(&(table->philo[i]), "died");
			pthread_mutex_lock(&(table->dead_mut));
			table->dead = 1;
			pthread_mutex_unlock(&(table->dead_mut));
			return (1);
		}
		i++;
	}
	return (0);
}

int ful_meal_req(t_table *table)
{
	int i;
	int ful;

	i = 0;
	ful = 0;
	if (table->must_eat_num == -1)
		return (0);
	while (i < table->philo_num)
	{
		pthread_mutex_lock(&(table->meal_mut));
		if (table->philo[i].times_eaten >= table->must_eat_num)
			ful++;
		pthread_mutex_unlock(&(table->meal_mut));
		i++;
	}
	i = 0;
	if (ful == table->philo_num)
	{
		pthread_mutex_lock(&(table->dead_mut));
		table->dead = 1;
		pthread_mutex_unlock(&(table->dead_mut));
		return (1);
	}
	return (0);
}

void	*check(void *arg)
{
	t_table *table;

	table = (t_table *)arg;
	while (1)
	{
		if (find_death(table) == 1 || ful_meal_req(table) == 1)
			break;
	}
	return (arg);
}

// int	checker_fn(t_table *table)
// {
	// unsigned int	i;
	// int	j;

	// i = 0;
	// j = -1;
	// while (i < ph_da->philo_num)
	// {
	// 	if (table->philo[i].left_to_die <= 0)
	// 	{
	// 		j = table->philo[i].number;
	// 		break;
	// 	}
	// 	i++;
	// }
	// return (j);
	// pthread_create(&(table->checker), NULL, &(check), table);
// }