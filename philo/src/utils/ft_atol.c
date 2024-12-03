#include "../../inc/philo.h"

unsigned long	ft_atol(const char *nptr)
{
	long	i;
	unsigned long	ans;

	i = 0;
	ans = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = ans * 10 + (nptr[i] - 48);
		i++;
	}
	return (ans);
}
