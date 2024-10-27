/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:50:34 by ylai              #+#    #+#             */
/*   Updated: 2024/10/27 17:54:47 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 4 || argc != 5)
	{
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] \
		[time_to_eat] [time_to_sleep] \
		optional: [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
}