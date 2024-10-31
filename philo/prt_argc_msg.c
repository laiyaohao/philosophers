/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_argc_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:10:44 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 16:17:16 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prt_argc_msg(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] \
		[time_to_eat] [time_to_sleep] \
		optional: [number_of_times_each_philosopher_must_eat]\n");
		exit(1);
	}
}
