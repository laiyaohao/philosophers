/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:12:29 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 16:21:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	check_data(t_ph_da *ph_params)
{
	if (ph_params->philo_num == 0 || ph_params->time_to_die == 0
		|| ph_params->time_to_eat == 0
		|| ph_params->time_to_sleep == 0 || ph_params->must_eat_num == 0)
	{
		printf("Error: some parameters are 0\n");
		exit(1);
	}
}
