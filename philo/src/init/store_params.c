/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:30:49 by ylai              #+#    #+#             */
/*   Updated: 2024/11/16 14:21:23 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	check_param(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		if (param[i] < '0' || param[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	store_params_helper(unsigned long num, int i, t_ph_da *ph_params)
{
	if (i == 1)
		ph_params->philo_num = num;
	if (i == 2)
		ph_params->time_to_die = num;
	if (i == 3)
		ph_params->time_to_eat = num;
	if (i == 4)
		ph_params->time_to_sleep = num;
	if (i == 5)
		ph_params->must_eat_num = num;
}

void	store_params(int argc, char **argv, t_ph_da *ph_params)
{
	int	i;
	char	*param;
	unsigned long	num;

	i = 1;

	while (i < argc)
	{
		param = argv[i];
		if (check_param(param) == 0)
		{
			printf("Error: parameter is not a number or is negative\n");
			exit(1);
		}
		num = ft_atol(param);
		store_params_helper(num, i, ph_params);
		i++;
	}
}