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

void	init_forks(t_table *table, t_ph_da *ph_params, int *mu_err)
{
	unsigned long	i;

	i = 0;
	while (i < ph_params->philo_num)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			*mu_err = 1;
			return ;
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

void	init_philo(t_ph_stat *philo, t_ph_da *ph_params, int *tr_err)
{
	unsigned long	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ph_params->philo_num)
	{
		philo[i].dead = -1;
		philo[i].left_to_die = ph_params->time_to_die;
		j = pthread_create(&(philo[i].t_id), NULL, &strt_rou, &philo[i]);
		if (j != 0)
		{
			printf("Error: pthread_mutex_init failed\n");
			*tr_err = 1;
			return ;
		}
		i++;
	}
}

void	init_table(t_table *table, t_ph_da *ph_params, int *mu_err, int *tr_err)
{
	table->philo = malloc(sizeof(t_ph_stat) * ph_params->philo_num);
	if (table->philo == NULL)
	{
		printf("Error: malloc failed for the status of each philosopher\n");
		exit(1);
	}
	table->forks = malloc(sizeof(pthread_mutex_t) * ph_params->philo_num);
	if (table->forks == NULL)
	{
		printf("Error: malloc failed for number of forks\n");
		exit(1);
	}
	init_forks(table, ph_params, mu_err);
	init_philo(table->philo, ph_params, tr_err);
}
