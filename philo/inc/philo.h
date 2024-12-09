/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:15 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 19:11:11 by ylai             ###   ########.fr       */
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
	int		times_eaten;
	size_t	meal_time;
	pthread_mutex_t	*meal_mut;
	pthread_mutex_t	*dead_mut;
	pthread_mutex_t	*prt_mut;
	int	eating;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
}							t_ph_stat;

typedef struct s_table
{
	unsigned long				philo_num;
	unsigned long				time_to_die;
	unsigned long				time_to_eat;
	unsigned long				time_to_sleep;
	int				must_eat_num;
	t_ph_stat					philo[300];
	pthread_t					checker;
	pthread_mutex_t		forks[300];
	pthread_mutex_t		prt_mut;
	pthread_mutex_t		dead_mut;
	pthread_mutex_t		meal_mut;
}							t_table;

// init functions
void	store_params(int argc, char **argv, t_table *table);
void	init_data(t_table *table);
void	check_data(t_table *table, int argc);
void	init_table(t_table *table);
int	init_forks(t_table *table);
int	init_mut(t_table *table);

// utils functions
unsigned long	ft_atol(const char *nptr);
void	prt_argc_msg(int argc);
size_t	get_time(void);
void	*check(void *arg);
void  print(t_ph_stat *philo, char *msg);
int	ft_usleep(size_t milliseconds);

// cleanup functions
void	free_philo(t_table *table, int tr_err);
void	free_table(t_table *table, int mu_err, int tr_err, int fr_err);

// main functions
int	start(t_table *table);
void	eat(t_ph_stat *philo);
void	kun(t_ph_stat *philo);
void	think(t_ph_stat *philo);

#endif