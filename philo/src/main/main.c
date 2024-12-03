/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:50:34 by ylai              #+#    #+#             */
/*   Updated: 2024/11/30 18:02:34 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	main(int argc, char **argv)
{
	int	mu_err;
	int	tr_err;
	t_ph_da	ph_data;
	t_table	table;
	
	tr_err = 0;
	mu_err = 0;
	prt_argc_msg(argc);
	init_data(&ph_data);
	store_params(argc, argv, &ph_data);
	check_data(&ph_data);
	init_table(&table, &ph_data, &mu_err, &tr_err);
	// free(ph_stat);
	// start(&table, &ph_data);
	free_table(&table, &ph_data, &mu_err, &tr_err);
	// free(ph_stat);
	return (0);
}