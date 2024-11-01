/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:50:34 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 16:44:55 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_ph_da	ph_data;
	t_table	table;
	prt_argc_msg(argc);
	init_data(&ph_data);
	store_params(argc, argv, &ph_data);
	check_data(&ph_data);
	init_table(&table, &ph_data);
	
	return (0);
}