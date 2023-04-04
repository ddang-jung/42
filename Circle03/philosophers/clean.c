#include "main.h"

int	clean(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		pthread_join(info->philo[i].philo_thread, NULL);
		if (pthread_mutex_destroy(&info->fork[i]))
			return (ERROR);
		if (pthread_mutex_destroy(&info->philo[i].m_philo_eat_count))
			return (ERROR);
		if (pthread_mutex_destroy(&info->philo[i].m_philo_last_eat_time))
			return (ERROR);
	}
	if (pthread_mutex_destroy(&info->m_status))
		return (ERROR);
	if (pthread_mutex_destroy(&info->m_print))
		return (ERROR);
	return (OK);
}
