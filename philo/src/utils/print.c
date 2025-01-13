/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:10:29 by ylai              #+#    #+#             */
/*   Updated: 2025/01/13 21:12:49 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print(t_ph_stat *philo, char *msg, long long time)
{
	long long	rtime;

	pthread_mutex_lock(philo->prt_mut);
	rtime = time - philo->start_time;
	if (check_death(philo) != 1)
		printf("%llu %lld %s\n", rtime, philo->number, msg);
	pthread_mutex_unlock(philo->prt_mut);
}
