/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:46:13 by ylai              #+#    #+#             */
/*   Updated: 2024/11/16 16:55:07 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_table *table, t_ph_da *ph_params)
{
	unsigned long	i;

	i = 0;
	while (i < ph_params->philo_num)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			exit(1);
		}
		i++;
	}
}

static void *strt_rou(void *arg)
{
	// t_ph_stat	*tinfo = arg;
	// char *uargv;
	(void)arg;

	// printf("dead: %d, time left: %ld\n", tinfo->dead,
	// tinfo->left_to_die);

	// uargv = strdup(tinfo->argv_string);
	// if (uargv == NULL)
	// 		handle_error("strdup");

	// for (char *p = uargv; *p != '\0'; p++)
	// 		*p = toupper(*p);

	// return uargv;
	return NULL;
}

void	init_philo(t_ph_stat **philo, t_ph_da *ph_params)
{
	// int i;

	// i = 0;
	// while (i < ph_params->philo_num)
	// {
		
	// }
	// (void)table;
	// (void)ph_params;
	// (void)ph_stat;
	unsigned long	i;
	int	j;

	i = 0;
	while (i < ph_params->philo_num)
	{
		philo[i]->dead = -1;
		philo[i]->left_to_die = ph_params->time_to_die;
		i++;
	}
	i = 0;
	j = -1;
	while (i < ph_params->philo_num)
	{
		j = pthread_create(&(philo[i]->t_id), NULL, &strt_rou, philo[i]);
		printf("j: %d\n", j);
		if (j != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			exit(1);
		}
		i++;
	}
}

void	init_table(t_table *table, t_ph_da *ph_params)
{
	table->philo = malloc(sizeof(t_ph_stat) * ph_params->philo_num);
	printf("philo num: %ld\n", ph_params->philo_num);
	if (table->philo == NULL)
	{
		printf("Error: malloc failed for the status of each philosopher\n");
		exit(1);
	}
	// table->philo->t_id = malloc(sizeof(pthread_t) * ph_params->philo_num);
	// if (table->philo->t_id == NULL)
	// {
	// 	printf("Error: malloc failed for number of philosophers\n");
	// 	exit(1);
	// }
	table->forks = malloc(sizeof(pthread_mutex_t) * ph_params->philo_num);
	if (table->forks == NULL)
	{
		printf("Error: malloc failed for number of forks\n");
		exit(1);
	}
	// free(ph_stat);
	init_forks(table, ph_params);
	init_philo(&(table->philo), ph_params);
}
