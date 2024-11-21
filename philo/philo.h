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

typedef struct s_ph_da
{
	unsigned long				philo_num;
	unsigned long				time_to_die;
	unsigned long				time_to_eat;
	unsigned long				time_to_sleep;
	unsigned long				must_eat_num;
}							t_ph_da;

typedef struct s_ph_stat
{
	pthread_t			t_id;
	int		dead;
	long			left_to_die;
}							t_ph_stat;

typedef struct s_table
{
	t_ph_stat					*philo;
	pthread_mutex_t				*forks;
}							t_table;


void	prt_argc_msg(int argc);
void	store_params(int argc, char **argv, t_ph_da *ph_params);
void	init_data(t_ph_da *ph_params);
void	check_data(t_ph_da *ph_params);
void	init_table(t_table *table, t_ph_da *ph_params);
void	free_table(t_table *table, t_ph_da *ph_params);

#endif