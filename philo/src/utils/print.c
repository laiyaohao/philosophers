/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:10:29 by ylai              #+#    #+#             */
/*   Updated: 2024/12/23 17:21:22 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print(t_ph_stat *philo, char *msg)
{
	long long	time;

	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->prt_mut);
	if (check_death(philo) != 1)
		printf("%llu %lld %s\n", time, philo->number, msg);
	pthread_mutex_unlock(philo->prt_mut);
}
