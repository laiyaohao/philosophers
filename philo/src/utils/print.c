#include "../../inc/philo.h"

void  print(t_table *table, unsigned int num, char *msg)
{
  size_t  time;

  pthread_mutex_lock(&(table->prt_mut));
  time = get_time() - table->philo[num].start_time;
  printf("%zu %d %s\n", time, num, msg);
  pthread_mutex_unlock(&(table->prt_mut));
}