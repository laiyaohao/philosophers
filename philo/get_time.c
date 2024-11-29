/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:02:51 by ylai              #+#    #+#             */
/*   Updated: 2024/10/31 19:02:52 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main() {
  struct timeval current_time;
  int gt = gettimeofday(&current_time, NULL);
  printf("gt: %d\n", gt);
  printf("seconds : %ld\nmicro seconds : %ld\n",
    current_time.tv_sec, current_time.tv_usec);

  return 0;
}