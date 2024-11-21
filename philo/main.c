/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:50:34 by ylai              #+#    #+#             */
/*   Updated: 2024/11/16 16:55:47 by ylai             ###   ########.fr       */
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
	// free(ph_stat);
	free_table(&table, &ph_data);
	// free(ph_stat);
	return (0);
}