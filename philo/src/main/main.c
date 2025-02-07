/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:50:34 by ylai              #+#    #+#             */
/*   Updated: 2024/12/26 16:33:37 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	main(int argc, char **argv)
{
	long long		fr_err;
	long long		mu_err;
	t_table			table;

	fr_err = -1;
	mu_err = -1;
	prt_argc_msg(argc);
	init_data(&table);
	store_params(argc, argv, &table);
	check_data(&table, argc);
	fr_err = init_forks(&table);
	mu_err = init_mut(&table);
	init_table(&table);
	start(&table);
	free_table(&table, mu_err, fr_err);
	return (0);
}
