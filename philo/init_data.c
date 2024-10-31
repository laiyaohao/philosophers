/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:30:52 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 16:41:28 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_ph_da *ph_params)
{
	ph_params->philo_num = 0;
	ph_params->time_to_die = 0;
	ph_params->time_to_eat = 0;
	ph_params->time_to_sleep = 0;
	ph_params->must_eat_num = -1;
}
