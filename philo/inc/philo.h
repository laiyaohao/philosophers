/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:15 by ylai              #+#    #+#             */
/*   Updated: 2024/12/23 16:19:03 by ylai             ###   ########.fr       */
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
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*meal_mut;
	pthread_mutex_t		*dead_mut;
	pthread_mutex_t		*prt_mut;
	pthread_mutex_t		*time_mut;
	pthread_t			t_id;
	long long			meal_time;
	long long			start_time;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			time_to_die;
	long long			number;
	int					*dead;
	long long			times_eaten;
	int					eating;
	long long			must_eat_num;
	long long			philo_num;
}							t_ph_stat;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		prt_mut;
	pthread_mutex_t		dead_mut;
	pthread_mutex_t		meal_mut;
	pthread_mutex_t		time_mut;
	pthread_t			checker;
	// pthread_t			checker_m;
	t_ph_stat			*philo;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			must_eat_num;
	long long			philo_num;
	long long			start_time;
	int					dead;
}							t_table;

// init functions
void				store_params(int argc, char **argv, t_table *table);
void				init_data(t_table *table);
void				check_data(t_table *table, int argc);
void				init_table(t_table *table);
int					init_forks(t_table *table);
int					init_mut(t_table *table);

// utils functions
long				ft_atol(const char *nptr);
void				prt_argc_msg(int argc);
void				*check(void *arg);
void				print(t_ph_stat *philo, char *msg);
void				sleeep(long long ms);
long long			get_time(void);
long long			get_start_time(t_ph_stat *philo);

// cleanup functions
void				free_table(t_table *table, long long mu_err, \
long long fr_err);

// main functions
void				start(t_table *table);
void				eat(t_ph_stat *philo);
void				kun(t_ph_stat *philo);
void				think(t_ph_stat *philo);
int					check_death(t_ph_stat *philo);

#endif