/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:34:08 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 18:20:49 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	philo_no_err(t_table *table)
{
	int	i;
	void	*res;

	i = 0;
	res = NULL;
	while ((unsigned long)i < table->philo_num)
	{
		if (pthread_join(table->philo[i].t_id, &res) != 0)
		{
			printf("pthread_join error\n");
			return ;
		}
		i++;
		free(res);
		res = NULL;
	}
}

void	philo_have_err(t_table *table, int tr_err)
{
	int	i;
	void	*res;

	i = 0;
	res = NULL;
	while (i < tr_err)
	{
		if (pthread_join(table->philo[i].t_id, &res) != 0)
		{
			printf("pthread_join error\n");
			return ;
		}
		i++;
		free(res);
		res = NULL;
	}
}

void	free_philo(t_table *table, int tr_err)
{
	void	*res;

	res = NULL;
	if (tr_err != -2)
	{
		if (pthread_join(table->checker, &res) != 0)
			printf("pthread_join error\n");
		free(res);
		res = NULL;
	}
	else if (tr_err == -1)
	{
		philo_no_err(table);
	}
	else 
	{
		philo_have_err(table, tr_err);
	}
}
