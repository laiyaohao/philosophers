/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:10:29 by ylai              #+#    #+#             */
/*   Updated: 2024/12/07 19:17:50 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void  print(t_ph_stat *philo, char *msg)
{
  size_t  time;

  pthread_mutex_lock(philo->prt_mut);
  time = get_time() - philo->start_time;
  if (check_death(philo) != 1)
    printf("%zu %d %s\n", time, philo->number, msg);
  pthread_mutex_unlock(philo->prt_mut);
}
