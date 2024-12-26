/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:02:51 by ylai              #+#    #+#             */
/*   Updated: 2024/12/26 15:51:21 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		printf("Error: gettimeofday failed\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleeep(long long ms)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
}
