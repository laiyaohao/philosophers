/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:15 by ylai              #+#    #+#             */
/*   Updated: 2024/11/16 16:54:30 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_ph_stat
{
	size_t		start_time;
	unsigned int	number;
	pthread_t			t_id;
	int		dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long		times_eaten;
	size_t	meal_time;
	// pthread_mutex_t	*prt_mut;
	int	eating;
}							t_ph_stat;

typedef struct s_table
{
	unsigned long				philo_num;
	unsigned long				time_to_die;
	unsigned long				time_to_eat;
	unsigned long				time_to_sleep;
	unsigned long				must_eat_num;
	t_ph_stat					*philo;
	pthread_t					checker;
	pthread_mutex_t		*forks;
	pthread_mutex_t		prt_mut;
	pthread_mutex_t		dead_mut;
}							t_table;


void	store_params(int argc, char **argv, t_table *table);
void	init_data(t_table *table);
void	check_data(t_table *table);
void	init_table(t_table *table, int *mu_err, int *tr_err);
void	free_table(t_table *table, int *mu_err, int *tr_err);

// utils functions
unsigned long	ft_atol(const char *nptr);
void	prt_argc_msg(int argc);
size_t	get_time(void);
void	*check(void *arg);

#endif